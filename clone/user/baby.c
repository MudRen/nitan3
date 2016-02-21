// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
inherit BABY;
inherit F_NOCLONE;  

void consider();
void provide(); 
mixed ask_father();
mixed ask_mother(); 
int check_legal_name(string name, int max_len);
 
int  is_baby(){ return 1; }


void create()
{
        set_name("����", ({"xiao baobao", "baby"}) );
        set("long", "һ���װ����ֵĹԱ�������֪����˭�ҵĺ��ӡ�\n");        
        set("gender", "Ů��");
        set("age", 1);
        set("attitude", "friendly");
        set("no_clean_up", 1); 
        set("env/halt_age", 1); 
        set("combat_exp", 10000);

        setup();
        carry_object("/clone/cloth/cloth")->wear();
        
        remove_call_out("check_me");
        call_out("check_me", 2, this_object());
}

void check_me(object me)
{
        if (me && ! mapp(me->query("parents")))
                destruct(me);
        return;
}

int load_baby(object me)
{   
        string file, info, name, id;   

        if (! userp(me)) return 0;

        if (me->query("gender") == "Ů��")
                file = "/data/baby/" + me->query("id") + ".o";
        else 
        if (me->query("couple/couple_id"))
                file = "/data/baby/" + me->query("couple/couple_id") + ".o";

        if (! file || file_size(file) < 0) return 0; 

        if (stringp(read_file(file)))
        {
                restore_object(file);
                reset_action();

                    /*
                set("max_neili", query_skill("force") * 20 + query("combat_exp") / 1000);
                set("neili", query("max_neili"));
                set("max_jingli", query_skill("magic") * 10 + query_skill("taoism") * 10 + query("combat_exp") / 3000); 
                set("jingli", query("max_jingli"));
                    */
                set("max_qi", 150 + query("max_neili") / 2 + query("age") * query("con"));
                set("eff_qi", query("max_qi"));
                set("qi", query("max_qi"));
                set("max_jing", 100 + query("max_jingli") / 3 + query("age") * query("con"));
                set("eff_jing", query("max_jing"));
                set("jing", query("max_jing"));
                set_name(query("name"), ({query("id"), "baby"})); 

                set("chat_chance", query("int") / 10);
                set("chat_chance_combat", query("con") / 5 * 10); 

                set("chat_msg", ({
                        (: consider :),
                        (: provide :), 
                }));
                
                set("inquiry", ([ 
                        "����" : (: ask_father :), 
                        "����" : (: ask_father :), 
                        "�ְ�" : (: ask_father :), 
                        "ĸ��" : (: ask_mother :), 
                        "����" : (: ask_mother :), 
                ]));
                
                set("perform_skills", 0); 

                setup();

                UPDATE_D->check_user(this_object());
                remove_call_out("consider");
                call_out("consider", 10);
        } else 
                return 0;
} 

void init()
{
        add_action("do_kill", ({"kill", "fight", "hit", "steal"}));
        add_action("do_get", "get");
        add_action("do_drop", "drop");
        add_action("do_home", "home_baby");   
        add_action("do_nick", "nick_baby"); 
        add_action("do_changename", "name_baby");   
}

int do_nick(string arg)
{
        object ob = this_object();       
        object me = this_player();        
        
        if (query("parents/father") != me->query("id") &&
            query("parents/mother") != me->query("id"))
                return notify_fail("������ˣ����ɲ�����ĺ��ӣ�\n");
                
        if (! arg)
                return notify_fail("��Ҫ�溢��ȡʲô�ºţ�\n");

        if (arg == "none")
        {
                ob->delete("nickname");
                write("��ĺ��Ӵº�ȡ���ˡ�\n");
                ob->save();
                return 1;
        }

        if (strlen(arg) > 80)
                return notify_fail("��Ϊ����ȡ�Ĵº�ռ�õ���Դ���࣬���������á�\n");

        arg = replace_string(arg, "$BLK$", BLK);
        arg = replace_string(arg, "$RED$", RED);
        arg = replace_string(arg, "$GRN$", GRN);
        arg = replace_string(arg, "$YEL$", YEL);
        arg = replace_string(arg, "$BLU$", BLU);
        arg = replace_string(arg, "$MAG$", MAG);
        arg = replace_string(arg, "$CYN$", CYN);
        arg = replace_string(arg, "$WHT$", WHT);
        arg = replace_string(arg, "$HIR$", HIR);
        arg = replace_string(arg, "$HIG$", HIG);
        arg = replace_string(arg, "$HIY$", HIY);
        arg = replace_string(arg, "$HIB$", HIB);
        arg = replace_string(arg, "$HIM$", HIM);
        arg = replace_string(arg, "$HIC$", HIC);
        arg = replace_string(arg, "$HIW$", HIW);
        arg = replace_string(arg, "$NOR$", NOR);

        if (strlen(filter_color(arg)) > 30)
                return notify_fail("��Ϊ����ȡ�Ĵº�̫���ˣ���һ����һ��ġ�����һ��ġ�\n");

        ob->set("nickname", arg + NOR);
        ob->save();
        write("��Ϊ����ȡ���˴ºš�\n");
        return 1;
}

