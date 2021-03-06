// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// zhang.c 张中

#include <ansi.h>
#include "mingjiao.h"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;

string ask_me();
string ask_xunluo();

void create()
{
	set_name("张中", ({ "zhang zhong", "zhang", "zhong" }) );
	set("title", HIG "明教" HIW "铁冠道人" NOR);    
	set("gender", "男性");
	set("age",51);
	set("long", "他就是明教五散人之一，人称铁冠道人的张中。\n");
        set("rank_info/respect","道长");
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
        set("no_get","张中对你来说太重了。\n");

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
        
        create_family("明教", 36, "五散人");

	set("inquiry", ([
                "太极拳经"  : (: ask_me :),
		"秘籍"  : (: ask_me :),
                "画印"  : (: ask_xunluo :),
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
        
        if (! (fam = this_player()->query("family")) || fam["family_name"] != "明教")
                return RANK_D->query_respect(this_player())+"与本派素无来往，不知此话从何谈起？"; 
                
        if (this_player()->query_temp("marks/秘1"))
        {
                ob = new("/d/mingjiao/obj/force_book");
                ob->move(this_player());
                this_player()->delete_temp("marks/秘1");
                return "好吧，既然教主大人已经同意，你就把这本太极拳经拿去吧。\n";
        }
        return "对不起，不经教主同意我不能给你。\n";
}
