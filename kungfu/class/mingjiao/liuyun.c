// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// liuyun.c ����ʹ

#include <ansi.h>

inherit NPC;
inherit F_GUARDER; 
inherit F_COAGENT; 

void create()
{
        set_name("����ʹ", ({ "liuyun shi", "shi", "liuyun"}) );
        set("title", "���̲�˹��ʹ");
        set("gender", "����");
        set("attitude", "friendly");
        set("age",49);
        set("long", "����ĸߴ���ױ��ۡ�\n");
        set("rank_info/respect","ʹ��");
        set("str", 25);
        set("int", 22);
        set("con", 25);
        set("dex", 26);
        set("per", 20);
        set("max_qi",2700);
        set("max_jing",1800);
        set("neili",3000);
        set("max_neili",3000);
        set("jiali",50);
        set("eff_jingli",1700);             
        set("level", 20);
        set("shen_type",0);
        set("combat_exp", 800000);
        
        set_skill("sword", 210);
        set_skill("parry", 210);
        set_skill("force", 210);
        set_skill("cuff", 210);
        set_skill("literate", 270);
        set_skill("dodge", 200);
        set_skill("qingfu-shenfa", 210);
        set_skill("shenghuo-shengong", 210);
        set_skill("shenghuo-ling", 210);
        
        map_skill("force", "shenghuo-shengong");
        map_skill("dodge", "qingyun-shenfa");
        map_skill("sword","shenghuo-ling");
        map_skill("parry", "shenghuo-ling");

        set("coagents", ({ 
                ([ "startroom" : "/d/mingjiao/qinyun", 
                   "id"        : "huiyue shi" ]), 
                ([ "startroom" : "/d/mingjiao/qinyun", 
                   "id"        : "miaofeng shi" ]), 
        })); 

        setup();

        carry_object("/clone/book/shenghuo-ling")->wield();
        carry_object("/clone/cloth/cloth")->wear();               
}

void init()
{
        object ob;
        
        ::init();        
        if (interactive(ob = this_player()) && ! is_fighting()) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        mapping myfam;
        
        myfam = (mapping)ob->query("family");
        
        if (myfam && myfam["family_name"] == "����")
                command("say ��ʥ������������٣�" + ob->name() + "�㻹���¹�");         
}