int do_changename(string arg)
{
        object ob = this_object();  
        object me = this_player();   
        string  arg_old;                  
        
        if (query("parents/father") != me->query("id") &&
            query("parents/mother") != me->query("id"))
                return notify_fail("������ˣ����ɲ�����ĺ��ӣ�\n");
                
        if (! arg)
                return notify_fail("��Ҫ�溢��ȡʲô���֣�\n");  
                 
        arg_old = arg; 

        arg = replace_string(arg, "$BLK$", "");
        arg = replace_string(arg, "$RED$", "");
        arg = replace_string(arg, "$GRN$", "");
        arg = replace_string(arg, "$YEL$", "");
        arg = replace_string(arg, "$BLU$", "");
        arg = replace_string(arg, "$MAG$", "");
        arg = replace_string(arg, "$CYN$", "");
        arg = replace_string(arg, "$WHT$", "");
        arg = replace_string(arg, "$HIR$", "");
        arg = replace_string(arg, "$HIG$", "");
        arg = replace_string(arg, "$HIY$", "");
        arg = replace_string(arg, "$HIB$", "");
        arg = replace_string(arg, "$HIM$", "");
        arg = replace_string(arg, "$HIC$", "");
        arg = replace_string(arg, "$HIW$", "");
        arg = replace_string(arg, "$NOR$", "");
                                
        if (! check_legal_name(arg, 8))  
                return notify_fail("�������趨��ĺ������֣�\n");
        
        arg = arg_old;

        arg = replace_string(arg, "$BLK$", BLK);
        arg = replace_string(arg, "$RED$", RED);
        arg = replace_string(arg, "$GRN$", GRN);
        arg = replace_string(arg, "$YEL$", YEL);
        arg = replace_string(arg, "$BLU$", BLU);
        arg = replace_string(arg, "$MAG$", MAG);
        arg = replace_string(arg, "$CYN$", CYN);
        arg = replace_string(arg, "$WHT$", WHT);
        arg = replace_string(arg, "$HIR$", HIR);
        arg = replace_string(arg, "$HIG$", HIG);
        arg = replace_string(arg, "$HIY$", HIY);
        arg = replace_string(arg, "$HIB$", HIB);
        arg = replace_string(arg, "$HIM$", HIM);
        arg = replace_string(arg, "$HIC$", HIC);
        arg = replace_string(arg, "$HIW$", HIW);
        arg = replace_string(arg, "$NOR$", NOR);
                
        ob->set("name", arg + NOR);
        ob->save();
        write("��Ϊ����ȡ����������\n");
        return 1;
}

int check_legal_name(string name, int max_len)
{
        int i;
        string  *legalname;             //not implemented..may add later
        
        i = strlen(name);
        if ((strlen(name) < 4) || (strlen(name) > max_len )) 
        {
                write(sprintf("�Բ������������� 2 �� %d �������֡�\n",
                      max_len / 2));
                return 0;
        }
        
        if (max_len < 13 && strsrch(NAME_D->who_is(name), "��") >= 0)
        {
                write("�Բ��𣬺��ӵ����ֲ��ܺ���ҵ������ظ���\n"); 
                return 0;
        }

        if (max_len < 13 && ! is_chinese(name))
        {
                write("�Բ��������á����ġ�Ϊ����ȡ���ֻ�������\n");
                return 0;
        }
        return 1; 
}

int do_home(string arg)
{
        object me = this_object(), who = this_player();

        if (! arg) return 0;
        if (! this_object()->id(arg)) return 0;

        if (who->query("id") == query("parents/father")
        ||  who->query("id") == query("parents/mother"))
        {                           
                message_vision("$N����$n����˵������������Щ���飬���Ȼؼ�ȥ�ɡ�\n", who, me);
                me->save();
                destruct(me);
                return 1;
        } else
                command("say ����˭����ΪʲôҪ����Ļ���\n");
        return 1;
}

