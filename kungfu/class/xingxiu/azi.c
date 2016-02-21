inherit NPC;
inherit F_MASTER;

#include <ansi.h>
#include "xingxiu.h"

string ask_me();
int ask_ding(object me);
int do_sou(string arg);
void create()
{
        set_name("����", ({ "a zi", "a", "zi"}));
        set("nickname", "������Сʦ��");
        set("long", 
                "�����Ƕ�������Ӱ��ϡ�\n"
                "������������������������͸��һ��а����\n");
        set("gender", "Ů��");
        set("age", 15);
        set("attitude", "peaceful");
        set("class", "fighter");
        set("shen_type", -1);
        set("str", 18);
        set("int", 28);
        set("con", 20);
        set("dex", 24);
        
        set("max_qi", 300);
        set("max_jing", 300);
        set("neili", 500);
        set("max_neili", 500);
        set("jiali", 10);
        set("combat_exp", 45000);

        set_skill("force", 60);
        set_skill("guixi-gong", 60);
        set_skill("huagong-dafa", 20);
        set_skill("dodge", 40);
        set_skill("zhaixing-gong", 40);
        set_skill("strike", 40);
        set_skill("chousui-zhang", 40);
        set_skill("claw", 40);
        set_skill("sanyin-zhua", 40);
        set_skill("whip", 80);
        set_skill("chanhun-suo", 80);
        set_skill("parry", 40);
        set_skill("poison", 50);
        set_skill("staff", 10);
        set_skill("tianshan-zhang", 10);

        set("no_teach", ([
                "huagong-dafa" : "�����������ɽ���ɣ��ҿɲ�Ը��������",
        ]));

        map_skill("force", "guixi-gong");
        map_skill("dodge", "zhaixinggong");
        map_skill("strike", "chousui-zhang");
        map_skill("claw", "sanyin-zhua");
        map_skill("parry", "tianshan-zhang");
        map_skill("staff", "tianshan-zhang");
        map_skill("whip", "chanhun-suo");

        prepare_skill("strike", "chousui-zhang");
        prepare_skill("claw", "sanyin-zhua");

        create_family("������", 2, "����");

        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "whip.suo" :),
                (: exert_function, "recover" :),
        }) );

        set("swmuding", 1);
        set("inquiry", ([
                "ľ��" : "�ֿ�����һ��ѣ����Լ�ȥ�Ұɣ�",
                "��ľ����" : (: ask_ding :),
        ]));

        set("master_ob", 4);
	setup();

        carry_object("/clone/weapon/rousisuo")->wield();
        carry_object("/d/xingxiu/obj/xxqingxin-san");
        carry_object("/d/xingxiu/obj/xxqingxin-san");
}

void attempt_apprentice(object ob)
{
        command("say �Ҳ���ͽ�ܣ�");
        return;
        welcome(ob);
        command("recruit " + ob->query("id"));
}

int ask_ding(object me)
{
        if(me->query_temp("sou/done")==1)
                return notify_fail("���ϳ�����һ�۵������㻹���ʲô����\n");
        
        if(me->query("family/family_name") != "������")
        {  
                say("����˵�������ⶫ���ɲ��Ǹ����õġ���\n");
                return 0;
        }  
        
        if ((int)me->query_temp("mark/ding") < 1)
                me->set_temp("mark/ding", 1 ); 
        
        me->add_temp("mark/ding", 1 );
        if ((int)me->query_temp("mark/ding") >= 5+random(5))
        {
                say("����˵�������������ô��ô������ľ�������ǲ��������ϣ��������ѣ�sou���Һ��ˡ�\n");
                add_action("do_sou","sou");
                return 1;
        }
        else
                say("����˵����ʲô��ľ�������ҿ�û�á��������ԩ�����ˣ�\n");
        return 1;
}

int do_sou(string arg)
{
    object me,ob1,ob2;
    ob2=this_object();
    me = this_player();
    if( !arg || arg=="" )
        return 0;
    
    if( arg=="a zi" ) 
    {
        message("vision",
            me->name() + "��Ц��˵�������ã����ҾͲ������ˡ���\n",
            environment(me),({me}));
        ob2->kill_ob(me);
        ob2->set_temp("last_damage_from",me);
        me->set_temp("azi/killer2",1); 
  
        ob1=present("xiao feng");
        if(!ob1 && !me->query_temp("xiaofeng/done"))
        {
                say(HIY+"���ϴ����������������ң��������������ң�����"NOR+"\n");
                ob1=new("/kungfu/class/xingxiu/xiaofeng");

                ob1->move(environment());
                message_vision(HIY+"\n���ش���һ��ŭ�ȣ���������˴�!���ϲ����£��н���ڿ�˭���۸��㣿��\n"+NOR,me);
                ob1->kill_ob(me);
                me->fight_ob(ob1);
                me->fight_ob(ob2);
                me->set_temp("xiaofeng/done",1);
                me->set_temp("sou/done",1);
                remove_action("do_sou","sou");          
                return 1; 
        }
        return 1;
    }
}


void accept_kill(object me)
{ 
        object ob;
        object ob1;
        if( is_fighting()) return;
        if(me->query_temp("you/done")==1 && me->query_temp("xiaofeng/done")==1)
        {
                this_object()->kill_ob(me);
                me->fight_ob(this_object());
        } 
        say("\n���ϴ�У���������������Ҫɱ�ң���\n\n");
//      this_object()->kill_ob(me);
//      me->fight_ob(this_object());
        me->set_temp("azi/killer",1);
        this_object()->set_temp("last_damage_from",me);
        ob1=present("xiao feng");
        ob=present("you tanzhi");
        if(!ob && !me->query_temp("you/done") )
        {
                ob=new("/kungfu/class/xingxiu/you");
                ob->move(environment());
                ob->kill_ob(me);
                me->fight_ob(ob);
                message_vision("��̹֮���һ������ס�����ȥ·��\n",me);
                        
        }
        if(!ob1 && !me->query_temp("xiaofeng/done") )
        {
                ob1=new("/kungfu/class/xingxiu/xiaofeng");
                ob1->move(environment());
                ob1->kill_ob(me);
                me->fight_ob(ob1);
                message_vision("������һ������ס�����ȥ·��\n",me);
        }
        return;
}
/*
int accept_kill(object who)
{
        object ob;
        object *obs;

        if (! living(this_object()))
                return 1;

        if (! query("swmuding"))
        {
                command("say ����ľ��ԭ����ȷ����������Ǻ���������������");
                command("inn " + who->query("id"));
                tell_object(who, "�㿴������һ���������������ӣ�������ͷһ��\n");
                return -1;
        }

        if (who->query("family/family_name") !=
            query("family/family_name"))
                return 1;

        obs = children("/clone/misc/swmuding");
        obs = filter_array(obs, (: ! clonep($1) :));
        if (sizeof(obs))
        {
                command("say ���أ�����ľ����ı�����������");
                tell_object(who, "�㿴�������鲻������α�����ɵ�̾��һ������\n");
                return -1;
        }

        if (count_gt(who->query("combat_exp"), 500000) &&
            who->query("shen") < -10000)
        {
                message_vision("$N��У����֣����֣��Ҹ���ľ�����ǣ�\n",
                               this_object());
                ob = new("/clone/misc/swmuding");
                ob->move(this_object());
                command("give " + ob->query("id") + " to " + who->query("id"));
                set("swmuding", 0);
                return -1;
        }

        command("say ��˵��û��ľ���ˣ�����ô���ţ�");
        return 1;
}
*/

void accept_fight(object me)
{
        say("�����۾�һ�ɣ����Ҳ�û�պ�������أ���\n");
        return;
}
