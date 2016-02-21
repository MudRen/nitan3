// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// wu.c �⾢��

inherit NPC;

void create()
{
        set_name("�⾢��", ({ "wu jincao", "wu", "jincao" }));
        set("gender", "����");
        set("age", 43);                
	set("rank_info/respect","����");
	set("title","��������츱����ʹ");

	set("str", 28);
        set("int", 20);
        set("con", 23);
        set("dex", 22);
        set("per", 20);
        set("combat_exp", 145000);
        set("level", 8);
        set("attitude", "peaceful");
	set("max_qi",1000);
        set("max_jing",1000);
        set("neili",1000);
        set("max_neili",1000);
        set("eff_jingli", 1000);
	set("jiali",30);
	
        set_skill("parry",60);
        set_skill("blade",60);
        set_skill("qingfu-shenfa",60);
        set_skill("dodge", 60);
        set_skill("force",60);
        set_skill("lieyan-dao",60);
        set_skill("shenghuo-shengong",60);
        
        map_skill("force","shenghuo-shengong");
        map_skill("dodge","qingfu-shenfa");
        map_skill("parry","lieyan-dao");
        map_skill("blade","lieyan-dao");

        create_family("����", 37, "����");               
        setup();
        
        carry_object("/d/mingjiao/obj/green-cloth")->wear();
        carry_object("/clone/weapon/blade")->wield();
}

void attempt_apprentice(object ob)
{     
        command("say ���ڽ��·�æ��������ò��յ����ˡ�");
        command("say ��λ"+RANK_D->query_respect(ob)+"������ذɡ�");
        return;
}
