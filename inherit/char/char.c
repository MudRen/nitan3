// char.c

#pragma optimize
#pragma save_binary

#include <action.h>
#include <ansi.h>
#include <command.h>
#include <condition.h>
#include <dbase.h>
#include <move.h>
#include <name.h>
#include <skill.h>
#include <team.h>
#include <user.h>

inherit F_ACTION;
inherit F_ALIAS;
inherit F_APPRENTICE;
inherit F_ATTACK;
inherit F_ATTRIBUTE;
inherit F_COMMAND;
inherit F_CONDITION;
inherit F_DAMAGE;
inherit F_DBASE;
inherit F_EDIT;
inherit F_FINANCE;
inherit F_MESSAGE;
inherit F_MORE;
inherit F_MOVE;
inherit F_NAME;
inherit F_SKILL;
inherit F_SHELL; 
inherit F_TEAM;

#define SCHEME_CMD      "/cmds/usr/scheme"

#define ID      0
#define NAME    1

string *id_name;

// Use a tick with longer period than heart beat to save cpu's work
nosave int next_beat;
nosave int keep_beat_flag = 0;
nosave string short_desc = 0;

void create()
{
        seteuid(0); // so LOGIN_D can export uid to us
}

// Use this function to identify if an object is a character.
int is_character() { return 1; }

// check the character is good or bad
int is_not_good() { return query("shen") < 500; }
int is_not_bad()  { return query("shen") > -500; }
int is_good()     { return query("shen") > 500; }
int is_bad()      { return query("shen") < -500; }

// setup: used to configure attributes that aren't known by this_object()
// at create() time such as living_name (and so can't be done in create()).
void setup()
{
        seteuid(getuid(this_object()));

        set_heart_beat(1);
        next_beat = time() + 5 + random(10);

        enable_player();
        CHAR_D->setup_char(this_object());
}

void keep_heart_beat()
{
        set_heart_beat(1);
        keep_beat_flag = 1;
}

void not_keep_heat_beat()
{
        keep_beat_flag = 0;
}