int do_drop(string arg)
{
        object me = this_object(), who = this_player();
        
        if (! arg || ! this_object()->id(arg)) return 0;
        
        if (! present(me->query("id"), who))
                return notify_fail("������û��������ӡ�\n"); 

        if (me->move(environment(who)))
        {
                message_vision("$N��$n�ӻ������������\n", who, me);
                return 1;
        }
        return 0;
}

int do_get(string arg)
{
        object  me = this_object(), who = this_player();
        object  ob1, ob2;
        string  fid, mid;
        mapping bro;
        string *ids;

        if (! arg) return 0;
        if (! this_object()->id(arg)) return 0;   

        if (environment(me) != environment(who))
                return notify_fail("����û��������ӡ�\n"); 

        fid = me->query("parents/father");
        mid = me->query("parents/mother");
        
        ob1 = UPDATE_D->global_find_player(fid);
        ob2 = UPDATE_D->global_find_player(mid);

        if (who->query("id") == fid
        ||  who->query("id") == mid)
        {
                if (query("age") < 15 && me->move(who))
                {
                        message_vision("$N��������$n����������§�ڻ��\n", who, me);
                }
                else
                {
                        message_vision("$N������һ��ȴû��$n��������С�һ�ó��ģ�\n", who, me);
                }
        } else        
        if (mapp(bro = ob1->query("brothers")) && sizeof(bro) > 0) 
        {
                ids = keys(bro);
                if (member_array(who->query("id"), ids) != -1)
                {
                        if (query("age") < 15 && me->move(who))
                        {
                                message_vision("$N��������$n����������§�ڻ��\n", who, me);
                        }
                        else
                        {
                                message_vision("$N������һ��ȴû��$n��������С�һ�ó��ģ�\n", who, me);
                        }  
                }                      
        } else        
        if (mapp(bro = ob2->query("brothers")) && sizeof(bro) > 0) 
        {
                ids = keys(bro);
                
                if (member_array(who->query("id"), ids) != -1)
                {
                        if (query("age") < 15 && me->move(who))
                        {
                                message_vision("$N��������$n����������§�ڻ��\n", who, me);
                        }
                        else
                        {
                                message_vision("$N������һ��ȴû��$n��������С�һ�ó��ģ�\n", who, me);
                        } 
                } 
        }  
        else
        {
                message_vision("$N������$n�쿪˫�֣�$nȴһ���������ˣ�����\n",who,me);
        }
                     
        UPDATE_D->global_destruct_player(ob1, 1); 
        UPDATE_D->global_destruct_player(ob2, 1); 
                
        return 1;
}

int do_kill(string arg)
{       
        object me, who;
        string name, verb, what, obj;
        
        if (! arg) return 0;
        
        verb = query_verb();
        me = this_player();
   
        if (verb == "steal")
        {
                if (sscanf(arg, "%s from %s", what, obj) != 2) 
                        return 0;
        }
        else obj = arg;

        if (! objectp(who = present(obj, environment(me))) 
        ||  ! living(who)) 
                return 0;
                
        if (who == this_object())
        {
                switch(verb)
                {
                case "kill":
                        // command("chat* " +
                        tell_object(environment(this_object()),
                                    who->query("name") + "ƴ���ؿ����������������������" +
                                    me->query("name") + "Ҫɱ�ң����������ѽ��\n");
                        break;
                case "hit":
                        //  command("chat* " +
                        tell_object(environment(this_object()),
                                    who->query("name") + "������������������������" +
                                    me->query("name") + "�۸��ң����������ѽ��\n");
                        break;
                case "fight":
                        // command("chat* " +
                        tell_object(environment(this_object()),
                                    who->query("name") + "�����������������������" +
                                    me->query("name") + "Ҫ���ҵ��ǳԣ����������ѽ��\n");
                        break;
                case "steal":
                        // command("chat* " +
                        tell_object(environment(this_object()),
                                    who->query("name") + "�����������������������" +
                                    me->query("name") + "Ҫ͵���ҵ��ǣ�\n");
                        break;
                case "beg":
                        // command("chat* " +
                        tell_object(environment(this_object()),
                                    who->query("name") + "С��һ������������������������" +
                                    me->query("name") + "Ҫƭ�ҵ��ǳԣ�\n");
                        break;
                }
        }
        command(verb);
        return 0;
}

