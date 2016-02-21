// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include "emei.h"

inherit NPC;
inherit F_MASTER;
int ask_for_ji();

void create()
{
        set_name("������", ({ "bei jinyi", "bei", "jinyi"}));
        set("long", "���Ƕ����ɵĵ��Ĵ��׼ҵ��ӡ�\n");
        set("gender", "Ů��");
        set("age", 21);
        set("attitude", "peaceful");
        set("class", "fighter");
        set("shen_type", 1);

        set("str", 21);
        set("int", 25);
        set("con", 24);
        set("dex", 20);

        set("max_qi", 2100);
        set("max_jing", 1000);
        set("neili", 2500);
        set("max_neili", 2500);
        set("level", 10);
        set("combat_exp", 250000);

        set_skill("throwing", 60);
        set_skill("persuading", 100);
        set_skill("force", 120);
        set_skill("emei-xinfa", 120);
        set_skill("linji-zhuang", 100);
        set_skill("dodge", 100);
        set_skill("zhutian-bu", 100);
        set_skill("strike", 80);
        set_skill("jinding-zhang", 80);
        set_skill("finger", 60);
        set_skill("tiangang-zhi", 60);
        set_skill("parry", 100);
        set_skill("sword", 120);
        set_skill("huifeng-jian", 120);
        set_skill("literate", 100);
        set_skill("mahayana", 100);
        set_skill("buddhism", 100);
        set_skill("martial-cognize", 20);

        map_skill("force","linji-zhuang");
        map_skill("finger","tiangang-zhi");
        map_skill("dodge","zhutian-bu");
        map_skill("strike","jinding-zhang");
        map_skill("sword","huifeng-jian");
        map_skill("parry","huifeng-jian");

        prepare_skill("strike", "sixiang-zhang");

        set("inquiry", ([
		"����"     : "��ȥ��ɽ�����������Ҿ��ֱ�ʦ��ɡ������ڸ����֡�ǧ���֡�\n�����֡������ֺ����������С�\n",
                "���ʦ̫" : "���Ǳ��������ˣ��ڻ��������С�\n",
                "����ܽ"   : (: ask_for_ji :),
        ]));
        
        create_family("������", 4, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "sword.xian" :),
                (: perform_action, "strike.xing" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        set("master_ob", 3);
	set("master_ob", 3);
	set("master_ob", 3);
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        command("say �ðɣ��Ҿ��������ˡ�");
        command("recruit " + ob->query("id"));
}

int ask_for_ji()
{
        object ob;
        ob = this_player();
        tell_object(ob,"������˵��������ܽ���������ء��������벻�����ˣ�\n"); 
        ob->set("marks/ji",1);
        return 1;
}
