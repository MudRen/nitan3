// npc.c
// update by Lonely for nt2

#include <command.h>

inherit CHARACTER;
inherit F_CLEAN_UP;

void scan();
int  chat();
int  heal_self();
int  exert_function(string func);
int  init_master();

void setup()
{
        ::setup();
        
        if (this_object()->query("master_ob") &&
            this_object()->query("master_ob") > 4)
                init_master();
}

object carry_object(string file)
{
        object ob, env, *clone;
        
        ob = new(file);

        if (! objectp(ob))
        {
        	clone = filter_array(children( file ), (: clonep :));
                if (sizeof(clone) && objectp(clone[0]) && 
                    objectp(env = environment(clone[0])) && ! clonep(env))
        	        clone[0]->move(this_object());
        }
        else
                ob->move(this_object());
        return ob;
}

object add_money(string type, int amount)
{
        object ob;

        ob = carry_object("/clone/money/" + type);
        if (! ob) return 0;
        ob->set_amount(amount);
}

int init_master()
{
        mixed exp;
        int i, lvl, level;
        int degree;
        object ob;
        mapping sks;
        string *sk;

        ob = this_object();
        if (! ob->query("master_ob"))
                return 0;
                
        exp = UPDATE_D->query_max_exp();
        level = to_int(pow(to_float(atoi(count_div(exp, 100))), 1.0 / 3)) * 10;
        
        lvl = 0;
        degree = ob->query("master_ob");
        switch(degree)
        {
        case 1  :  lvl = level / 5;     break;
        case 2  :  lvl = level * 2 / 5; break;
        case 3  :  lvl = level * 3 / 5; break;
        case 4  :  lvl = level * 4 / 5; break;
        case 5  :  lvl = level;         break;
        default :  return 0;
        }
                
        sks = ob->query_skills();
        sk = keys(sks);

        if (! sizeof(sk)) return 0;
        for(i = 0; i < sizeof(sk); i++)
        {
                if (sks[sk[i]] >= lvl)
                        continue;

                ob->set_skill(sk[i], lvl);
        }
        return 1;
}

int accept_fight(object who)
{
        string att;
        int perqi;
        int perjing;

        if (! query("can_speak"))
        {
                kill_ob(who);
                return 1;
        }

        if (this_object()->is_guarder())
                return this_object()->check_enemy(who, "fight");

        att = query("attitude");
        perqi = (int)query("qi") * 100 / query("max_qi");
        perjing = (int)query("jing") * 100 / query("max_jing");

        if (is_fighting())
        switch(att)
        {
                case "heroism":
                if (perqi >= 50)                
                {
                        command("say �ߣ����аɣ�");
                        return 1;
                } else
                {
                        command("say �ߣ���СЪƬ������ʰ�㲻�١�");
                        return 0;
                }
                        break;
                default:
                        command("say ���ж�Ϊʤ���ⲻ������̫����");
                        return 0;
        }

        if (perqi >= 75 && perjing >= 75)
        {
                switch (att)
                {
                case "friendly":
                        command("say " + RANK_D->query_self(this_object())
                                + "��ô������" + RANK_D->query_respect(who)
                                + "�Ķ��֣�");
                        return 0;
                case "aggressive":
                case "killer":
                        command("say �ߣ����аɣ�");
                        break;
                default:
                        command("say ��Ȼ" + RANK_D->query_respect(who)
                                + "�ͽ̣�" + RANK_D->query_self(this_object())
                                + "ֻ�÷��㡣");
                        break;
                }
                return 1;
        }

        command("say ������Щƣ����������սҲ���ٰ���");
        return 0;
}