void relay_emote(object ob, string verb)
{
        if (! userp(ob)) return;

        switch(verb)
        {
        case "kick":
                command("say �������������"  + ob->query("name") + "����Ү��");
                command("kick " + ob->query("id"));
                 break;
        case "slap":
                command("say �������������"  + ob->query("name") + "����Ү����ʹ����������");
                command("slap " + ob->query("id"));
                break;
        case "hit":
                command("pain " + ob->query("id"));
                break;
        case "bite":
                command("face " + ob->query("id"));
                break;  
        case "papaya":
                command("angry");
                break;  
        }
}

void relay_whisper(object me, string msg)
{
        if (me->query("id") != query("parents/father")
        &&  me->query("id") != query("parents/mother"))
        {
                message_vision((string)this_object()->query("name") + "�ɻ�ؿ���$N��\n", me);
                return;
        }

        /*
        // note, do not allow the order contain "chat", "tell"...
        // may need disable more later...
        if (strsrch(msg, "chat") != -1 ||
            strsrch(msg, "tell") != -1 ||
            strsrch(msg, "sos")  != -1 ||
            strsrch(msg, "recruit") != -1)
                return;
        */

        if (msg)
        {
                remove_call_out ("relaying");
                call_out ("relaying", random(2), msg);
        }
}

void relaying (string msg)
{
        // execute the order.
        if (command(msg)) 
                return;
        else 
                command("say ������ѽ������\n");
        return;        

}

mixed ask_father()
{
        object me, ob;
        string id, name;
        
        me = this_object();
        
        id = me->query("parents/father");
        ob = UPDATE_D->global_find_player(id); 
        
        if (! objectp(ob))
                return notify_fail(me->name() + "¶��ʹ��ı���������Ҹ��Ѿ�ȥ���ˣ����ʼҸ��кι�ɣ�����\n");
                
        name = ob->query("name");
        command("say �ҵĸ����Ǹ��������صĴ�Ӣ�ۣ�" + name + "(" + id + ")����������ţ�����˵������");
        UPDATE_D->global_destruct_player(ob, 1); 
        return 1;
}
        
mixed ask_mother()
{
        object me, ob;
        string id, name;
        
        me = this_object();
        
        id = me->query("parents/mother");
        ob = UPDATE_D->global_find_player(id); 
        
        if (! objectp(ob))
                return notify_fail(me->name() + "¶��ʹ��ı����������ĸ�Ѿ�ȥ���ˣ����ʼ�ĸ�кι�ɣ�����\n");
                
        name = ob->query("name");
        command("say �ҵ�ĸ�������ֵ�һ��Ů��" + name + "(" + id + ")����������ţ�����˵������");
        UPDATE_D->global_destruct_player(ob, 1); 
        return 1;
}

