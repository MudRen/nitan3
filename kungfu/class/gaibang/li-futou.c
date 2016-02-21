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
	set_name("�ͷ", ({"li futou", "futou", "li"}));
	set("title", "ؤ����������");
        set("bunch/name","ؤ��");
	set("gender", "����");
	set("age", 32);
	set("long", 
		"�ͷ���Ժ�ˬ����ʹ��師�������޵У���ؤ�������ĺ���֮ʿ��\n");

	set("attitude", "heroism");
	set("class", "beggar");
	set("str", 30);
	set("int", 18);
	set("con", 28);
	set("dex", 20);
	set("max_qi", 650);
	set("max_jing", 400);
	set("neili",600);
	set("max_neili", 600);
	set("jiali", 50);
	set("level", 7);
	set("combat_exp", 166000);
	
	set_skill("force", 60);
        set_skill("huntian-qigong", 60);
        set_skill("unarmed", 60);
        set_skill("changquan", 60);
        set_skill("dodge", 60);
        set_skill("feiyan-zoubi", 60);
        set_skill("hand", 60);
        set_skill("shexing-diaoshou", 60);
        set_skill("strike", 60);
        set_skill("xiaoyaoyou", 60);
        set_skill("parry", 60);
        set_skill("staff", 60);
        set_skill("fengmo-zhang", 60);
        set_skill("jiaohua-bangfa", 60);
        set_skill("blade", 60);
        set_skill("liuhe-dao", 60);
        set_skill("begging", 60);
        set_skill("checking", 60);
        set_skill("literate", 60);
        set_skill("martial-cognize", 45);
	set_skill("stealing", 60); 
	
        map_skill("force", "huntian-qigong");
        map_skill("hand", "shexing-diaoshou");
        map_skill("blade", "liuhe-dao");
        map_skill("strike", "xiaoyaoyou");
        map_skill("staff", "fengmo-zhang");
        map_skill("parry", "shexing-diaoshou");
        map_skill("dodge", "feiyan-zoubi");
        map_skill("unarmed", "changquan");
	
	prepare_skill("hand", "shexing-diaoshou");
	
	create_family("ؤ��", 19, "����");
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
