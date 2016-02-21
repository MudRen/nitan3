// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// zhang.c ����

#include <ansi.h>
#include "mingjiao.h"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;

string ask_me();
string ask_xunluo();

void create()
{
	set_name("����", ({ "zhang zhong", "zhang", "zhong" }) );
	set("title", HIG "����" HIW "���ڵ���" NOR);    
	set("gender", "����");
	set("age",51);
	set("long", "������������ɢ��֮һ���˳����ڵ��˵����С�\n");
        set("rank_info/respect","����");
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("max_qi",1500);
        set("max_jing",1200);
        set("jiali",50);
        set("eff_jingli",1100);	
	set("shen_type",0);
	set("combat_exp", 600000);
        set("level", 10);
        set("no_get","���ж�����˵̫���ˡ�\n");

	set_skill("sword",120);
	set_skill("parry", 120);
	set_skill("literate",120);
	set_skill("force",120);
	set_skill("dodge",120);
	set_skill("liehuo-jian",120);
	set_skill("qingfu-shenfa",120);
	set_skill("shenghuo-shengong",120);

	map_skill("force","shenghuo-shengong");
	map_skill("dodge","qingfu-shenfa");
	map_skill("sword","liehuo-jian");
	map_skill("parry","liehuo-jian");        
        
        create_family("����", 36, "��ɢ��");

	set("inquiry", ([
                "̫��ȭ��"  : (: ask_me :),
		"�ؼ�"  : (: ask_me :),
                "��ӡ"  : (: ask_xunluo :),
        ]));

        set("xl", 2);
        set("xl2", "zhang-zhong");
	set("master_ob",3);
	setup();
	
        carry_object("/d/mingjiao/obj/yel-cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();	
}

#include "5san_app.h";
#include "xunluo.h";

string ask_me()
{
        mapping fam; 
        object ob;
        
        if (! (fam = this_player()->query("family")) || fam["family_name"] != "����")
                return RANK_D->query_respect(this_player())+"�뱾��������������֪�˻��Ӻ�̸��"; 
                
        if (this_player()->query_temp("marks/��1"))
        {
                ob = new("/d/mingjiao/obj/force_book");
                ob->move(this_player());
                this_player()->delete_temp("marks/��1");
                return "�ðɣ���Ȼ���������Ѿ�ͬ�⣬��Ͱ��Ȿ̫��ȭ����ȥ�ɡ�\n";
        }
        return "�Բ��𣬲�������ͬ���Ҳ��ܸ��㡣\n";
}
