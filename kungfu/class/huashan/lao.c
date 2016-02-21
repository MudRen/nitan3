// lao-denuo.c

#include <ansi.h>
inherit NPC;
inherit F_GUARDER;
inherit F_MASTER;

#include "qizong.h"

string ask_me(object who);
void create()
{
        set_name("�͵�ŵ", ({ "lao denuo","lao","denuo" }) );
        set("nickname", "�Ϻ���");
        set("gender", "����");
        set("age", 61);
        set("long", "�͵�ŵ������Ⱥ�Ķ����ӣ�����Ҳ�ǲ�����\n");
        set("attitude", "peaceful");

        set("str", 26);
        set("con", 30);
        set("int", 24);
        set("dex", 30);

        set("max_qi", 3400);
        set("max_jing", 1700);
        set("neili", 2800);
        set("max_neili", 2800);

        set("combat_exp", 150000);
        set("shen_type", -1);
        set("score", 5000);

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "strike.lao" :),
                (: perform_action, "cuff.song" :),
                (: perform_action, "sword.feng" :),
                (: perform_action, "sword.lian" :),
                (: exert_function, "recover" :)
        }) );

        set_skill("unarmed", 120);
        set_skill("sword", 140);
        set_skill("force", 140);
        set_skill("cuff", 120);
        set_skill("strike", 120);
        set_skill("parry", 120);
        set_skill("dodge", 120);
        set_skill("literate", 100);
        set_skill("martial-cognize", 100);

        set_skill("huashan-jianfa", 140);
        set_skill("huashan-xinfa", 140);
        set_skill("huashan-quan", 120);
        set_skill("huashan-zhang", 120);
        set_skill("huashan-shenfa", 120);

        map_skill("sword", "huashan-jianfa");
        map_skill("parry", "huashan-jianfa");
        map_skill("force", "huashan-xinfa");
        map_skill("cuff", "huashan-quan");
        map_skill("strike", "huashan-zhang");
        map_skill("dodge", "huashan-shenfa");

        prepare_skill("strike", "huashan-zhang");
        prepare_skill("claw", "huashan-quan");

        set_temp("apply/damage", 100);
        set_temp("apply/armor", 100);

        set("inquiry", ([
               "����Ⱥ"     :  "��������ʦ��������������\n",
               "������"     :  "������ʦĸ��\n",
                "��ϼ�ؼ�" : (: ask_me :),
        ]));

        set("apply/dodge", 100);

        set("coagents", ({
                ([ "startroom" : "/d/huashan/qunxianguan",
                   "id"        : "yue buqun" ]),
        }));

        create_family("��ɽ��", 14, "����");
        set("master_ob",4);
	set("master_ob",2);
	setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        if( !permit_recruit(ob) )
                return;
        
        if (ob->query("shen") < 0)
        {
             command("shake");
             command("say �һ�ɽ�����������ɣ�������������������֮ͽ��");
             return;
        }

        command("say �ðɣ��Ҿ��������ˡ�");
        command("recruit " + ob->query("id"));
}


int accept_ask(object me, string topic)
{
        switch (topic)
        {
        case "����ʽ" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/huashan-jianfa/jie",
                           "name"    : "����ʽ",
                           "sk1"     : "huashan-jianfa",
                           "lv1"     : 30,
                           "gongxian": 60,
                           "shen"    : 500, ]));
                break;

        case "����Ʈ��" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/huashan-zhang/piao",
                           "name"    : "����Ʈ��",
                           "sk1"     : "huashan-zhang",
                           "lv1"     : 30,
                           "gongxian": 60,
                           "shen"    : 600, ]));
                break;

        case "����ʽ" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/huashan-quan/song",
                           "name"    : "����ʽ",
                           "sk1"     : "huashan-quan",
                           "lv1"     : 40,
                           "gongxian": 100,
                           "shen"    : 800, ]));
                break;

        case "����������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/huashan-jianfa/lian",
                           "name"    : "����������",
                           "sk1"     : "huashan-jianfa",
                           "lv1"     : 50,
                           "force"   : 100,
                           "gongxian": 150,
                           "shen"    : 1200, ]));
                break;

        default:
                return 0;
        }
}


string ask_me(object who)
{
        int i;
        object *ob, book;

        if ((random(10) < 8) || is_fighting())
                return "�Բ�������£��Ҳ�������㻹������ʦ��ȥ�ɣ�\n";

        set_temp("apply/attack",  50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage",  50);

        message("vision",
                YEL "����������㶼֪���ˣ�������ȥ���ɣ�\n"
                "�͵�ŵʹ���������������棬�����ޱȣ�һ������Ц�����ģ����\n" NOR,
                environment(), this_object());
                
        set("chat_msg_combat", ({
                (: random_move :)
        }) );
        set("chat_chance", 15);
        set("chat_msg", ({
                (: random_move :)
        }) );
        
        ob = all_inventory(environment());
        for (i = sizeof(ob) - 1; i >= 0; i--) 
        {
                if (! userp(ob[i])) continue;
                
                if (ob[i]->query_temp("hs/askzixia", 1))
                {
                        ob[i]->delete_temp("hs/askzixia");
                        book = new("/clone/book/zixia_book");
                        book->move(environment(this_object()));
                }
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
        
        return "�Ҵ�ʦͶ�գ����踺�أ��㾹�Ҵ��ҵ����⣡\n";
}


