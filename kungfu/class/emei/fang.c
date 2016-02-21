// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// fang.c ������

#include <ansi.h>
#include "emei.h"

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("������", ({ "fang bilin","fang","bilin"}));
        set("long",
                "���Ƕ����ɵĵ��Ĵ��׼ҵ��ӡ�\n");
        set("gender", "Ů��");
        set("age", 20);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("shen", 10000);
        set("class", "fighter");

        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("per", 30);

        set("max_qi", 1000);
        set("max_jing", 500);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jingli", 1500);
        set("max_jingli", 1500);
        set("level", 10);
        set("combat_exp", 150000);
        set("score", 1000);
        
        set_skill("persuading", 40);
        set_skill("throwing", 30);
        set_skill("force", 60);
        set_skill("dodge", 80);
        set_skill("finger", 50);
        set_skill("parry", 70);
        set_skill("strike", 80);
        set_skill("blade", 60);
        set_skill("emei-xinfa", 60);
        set_skill("jinding-zhang", 80);
        set_skill("tiangang-zhi", 50);
        set_skill("yanxing-dao", 60);
        set_skill("zhutian-bu", 80);
        set_skill("linji-zhuang", 60);

        map_skill("force","linji-zhuang");
        map_skill("finger","tiangang-zhi");
        map_skill("dodge","zhutian-bu");
        map_skill("strike","jinding-zhang");
        map_skill("blade","yanxing-dao");
        map_skill("parry","yanxing-dao");
        
        set("inquiry", ([
		"����"     : "��ȥ��ɽ�����������Ҿ��ֱ�ʦ��ɡ������ڸ����֡�ǧ���֡�\n�����֡������ֺ����������С�\n",
                "���ʦ̫" : "���Ǳ��������ˣ��ڻ��������С�\n",
        ]));
        
        create_family("������", 4, "����");

        set("master_ob", 2);
	setup();
        carry_object("/d/city/obj/gangdao")->wield();
        carry_object("/d/city/obj/cloth.c")->wear();
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        command("say �ðɣ��Ҿ��������ˡ�");
        command("recruit " + ob->query("id"));
}
