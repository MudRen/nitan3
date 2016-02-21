// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>

inherit NPC;
inherit F_GUARDER; 
inherit F_COAGENT; 

void create()
{
        set_name("����ʹ", ({ "huiyue shi", "huiyue", "shi"}) );
        set("title", "���̲�˹��ʹ");
        set("gender", "Ů��");
        set("attitude", "friendly");
        set("age",38);
        set("long","��һͷ�ڷ����ͻ������죬�����Ӽ�����������ɫ���������͡�\n");
        set("rank_info/respect","ʹ��");
        set("str", 23);
        set("int", 24);
        set("con", 23);
        set("dex", 26);
        set("per", 24);
        set("max_qi",2200);
        set("max_jing",1700);
        set("neili",2800);
        set("max_neili",2800);
        set("jiali",50);
        set("eff_jingli",1500);             
        set("shen_type", 0);
        set("combat_exp", 680000);
        set("level", 20);
        
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
                   "id"        : "liuyun shi" ]), 
                ([ "startroom" : "/d/mingjiao/qinyun", 
                   "id"        : "miaofeng shi" ]), 
        })); 

        setup();

        carry_object("/clone/book/shenghuo-ling")->wield();
        carry_object("/clone/cloth/cloth")->wear();               
}