int accept_ask(object who, string topic) 
{
        object  ob, ob1, ob2, me = this_object();
        string  fid, mid, name, fname, mname;
        mapping bro;
        string *ids;
        string  id; 
        
        fid = me->query("parents/father");
        mid = me->query("parents/mother");
        
        ob1 = UPDATE_D->global_find_player(fid);
        fname = ob1->query("name");
        
        if (mapp(bro = ob1->query("brothers")) && sizeof(bro) > 0) 
        {
                ids = keys(bro);
                
                foreach (id in ids)
                {
                        ob = UPDATE_D->global_find_player(id);
                        name = ob->query("name");
                        if (topic == id || topic == name)
                        {
                                if (ob->query("gender") == "����")
                                {
                                        if (ob->query("mud_age") > ob1->query("mud_age"))
                                                command("say ���ǼҸ��Ľ����ֳ���Ҳ�����ҵĲ�����");
                                        else
                                                command("say ���ǼҸ�����ܣ�Ҳ�����ҵ����塣");

                                } else
                                {
                                        if (ob->query("mud_age") > ob1->query("mud_age"))
                                                command("say ���ǼҸ�����㣬Ҳ�����ҵĴ�á�");
                                        else
                                                command("say ���ǼҸ��Ľ������ӣ�Ҳ�����ҵ�С�á�");                                            
                                }
                                UPDATE_D->global_destruct_player(ob, 1);
                                UPDATE_D->global_destruct_player(ob1, 1); 
                                return 1;                                   
                        }
                        UPDATE_D->global_destruct_player(ob, 1);
                }
        }                                                
                       
        UPDATE_D->global_destruct_player(ob1, 1); 
         
        ob2 = UPDATE_D->global_find_player(mid);
        mname = ob2->query("name");
        
        if (mapp(bro = ob2->query("brothers")) && sizeof(bro) > 0) 
        {
                ids = keys(bro);
                
                foreach (id in ids)
                {
                        ob = UPDATE_D->global_find_player(id);
                        name = ob->query("name");
                        if (topic == id || topic == name)
                        {
                                if (ob->query("gender") == "����")
                                {
                                        if (ob->query("mud_age") > ob1->query("mud_age"))
                                                command("say ���Ǽ�ĸ�Ľ����ֳ���Ҳ�����ҵĴ�ˡ�");
                                        else
                                                command("say ���Ǽ�ĸ����ܣ�Ҳ�����ҵ�С�ˡ�");

                                } else
                                {
                                        if (ob->query("mud_age") > ob1->query("mud_age"))
                                                command("say ���Ǽ�ĸ����㣬Ҳ�����ҵĴ��̡�");
                                        else
                                                command("say ���Ǽ�ĸ�Ľ������ӣ�Ҳ�����ҵ�С�̡�");                                            
                                }
                                UPDATE_D->global_destruct_player(ob, 1);
                                UPDATE_D->global_destruct_player(ob2, 1); 
                                return 1;                                   
                        }                        
                        UPDATE_D->global_destruct_player(ob, 1);
                }
        }  
                     
        UPDATE_D->global_destruct_player(ob2, 1); 
        
        if (topic == fid || topic == fname)
        {
                if (who->query("id") == me->query("parents/father") ||
                    who->query("id") == me->query("parents/mother"))
                        command("say ���Ǹ��״��˵����䰡��������������");
                else
                        command("say ���ǼҸ������䣬����ʶ�Ҹ���");
                return 1;
        }

        if (topic == mid || topic == mname)
        {
                if (who->query("id") == me->query("parents/father") ||
                    who->query("id") == me->query("parents/mother"))
                        command("say ����ĸ�״��˵����䰡��������������");
                else
                        command("say ���Ǽ�ĸ�����䣬����ʶ��ĸ��");
                return 1;
        }
                                
        switch (topic) 
        {
        case "�е���" : 
        case "�аְ�" : 
                if (who->query("id") == me->query("parents/father"))
                        command("say ���״��˺ã�");
                else
                        command("say ��ռ�ұ��ˣ��Ŷ�û�У�");
                return 1;
                      
        case "��ĸ��" : 
        case "������" : 
                if (who->query("id") == me->query("parents/mother"))
                {
                        command("say ĸ�״��˼��飡");
                        command("cat " + who->query("id"));
                }
                else
                        command("say ��ռ�ұ��ˣ��Ŷ�û�У�");
                return 1;
        
        case "������" :
                if (who->query("gender") != "����")
                        command("say �㲻�����ˣ�����ô�ܽ��������أ�");
                else
                        command("say ����ã�");
                return 1;
        case "�а���" : 
                if (who->query("gender") != "Ů��")
                        command("say �㲻��Ů�ˣ�����ô�ܽ��㰢���أ�");
                else
                        command("say ���̼��飡");
                return 1;
        case "�йù�" : 
                if (who->query("gender") != "Ů��")
                        command("say �㲻��Ů�ˣ�����ô�ܽ���ù��أ�");
                else
                        command("say �ùü��飡");
                return 1;                
        default: 
                return 0;
        }
}
                       
