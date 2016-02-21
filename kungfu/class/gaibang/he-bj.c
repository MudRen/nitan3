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
	set_name("�β���", ({"he bujing", "he", "bujing"}));
	set("title", "ؤ���ߴ�����");
	set("gender", "����");
	set("age", 30);
	set("long", 
		"����λ������������ͷ�����ؤ���ߴ����ӡ�\n");
	set("attitude", "heroism");
	set("class", "beggar");
	set("str", 28);
	set("int", 18);
	set("con", 24);
	set("dex", 20);
	set("max_qi", 880);
	set("max_jing", 600);
	set("neili", 980);
	set("max_neili", 980);
	set("jiali", 90);	
	set("level", 10);
	set("combat_exp", 80000);
	
	set_skill("force", 80);
        set_skill("huntian-qigong", 80);
        set_skill("dodge", 80);
        set_skill("feiyan-zoubi", 80);
        set_skill("unarmed", 80);
        set_skill("changquan", 80);
        set_skill("hand", 80);
        set_skill("shexing-diaoshou", 80);
        set_skill("strike", 80);
        set_skill("xiaoyaoyou", 80);
        set_skill("parry", 80);
        set_skill("staff", 80);
        set_skill("fengmo-zhang", 80);
        set_skill("jiaohua-bangfa", 80);
        set_skill("blade", 80);
        set_skill("liuhe-dao", 80);
        set_skill("begging", 80);
        set_skill("checking", 80);
        set_skill("literate", 80);
        set_skill("stealing", 80);
        set_skill("martial-cognize", 60);
	
        map_skill("force", "huntian-qigong");
        map_skill("hand", "shexing-diaoshou");
        map_skill("unarmed", "changquan");
        map_skill("blade", "liuhe-dao");
        map_skill("strike", "xiaoyaoyou");
        map_skill("staff", "fengmo-zhang");
        map_skill("parry", "shexing-diaoshou");
        map_skill("dodge", "feiyan-zoubi");
	
	prepare_skill("hand", "shexing-diaoshou");

	create_family("ؤ��", 19, "����");
	
	set_temp("apply/blade", 100);
        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

	set("master_ob", 1);
	setup();

	carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        string title = ob->query("title");
        int lvl = ob->query("family/beggarlvl");

        if (! permit_recruit(ob))
                return;
               
          if (count_lt(ob->query("combat_exp"),  30000))
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
