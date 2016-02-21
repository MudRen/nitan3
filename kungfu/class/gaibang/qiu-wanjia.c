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
	set_name("�����", ({"qiu wanjia", "qiu", "wanjia"}));
	set("title", "ؤ���������");
	set("gender", "����");
	set("age", 18);
	set("long", 
		"����������ؤ������ü��Ŀ�㣬�ƺ��Ǽ������䣬�����˵���ͷ��\n");

	set("attitude", "heroism");
        set("class", "beggar");
        
	set("str", 17);
	set("int", 26);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 250);
	set("max_jing", 250);
	set("neili", 100);
	set("max_neili",100);
	set("jiali", 20);	
	set("level", 3);
	set("combat_exp", 10000);
	
	set_skill("force", 30);
        set_skill("huntian-qigong", 30);
        set_skill("dodge", 30);
        set_skill("feiyan-zoubi", 30);
        set_skill("unarmed", 35);
        set_skill("changquan", 35);
        set_skill("hand", 30);
        set_skill("shexing-diaoshou", 30);
        set_skill("strike", 30);
        set_skill("xiaoyaoyou", 30);
        set_skill("parry", 30);
        set_skill("staff", 30);
        set_skill("fengmo-zhang", 30);
        set_skill("jiaohua-bangfa", 30);
        set_skill("blade", 30);
        set_skill("liuhe-dao", 30);
        set_skill("begging", 30);
        set_skill("checking", 30);
        set_skill("literate", 30);
        set_skill("martial-cognize", 20);
	
        map_skill("force", "huntian-qigong");
        map_skill("hand", "shexing-diaoshou");
        map_skill("blade", "liuhe-dao");
        map_skill("strike", "xiaoyaoyou");
        map_skill("staff", "fengmo-zhang");
        map_skill("parry", "shexing-diaoshou");
        map_skill("dodge", "feiyan-zoubi");
        map_skill("unarmed", "changquan");
	
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

        if (ob->query("shen") < 0)
        {
                command("say ����Ϊؤ����ӣ���Ȼ�������£�");
                return;
        }
        command("nod");
        command("say �����Ϊʦ����Ҫ���óԿ��׼�����ú�����ؤ����ӣ�");
        command("recruit " + ob->query("id"));

        if (ob->query("class") != "beggar")
                ob->set("class", "beggar");

        if (lvl > 0)
        {
                ob->set("family/beggarlvl", lvl);
                ob->set("title", title);
        }
}