int accept_hit(object who)
{
        int t;
        string att;
        int perqi;
        int perjing;

        if (! query("can_speak"))
        {
                kill_ob(who);
                return 1;
        }

        if (this_object()->is_guarder())
                return this_object()->check_enemy(who, "hit");

        att = query("attitude");
        perqi = (int)query("qi") * 100 / query("max_qi");
        perjing = (int)query("jing") * 100 / query("max_jing");

        add_temp("attempt_hit", 1);
        t = query_temp("attempt_hit");

        if (perqi >= 50 && perjing >= 50)
        {
                switch(att)
                {
                case "friendly":
                        command("say ��λ" + RANK_D->query_respect(who)
                                + "��������");
                        break;
                case "aggressive":
                        if (random(t) > 8)
                        {
                                command("say �����̵ģ���ô��ô��������" +
                                        RANK_D->query_self_rude(this_object()) +
                                        "����ɱ�䣡");
                                kill_ob(who);
                                return 1;
                        }
                        command("say �ø�" + RANK_D->query_rude(who) +
                                "�����У�");
                        break;
                case "killer":
                        if (random(t) > 2)
                        {
                                command("say �ߣ������ҵ��������ˣ�" +
                                        RANK_D->query_self_rude(this_object()) +
                                        "�������أ�");
                                kill_ob(who);
                                return 1;
                        }
                        command("say ���аɣ�");
                        break;
                default:
                        if (random(t) > 7)
                        {
                                command("say ��Ҫ��������");
                                kill_ob(who);
                                return 1;
                        }
                        command("say ��λ" + RANK_D->query_respect(who)
                                + "��������");
                        break;
                        switch (random(3))
                        {
                        case 0:
                                command("say ��������");
                                break;
                        case 1:
                                command("say �Ǿͽ���������");
                                break;
                        case 2:
                                command("say ���ɣ��һ��������㲻�ɣ�");
                                break;
                        }
                        break;
                }
        } else
        {
                switch(att) {
                case "friendly":
                        command("say ��Ȼ" + RANK_D->query_respect(who)
                                + "���������ֻ�в������ˣ�");
                        break;
                case "aggressive":
                case "killer":
                        command("say " + RANK_D->query_rude(who) +
                                "����������");
                        break;
                default:
                        command("say �㲻�ʣ��Ҳ��壡" + RANK_D->query_rude(who) +
                                "���ɲ�Ҫ���ҡ�");
                        break;
                }
                this_object()->kill_ob(who);
        }

        return 1;
}

int accept_kill(object who)
{
        if (! living(this_object()))
                return 1;

        if (! query("can_speak"))
        {
                kill_ob(who);
                return 1;
        }

        if (this_object()->is_guarder())
                return this_object()->check_enemy(who, "kill");

        switch(query("attitude"))
        {
        case "friendly":
                command("say ��Ȼ" + RANK_D->query_respect(who)
                        + "��˱��ȣ�Ī�����²����飡");
                break;
        case "aggressive":
        case "killer":
                command("say " + RANK_D->query_rude(who) +
                        "������Ľ��죬������ļ��գ���");
                break;
        default:
                command("say �ã�" + RANK_D->query_rude(who)
                        + "�����Ǿ�һ��������");
                break;
        }

        return 1;
}

int accept_ansuan(object who)
{
        if (! query("can_speak"))
        {
                kill_ob(who);
                return 1;
        }

        if (this_object()->is_guarder())
                return this_object()->check_enemy(who, "ansuan");

        command(random(2) ? "say �ţ���ô��" : "say ��ѽ�����ã�");
        return 1;
}

int accept_touxi(object who)
{
        if (! query("can_speak"))
                return 1;

        if (this_object()->is_guarder())
                return this_object()->check_enemy(who, "touxi");

        command(random(2) ? "say �ţ���ô����˭��" : "say ��ѽ���㡭");
        return 1;
}

// Ϊ�����ṩ����
mixed accept_ask(object who, string topic)
{        
        if (this_object()->is_quester())
                return QUEST_D->accept_ask(this_object(), who, topic);     

        // ����ĳ���Ϊ��ʦ�������
        if (! this_object()->is_knower())
        {
                if (who->query("ultraquest/npc5") == this_object()->query("id") ||
                    who->query("ultraquest/npc4") == this_object()->query("id") ||
                    who->query("ultraquest/npc3") == this_object()->query("id") ||
                    who->query("ultraquest/npc2") == this_object()->query("id"))
                        return ULTRA_QUEST_D->ask_information(this_object(), who, topic);                                 
        }
}

