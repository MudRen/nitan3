// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// zhuang.c 庄铮 

inherit NPC;

string ask_me();
string ask_xunluo();
string ask_jihe();

void create()
{
        set_name("庄铮", ({ "zhuang zheng", "zhuang", "zheng" }));
        set("gender", "男性");
        set("age", 48);       
        set("long", "他是一个黑汉子，天生臂力奇大，一身皮肤被火熏又红又亮。\n");        
        set("rank_info/respect","旗主");
        set("title","明教锐金旗掌旗使");
        set("str", 40);
        set("int", 20);
        set("con", 26);
        set("dex", 22);
        set("per", 12);
        set("combat_exp", 160000);
        set("level", 7);
        set("attitude", "peaceful");
        set("max_qi",1000);
        set("max_jing",1000);
        set("neili",1000);
        set("max_neili",1000);
        set("eff_jingli", 1000);
        set("jiali",30);
        
        set_skill("blade",60);
        set_skill("parry",60);
        set_skill("dodge", 60);
        set_skill("force",60);
        set_skill("qingfu-shenfa",60);
        set_skill("lieyan-dao",60);        
        set_skill("shenghuo-shengong",60);
        map_skill("force","shenghuo-shengong");
        map_skill("dodge","qingfu-shenfa");
        map_skill("blade","lieyan-dao");
        map_skill("parry","lieyan-dao");
        
        create_family("明教",37,"弟子");
        
        set("inquiry", ([
                "画印"  : (: ask_xunluo :),
                "集合"  : (: ask_jihe :),
        ]));       
        set("xl", 6); 
        set("xl2", "zhuang");     
        setup();
        
        carry_object("/clone/weapon/blade")->wield();
        carry_object("/d/mingjiao/obj/red-cloth")->wear();
}

string ask_jihe()
{
        if (! this_player()->query_temp("mj/ling"))
                return "集合什么呀？吃饭时间到了？";
        command("nod");
        command("say 我立刻到光明顶广场集合。");
        this_object()->move("/d/mingjiao/gmd");
        return "你去请其他的旗使吧";
}
void attempt_apprentice(object ob)
{     
        command("say 由于教事繁忙，我已许久不收弟子了。");
        command("say 这位"+RANK_D->query_respect(ob)+"还是请回吧。");
        return;
}

#include "xunluo.h";