void consider()
{
        string *basic = ({ "force", "dodge", "unarmed", "cuff", "strike", "finger",
                           "hand", "claw", "sword", "blade", "staff", "hammer", 
                           "club", "whip", "dagger", "throwing", "parry", "magic",
                           "medical", "poison", "chuixiao-jifa", "tanqin-jifa",
                           "guzheng-jifa", "cooking",
        });       
        string skill;
        string *chat_chance_combat_here = ({(: exert_function, "powerup" :)}), *my_skill,
               *basic_skill = ({}), *use_skill = ({}), dir;
        mapping skills;
        int i, j, k;
        mixed *file;
        object me = this_object();
        
        if (! environment())  
                return;   
        skills = me->query_skills();        
        if (sizeof(skills) && sizeof(skills) > query("skills_learned"))
        {
                my_skill = keys(skills);
                for (i = 0; i < sizeof(basic); i++)
                        if (member_array(basic[i], my_skill) != -1)
                                basic_skill += ({basic[i]});

                for (i = 0; i < sizeof(my_skill); i++)   
                        if (SKILL_D(my_skill[i])->type() != "knowledge" 
                        &&  member_array(my_skill[i], basic) == -1)
                                use_skill += ({my_skill[i]});                               

                for (i = 0; i < sizeof(basic_skill); i++)
                for (j = 0; j < sizeof(use_skill); j++)
                if (SKILL_D(use_skill[j])->valid_enable(basic_skill[i]) 
                &&  ! stringp(query_skill_mapped(basic_skill[i])))
                {
                        map_skill(basic_skill[i], use_skill[j]);
                        if (sizeof(me->query_skill_prepare()) < 2)
                        if (basic_skill[i] == "finger" 
                        ||  basic_skill[i] == "strike" 
                        ||  basic_skill[i] == "hand" 
                        ||  basic_skill[i] == "cuff" 
                        ||  basic_skill[i] == "claw" 
                        ||  basic_skill[i] == "unarmed")
                                prepare_skill(basic_skill[i], use_skill[j]);
                                                
                } else 
                        continue;
                                
                if (sizeof(skills) > query("skills_learned"))
                        set("perform_skills", 0);
                                
                if (! query("perform_skills"));  
                {
                        for (i = 0; i < sizeof(basic_skill); i++)
                        if (basic_skill[i] != "magic" && basic_skill[i] != "medical"
                        &&  basic_skill[i] != "cooking"
                        &&  stringp(query_skill_mapped(basic_skill[i])))
                        {
                                dir = "/kungfu/skill/" + query_skill_mapped(basic_skill[i]) + "/";
                                if (SKILL_D(query_skill_mapped(basic_skill[i]))->valid_enable("force"))
                                        dir += "perform/";
                                if (file_size(dir) != -2)
                                        continue;
                                file = get_dir(dir, -1);
                                if (! sizeof(file))
                                        continue;

                                for (k = 0; k < sizeof(file); k++)
                                {
                                        if (file[k][0][strlen(file[k][0])-2..strlen(file[k][0])] != ".c")
                                                        continue;
                                        file[k][0] = replace_string(file[k][0], ".c", "");
                                        chat_chance_combat_here += 
                                                ({( : perform_action, basic_skill[i] + "." + file[k][0]: )}); 
                                }
                        } else 
                                continue;     

                        set("chat_msg_combat", chat_chance_combat_here);                        
                        set("perform_skills", 1); 
                }

                set("chat_msg_combat", chat_chance_combat_here);
                reset_action();
                set("skills_learned", sizeof(skills));  
                command("say ��������֪���ˣ��һ����ˣ�\n");  
        }

        set("jiali", query_skill("force") / 2 + 10);
        save();

        command("say ����������ס�ˣ������ˣ�\n");
        return;
}

int accept_object(object who, object ob)
{
        if (who->query("id") == query("parents/father")
        ||  who->query("id") == query("parents/mother"))
        {
                remove_call_out("provide");
                call_out("provide", 1);
                return 1;
        } else 
                return 0;
}

void provide()
{
        object *ilist, ob;
        object weapon, armor;
        int i;
        
        if (! environment()) return;
        ilist = all_inventory(this_object());
        if (sizeof(ilist) < 1) return;

        for (i = 0; i < sizeof(ilist); i++)
        {
                ob = ilist[i];
                if (ob->query("weapon_prop/damage"))
                {
                        if (objectp(weapon = query_temp("weapon")) && weapon != ob 
                        &&  ob->query("weapon_prop/damage") > 
                            weapon->query("weapon_prop/damage"))
                                weapon->unequip();
                        command("wield " + ob->query("id"));
                }

                if (ob->query("armor_prop/armor"))
                { 
                        if (objectp(armor = query_temp("armor/" + ob->query("armor_type")))
                        &&  armor != ob 
                        &&  ob->query("armor_prop/armor") > 
                            armor->query("armor_prop/armor"))
                                armor->unequip();
                        command("wear " + ob->query("id")); 
                }    

                if (ob->query("food_remaining"))
                        command("eat " + ob->query("id"));
                else 
                if (ob->query("liquid/remaining"))
                        command("drink " + ob->query("id"));
        }

        set("jiali", query_skill("force") / 2 + 10);   

        command("sweat");
        return;
}


