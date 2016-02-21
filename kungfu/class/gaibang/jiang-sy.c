// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include "gaibang.h"

inherit NPC;
inherit F_MASTER;

#include "fight.h"

void create()
{
	set_name("������", ({"jiang shangyou", "jiang shangyou", "jiang"}));
	set("title", "ؤ���������");
	set("gender", "����");
	set("age", 28);
	set("long", 
		"����Զ��������Ǳˮ���֣��������˸���žͽС������㡹�����Ρ�\n");

	set("attitude", "peaceful");
	set("class", "beggar");
	set("str", 20);
	set("int", 24);
	set("con", 20);
	set("dex", 28);
	set("max_qi", 550);
	set("max_jing", 550);
	set("neili", 400);
	set("max_neili", 400);
	set("jiali", 40);
        set("level", 6);	
	set("combat_exp", 100000);
	
	set_skill("force", 55);
        set_skill("huntian-qigong", 55);
        set_skill("dodge", 55);
        set_skill("feiyan-zoubi", 55);
        set_skill("unarmed", 50);
        set_skill("changquan", 50);
        set_skill("hand", 55);
        set_skill("shexing-diaoshou", 55);
        set_skill("strike", 55);
        set_skill("xiaoyaoyou", 55);
        set_skill("parry", 55);
        set_skill("staff", 55);
        set_skill("fengmo-zhang", 55);
        set_skill("jiaohua-bangfa", 55);
        set_skill("blade", 55);
        set_skill("liuhe-dao", 55);
        set_skill("begging", 55);
        set_skill("checking", 55);
        set_skill("literate", 55);
        set_skill("martial-cognize", 40);
	
        map_skill("force", "huntian-qigong");
        map_skill("unarmed", "changquan");
        map_skill("hand", "shexing-diaoshou");
        map_skill("blade", "liuhe-dao");
        map_skill("strike", "xiaoyaoyou");
        map_skill("staff", "fengmo-zhang");
        map_skill("parry", "shexing-diaoshou");
        map_skill("dodge", "feiyan-zoubi");
	
	prepare_skill("hand", "shexing-diaoshou");

	create_family("ؤ��", 20, "����");

	set("master_ob",1);
	setup();

	carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        string title = ob->query("title");
        int lvl = ob->query("family/beggarlvl");

        if (! permit_recruit(ob))
                return;
               
        if (ob->query("gender") != "����") 
                return;

        if (ob->query("shen") < 0)
        {
                command("say ����Ϊؤ����ӣ���Ȼ�������£�");
                return;
        }
        command("nod");
        command("say �ұ�����Ϊͽ���պ�ɵ��������壬Ī����ؤ��������");
        command("recruit " + ob->query("id"));

        if (ob->query("class") != "beggar")
                ob->set("class", "beggar");

        if (lvl > 0)
        {
                ob->set("family/beggarlvl", lvl);
                ob->set("title", title);
        }
}