void heart_beat()
{
        int t;
        int period;
        int wimpy_ratio, cnd_flag;
        mapping my;
        object ob;
	object me;
	string prompt;
	int is_player;

	me = this_object();
        my = query_entire_dbase();

        if (userp(me) && living(me) && mapp(my["env"]))
        {
                // update prompt
		prompt = my["env"]["prompt"];
                if ((prompt == "time" || prompt == "mud" || prompt == "hp") &&
		    is_waiting_command() && ! me->is_attach_system())
                    
                {
                        write_prompt();
                }
                
        }

        // If we're dying or falling unconcious?
        if (my["qi"] < 0 || my["jing"] < 0)
        {
                if (! living(me)) die();
                else unconcious();

                // Why does the living test? Because
                // The wizard may set immortal but his
                // qi was -1, so I don't want return,
                // or the continue_action will never be
                // called in such case.
                if (! me || ! living(me))
                        return;
        }

        if (is_p_busy())
        {
                continue_p_busy();
        }
        
        // Do attack if we are fighting.
        if (is_busy())
        {
                continue_action();
                // We don't want heart beat be halt eventually, so return here.
        } else
	if (living(me))
        {
                string apply;
                object apply_ob;

                // Is it time to flee?
                if (is_fighting() &&
                   intp(wimpy_ratio = (int)query("env/wimpy")) &&
                   wimpy_ratio > 0 &&
                   (my["qi"] * 100 / my["max_qi"] <= wimpy_ratio ||
                    my["jing"] * 100 / my["max_jing"] <= wimpy_ratio))
                {
                        if (stringp(apply = query("env/wimpy_apply")) &&
                            objectp(apply_ob = present(apply, me)) &&
                            apply_ob->query("can_apply_for_wimpy"))
                        {
                                apply_ob->apply_for_wimpy(this_object());
                        } else
                                GO_CMD->do_flee(this_object());
                }
                
                if (query("auto_perform") || me->query_auto_perform())
                {                       
                        if (my["eff_jing"] > 0 && my["jing"] * 100 / my["eff_jing"] <= 70)
                                SKILL_D("force/regenerate")->exert(me, me);
                        if (my["eff_qi"] > 0 && my["qi"] * 100 / my["eff_qi"] <= 70)
                                SKILL_D("force/recover")->exert(me, me);

                        // 如果不在打架而且处于受伤状态，则自行疗伤
                        if (! is_fighting())
                        {
                                if (my["eff_jing"] < my["max_jing"])
                                        SKILL_D("force/inspire")->exert(me, me);
                                if (my["eff_qi"] < my["max_qi"])
                                        SKILL_D("force/heal")->exert(me, me);
                        }
                }
                // Do attack or clean up enemy if we have fleed.
                if (is_busy())
                        continue_action();
                else
                        attack();
        }

        if (my["doing"] == "scheme")
                // executing schedule now
                SCHEME_CMD->execute_schedule(me);

        if (! me) return;

        if (! (is_player = playerp(me)))
        {
                me->scan();
                // scan() may do anything -- include destruct(this_object())
                if (! me) return;
        }

        if ((t = time()) < next_beat) return;
        else next_beat = t + 5 + random(10);

	if (! my["not_living"])
        	cnd_flag = update_condition();
	if (! me) return;

	if (! (cnd_flag & CND_NO_HEAL_UP))
		cnd_flag = heal_up();

        // If we are compeletely in peace, turn off heart beat.
        // heal_up() must be called prior to other two to make sure it is called
        // because the && operator is lazy :P
        if (! cnd_flag &&
	    ! is_player &&
            ! keep_beat_flag &&
            ! is_fighting() &&
	    ! is_busy() &&
            ! interactive(this_object()))
        {
                if (environment() && query("chat_msg"))
                {
                        ob = first_inventory(environment());
                        while (ob && ! interactive(ob))
                                ob = next_inventory(ob);
                } else
                        ob = 0;
                if (! ob) set_heart_beat(0);
        }

        update_all_limb_damage();
        
        if (! me || ! is_player) return;

        // Make us a bit older. Only player's update_age is defined.
        // Note: update_age() is no need to be called every heart_beat, it
        //       remember how much time has passed since last call.
        me->update_age();

#ifdef AUTO_SAVE
        if (living(me))
        {
            	period = t - ((int) my["last_save"]);
                if (period < 0 || period > 15 * 60)
            	{
                	string msg;
                        msg = HBCYN HIW "【档案存储】您的档案已经自动存盘，"
                              "欢迎访问论坛 http://bbs.mudbuilder.com/ 。\n" NOR;
                	if (! me->save())
                    	msg = HIR "【数据保护】由于数据异常，您的档"
                              "案本次存盘失败。\n" NOR;
                	set("last_save", t);
                	tell_object(me, msg);
            }
        }
#endif
	if (! interactive(me))
		return;

        if (my["food"] <= 0 || my["water"] <= 0)
        {
		if (environment() &&
		    ! environment()->is_chat_room() &&
                    ! wizardp(me) &&
                    ! query_condition("hunger"))
		{
			// born & enter the world
                        apply_condition("hunger", 1);
		}
        }

        if (query_idle(me) > IDLE_TIMEOUT && ! wizardp(me) &&
            (! mapp(my["env"]) || ! my["env"]["keep_idle"]))
                me->user_dump(DUMP_IDLE);
}

// check the poison attack
mixed hit_ob(object me, object victim, int damage_bonus)
{
        object unarmed_weapon;

        if (unarmed_weapon = query_temp("armor/hands"))
                return unarmed_weapon->hit_ob(me, victim, damage_bonus);

        if (! mapp(query_temp("daub")))
                return;

        return COMBAT_D->hit_with_poison(me, victim, this_object());
}

