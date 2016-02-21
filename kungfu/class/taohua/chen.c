// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// chen.c ������

#include <ansi.h>;
inherit NPC;

#define ZHENJING    "/clone/book/jiuyin2"

void create()
{
        object ob;
        set_name("������", ({ "chen xuanfeng", "chen", "xuanfeng" }));
        set("title", "�ڷ�˫ɷ");
        set("nickname", YEL "ͭʬ" NOR);
        set("gender", "����");
        set("age", 35);
        set("long", "�����ǻ�ҩʦ�Ķ����ӣ���Ũü���ۣ�������������\n"
                    "��׳����ֻ����ɫ΢΢���ơ�\n");
        set("attitude", "aggressive");
        set("str", 28);
        set("int", 25);
        set("con", 30);
        set("dex", 25);
        set("shen_type", -1);

        set("max_qi", 5000);
        set("max_jing", 3500);
        set("neili", 6000);
        set("max_neili", 6000);
        set("jiali", 220);
        set("level", 20);
        set("combat_exp", 2000000);

        set_skill("claw", 240);
        set_skill("strike", 240);
        set_skill("force", 220);
        set_skill("parry", 240);
        set_skill("dodge", 220);
        set_skill("bibo-shengong", 240);
        set_skill("cuixin-zhang", 240);
        set_skill("jiuyin-zhao", 240);
        set_skill("luoying-shenfa", 220);
        set_skill("martial-cognize", 220);

        map_skill("force", "bibo-shengong");
        map_skill("parry", "jiuyin-zhao");
        map_skill("dodge", "luoying-shenfa");
        map_skill("claw", "jiuyin-zhao");
        map_skill("strike", "cuixin-zhang");

        prepare_skill("claw", "jiuyin-zhao");
        prepare_skill("strike", "cuixin-zhang");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "claw.duo" :),
                (: perform_action, "claw.sha" :),
                (: perform_action, "strike.cui" :),
                (: exert_function, "recover" :),
        }));

        create_family("�һ���", 2, "�������");
        set("inquiry", ([
                "ͭʬ" : "�����ϵ��˶���ô���ҵģ����²��£�����������",
                "��а" : "������ʦ���Ĵºš�",
                "����" : "�������ʦ�����ĸ���֮һ���Ǹ��϶��ס�ڰ���ɽ��",
                "�ϵ�" : "����ү�ѳ��ҵ�����ȥ�ˣ�������һ�ơ�",
                "��ؤ" : "��ؤͳ����ԭ��ؤ�������Ϊǿ��",
                "����" : "������ʦ���Ķ�Ů�����ǵ������ԡ�",
                "���߹�" : "���߹��书��ǿ�����ҽ̻������С������ʮ���ƣ��ɺޣ�",
                "÷����" : "�����ҵ�ʦ�ã�Ҳ���ҵ����ҡ�",
                "������" : "��������ô�����ǰ׳հ���",
                "��ҩʦ" : "������ʦ����"
        ]));
        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

        setup();
        if (clonep())
        {
                ob = find_object(ZHENJING);
                if (! ob) ob = load_object(ZHENJING);

                if (environment(ob) && random(3) == 1)
                {
                        ob = new(ZHENJING);
                        ob->move(this_object());
                }
                else if (! environment(ob))
                        ob->move(this_object());
        }
        carry_object("/clone/cloth/bupao")->wear();
}

void attempt_apprentice(object ob)
{
        command("say �ٷ��ң������");
}

int accept_fight(object me)
{
        command("say ���ҹ�����");
        return 0;
}

int accept_hit(object me)
{
        command("say ������");
        kill_ob(me);
        return 1;
}

void kill_ob (object ob)
{
        object me = this_object();
        object where = environment(me);
        object guard = present("mei chaofeng", where);

        set_temp("my_killer", ob);
        ::kill_ob(ob);

        if (guard && ! guard->is_fighting())
        {
                message_vision(HIW "\n$N" HIW "��ŭ������Ȼ�۸������Ǻڷ�˫ɷ"
                               "ͷ�����ˣ����ɣ�\n\n" NOR, guard);
                guard->kill_ob(ob);
        }
}

void die()
{
        object obj, me;
       // int i, flag;
       int flag;

	flag = 0;
	me = this_object();
        if (objectp(obj = query_last_damage_from()))
		obj->set_temp("kill_xuanfeng", 1);
	else
		return;
	
	if (obj->query_temp("kill_chaofeng")) 
	{
		obj->set("kill_th_traitor", 1);
		flag = 1;
	}

        if (flag) 
	        message_vision(HIR"������Һ�һ����������������������ˣ�����\n"NOR, this_object());
	else 
	        message_vision(HIR"������Һ�һ����������������ұ��𣡣���\n"NOR, this_object());
        
	::die();
}