// ������Ʒ
int accept_object(object who, object ob)
{
        string id;
        
        if (this_object()->is_quester())
                return QUEST_D->accept_object(this_object(), who, ob);

        // �������Ϊ��ʦ�������
        if (who->query("ultraquest/npc5"))  
        {
                id = who->query("ultraquest/npc5");        
        } else
        if (who->query("ultraquest/npc4"))  
        {
                id = who->query("ultraquest/npc4");        
        } else
        if (who->query("ultraquest/npc3"))  
        {
                id = who->query("ultraquest/npc3"); 
        } else
        if (who->query("ultraquest/npc2"))
        { 
                id = who->query("ultraquest/npc2");    
        } else
                id = who->query("ultraquest/npc1");
        
        if (! id) return 0;
        
        if (! this_object()->is_knower() &&
            (id == this_object()->query("id") ||
            who->query("ultraquest/quest/id") == this_object()->query("id")))
                return ULTRA_QUEST_D->accept_object(this_object(), who, ob);
}

// �ظ����������Ӧ��
int need_accede(object who)
{
        string id;

        if (who->query("ultraquest/npc5"))  
        {
                id = who->query("ultraquest/npc5");        
        } else
        if (who->query("ultraquest/npc4"))  
        {
                id = who->query("ultraquest/npc4");        
        } else
        if (who->query("ultraquest/npc3"))  
        {
                id = who->query("ultraquest/npc3"); 
        } else
        if (who->query("ultraquest/npc2"))
        { 
                id = who->query("ultraquest/npc2");    
        } 
        
        if (! id) return 0;
        
        if (! this_object()->is_knower() &&
            (id == this_object()->query("id") ||
            who->query("ultraquest/quest/id") == this_object()->query("id")))
                return ULTRA_QUEST_D->need_accede(this_object(), who);
}

// This function is called by the reset() of the room that creates this
// npc. When this function is called, it means the room demand the npc
// to return its startroom.
int return_home(object home)
{
        // Are we at home already?
        if (! environment() || environment() == home)
                return 1;

        // Are we able to leave?
        if (! living(this_object()) || is_fighting()
           || ! mapp(environment()->query("exits")))
                return 0;

        // Leave for home now.
        message("vision", this_object()->name() + "����ææ���뿪�ˡ�\n",
                environment(), this_object());

        return move(home);
}

// In this function, the npc will scan itself wether there is
// someting to do.
void scan()
{
        object me;

        me = this_object();

        if (! environment() || ! living(me)) return;

        if (me->is_coagent() && me->is_helping() && ! me->is_fighting())
        {
                // finish helping
                me->finish_help();
        }

        if (heal_self()) return;

        chat();
}

// Here, the NPC will process the heal/recover.
int heal_self()
{
        mapping my;
        int cost;

        if (is_busy() || is_fighting())
                // ��æ��
                return 0;

        if (query("not_living"))
                // ������
                return 0;

        if (! query_skill_mapped("force"))
                // û�м����ڹ�
                return 0;

        if (query_temp("no_exert"))
                // ���������ֹʹ���ڹ�
                return 0;

        my = query_entire_dbase();
        if (my["neili"] < 50)
                return 0;

        if (my["jing"] < my["eff_jing"] * 8 / 10)
        {
                // ����̫��
                exert_function("regenerate");
                return 1;
        }

        if (my["qi"] < my["eff_qi"] * 8 / 10 &&
            query_skill("force") >= 150)
        {
                // ��Ѫ�������沢���ڹ��ȼ���
                exert_function("recover");
                return 1;
        }

        if (my["eff_qi"] < my["max_qi"])
        {
                // ������
                exert_function("heal");
                return 1;
        }

        if (my["eff_jing"] < my["max_jing"])
        {
                // ���ܵ�����ʧ
                exert_function("inspire");
                return 1;
        }

        if (my["neili"] < my["max_neili"] - 10)
        {
                // �����������棬�����ָ�
                cost = my["max_neili"] - my["neili"];
                if (cost > my["qi"] / 2) cost = my["qi"] / 2;
                command(sprintf("dazuo %d", cost));
                return 1;
        }

        return 0;
}

