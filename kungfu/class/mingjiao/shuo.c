// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// shuo.c 说不得

#include <ansi.h>
#include "mingjiao.h"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;

void create()
{
        set_name("说不得", ({ "shuo bude","shuo","bude" }) );
	set("title", HIG "明教" HIW "布袋和尚" NOR);    

        set("gender", "男性");
        set("class", "bonze");
        set("age",49);
        set("long","他就是明教五散人之一，人称布袋和尚。\n"+
                   "腰中绑着一条布袋。\n");
        set("rank_info/respect","大师");
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);
        set("max_qi",1500);
        set("max_jing",1200);
        set("jiali",50);
        set("eff_jingli",1100);        
        set("shen_type",0);
        set("level", 10);
        set("combat_exp", 500000);
        
        set_skill("blade", 85);
        set_skill("lieyan-dao", 85);
        set_skill("force", 80);
        set_skill("cuff", 80);
        set_skill("literate", 70);
        set_skill("dodge", 80);        
        set_skill("qingfu-shenfa", 85);
        set_skill("shenghuo-shengong", 85);
        
        map_skill("force","shenghuo-shengong");
        map_skill("dodge","qingfu-shenfa");
        map_skill("blade","lieyan-dao");
        map_skill("parry","lieyan-dao");
        
        create_family("明教", 36, "五散人");

        set("inquiry", ([
                "rumors" : "我教张教主在光明顶练武场上大败六大派，真令我明教扬眉吐气。",
                "name": "说不得。",
                "here": "这里就是明教光明顶。。",
        ]));
        
        set("master_ob",1);
	setup();
        
        carry_object("/d/mingjiao/obj/yel-cloth")->wear();
        carry_object("/clone/weapon/blade")->wield();
        carry_object("/d/mingjiao/obj/yiqi-dai");
}

#include "5san_app.h";

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        object me;
        
        me = this_player();
        if (! present(ob, environment())) return;
        command("hi " + ob->query("id"));           
}

void relay_emote(object me,string arg)
{
        command("say 说不得，说不得！ ");
}