int visible(object ob)
{
        int lvl;

        if (! ob->is_character())
                return 1;

        if (! wizardp(ob))
        {
                if (wizardp(this_object()) || 
                    query("env/invisible") || 
                    is_ghost())
                        return 1;

                if (ob->query("env/invisible") || 
                    ob->is_ghost())
                        return 0;
        }

        lvl = wiz_level(this_object());
        if (lvl && 
            lvl >= wiz_level(ob)) 
                return 1;
        if (ob->query("env/invisible") == "YES") 
                return 0;
        if (lvl && 
            lvl >= (int)ob->query("env/invisible")) 
                return 1;

        if (wizardp(ob) && 
            ob->query("env/invisible")) 
                return 0;

        return 1;
}
// by Lonely
varargs string query_idname(int raw)
{
        if (! arrayp(id_name) || sizeof(id_name) < 1)
                return query("name") + "(" + (raw ? capitalize(query("id")) : query("id")) + ")";
                
        return (id_name[NAME] ? id_name[NAME] : query("name")) + "(" + 
               (raw ? color_capitalize(id_name[ID] ? id_name[ID] : query("id")) : 
               (id_name[ID] ? id_name[ID] : query("id"))) + ")"; 
}

mixed query_IDNAME()
{
        if (! arrayp(id_name) || sizeof(id_name) < 1)
                return 0;
        
        return id_name;
}

void set_IDNAME(mixed m)
{
        if (! arrayp(m) || sizeof(m) < 1)
                return;

        id_name = m;
}

void remove_idname()
{
        id_name = ({});
}

varargs string *set_idname(string id, string name)
{
        string text;

        if (! stringp(id) && ! stringp(name)) return 0;

        if (! arrayp(id_name) || sizeof(id_name) < 1)
                id_name = allocate(2);
        
        if (stringp(id))
        {
                text = lower_case(filter_color(trans_color(id, 1))); 
                id = lower_case(trans_color(id, 1));
                
                if (! id(text)) return 0;
 
                id_name[ID] = id;
        }
        
        if (stringp(name))
        {
                name = trans_color(name, 1);
                
                if (filter_color(name) != query("name")) return 0;
                
                id_name[NAME] = name;
        }

        return copy(id_name);
}
        
string set_short_desc(string desc)
{
        short_desc = desc;
}

varargs string short(int raw)
{
        //string title, nick, str, str1, *mask;
        string title, nick, str, *mask;
        string bname;
        object me;

        me = this_object();

        if (! raw && sizeof(mask = query_temp("apply/short")))
                str = (string)mask[sizeof(mask) - 1];
	else
        {
                str = query_idname();
                if (! stringp(title = query_temp("title")))
                        title = query("title");
		if (nick = query("nickname"))
                {
			str = "「" + nick + "」" + str;
        		if (title) str = title + str;
                } else
		if (title) str = title + " " + str;
		
                if (stringp(bname = query("bunch/bunch_name")))
                        str = sprintf("%s%s%s" NOR " %s", 
                                BUNCH_D->query(bname + "/color") ? BUNCH_D->query(bname + "/color") : NOR,
                                bname, (string)query("bunch/title") ? query("bunch/title") : "帮众", str);		
	}

	if (! raw)
        {
                if (short_desc)
		        str = name() + short_desc;
        } else
                return str;

	if (me->is_ghost())
                str = HIB "(鬼气) " NOR + str;

	if (me->is_net_dead())
        {
		switch (me->query("doing"))
                {
                case "breakup":
                case "animaout":
			str += HIY " <闭关中>" NOR;
                        break;

                case "closed":
                case "xiulian":
                        str += HIY " <修炼中>" NOR;
                        break;

                case "scheme":
                        str += HIW " <计划中>" NOR;
                        break;

                default:
                	str += HIG " <断线中>" NOR;
                }
        }

        if (query_temp("on_bantan"))
                 str += HIG " <摆摊中> " NOR;

 	if (in_input())
                str += HIC " <输入文字中>" NOR;

     	if (! living(me) && query("disable_type"))
                str += HIR + query("disable_type") + NOR;

 	if (in_edit())
                str += HIY " <编辑档案中>" NOR;

	if (interactive(this_object()) &&
	    query_idle(this_object()) > 120 )
                str += HIM " <发呆中>" NOR;

	return str;
}

int command(string arg)
{
        return efun::command(arg);
}

int command_function(string arg)
{
        return efun::command(arg);
}