// This is the chat function dispatcher. If you use function type chat
// message, you can either define your own functions or use the default
// ones.
int chat()
{
        string *msg;
        int chance, rnd;

        if (is_busy())
                return 0;

        if (! chance = (int)query(is_fighting() ? "chat_chance_combat" : "chat_chance"))
                return 0;

        if (arrayp(msg = query(is_fighting() ? "chat_msg_combat" : "chat_msg")))
        {
                if (random(120) < chance)
                {
                        rnd = random(sizeof(msg));
                        if (stringp(msg[rnd]))
                                say(msg[rnd]);
                        else if (functionp(msg[rnd]))
                                return evaluate(msg[rnd]);
                }
                return 1;
        }
}

// Default chat function: Let the npc random move to another room.
int random_move()
{
        mapping exits;
        string *dirs;

        if (! mapp(exits = environment()->query("exits")) ||
	    ! sizeof(exits))
                return 0;
        dirs = keys(exits);
        command("go " + dirs[random(sizeof(dirs))]);
}

// Default chat function: Let the npc cast his/her enabled spells
void cast_spell(string spell)
{
        string spell_skill;

        if (stringp(spell_skill = query_skill_mapped("spells")))
                SKILL_D(spell_skill)->cast_spell(this_object(), spell);
}

// Default chat function: Let the npc exert his/her enabled force
int exert_function(string func)
{
        string force_skill;

        if (! stringp(force_skill = query_skill_mapped("force")))
                return 0;

        // ���������ֹʹ���ڹ�
        if (this_object()->query_condition("no_exert"))
                return 0;

        if (SKILL_D(force_skill)->exert_function(this_object(), func))
                return 1;

        return SKILL_D("force")->exert_function(this_object(), func);
}

// Default chat function: Let the npc perform special action with 
// his/her enabled martial art
int perform_action(string action)
{
        //object weapon;
        string martial_skill, act;

        if (sscanf(action, "%s.%s", martial_skill, act) != 2)
                return 0;

        // ���������ֹʹ���⹦
        if (this_object()->query_condition("no_perform"))
                return 0;

        martial_skill = query_skill_mapped(martial_skill);
        if (stringp(martial_skill))
                return SKILL_D(martial_skill)->perform_action(this_object(), act);              
}

// Check the player wether is belong a family
int check_family(object ob, string fam)
{
        if (ob->query("family/family_name") == fam)
                return 1;

        if (! ob->query("family/family_name") &&
            ob->query("born_name") == fam)
                return 1;

        return 0;
}

// when remove
void remove()
{
        function *fun;

        if (functionp(fun = query_temp("override/destruct", 1)))
                catch(evaluate(fun, this_object()));

        ::remove();
}

// environment destruct
void move_or_destruct()
{
        remove();
}
/*
void relay_emote(object me, string verb)
{
        string player_id, att, relay_msg;
        string *emote, cmd_emote;
        object ob = this_object();
        int    i;
        
        if (! userp(me)) 
                return;
        
        if (! ob->query("can_speak")) 
                return;

        player_id = me->query("id");

        att = query( "attitude" );

        // ������npc��������emote���mapping
        // ��һЩemote������ķ�Ӧ��
        // �����Ӧ�����Ǹ�string��Ҳ�����Ǹ�function

        if (relay_msg = query("emote/" + verb ))
        {
                if (stringp(relay_msg))
                        message_vision(relay_msg + "\n", ob, me);
                else 
                if (functionp(relay_msg))
                        return evaluate(relay_msg);
                        
                return;
        }

        if (random(2) != 1) 
                return ;
        
        emote = sort_array(EMOTE_D->query_all_emote(), 1);
        i = 0;
        i = sizeof(emote);
        
        if (i == 0) 
                return ;
        
        cmd_emote = emote[random(i)];
        command(cmd_emote + " " + player_id);
}
*/
void recover()
{
        mapping p;

        clear_condition(0);
        p = query_entire_dbase();
        p["eff_qi"] = p["max_qi"];
        p["qi" ] = p["max_qi"];
        p["eff_jing"] = p["max_jing"];
        p["jing" ] = p["max_jing"];
}
