// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// zhou.c �ܵ�

#include <ansi.h>
#include "mingjiao.h"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;

string ask_blade();

void create()
{
        object weapon;
        set_name("�ܵ�", ({ "zhou dian","zhou","dian" }) );       
        set("gender", "����");
        set("age",52);
        set("long", "������������ɢ��֮һ���ܵߡ�\n");
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

        set_skill("blade",80);
        set_skill("force",80);
        set_skill("dodge",80);
        set_skill("claw",80);
        set_skill("qingfu-shenfa",85);
        set_skill("shenghuo-shengong",85);
        set_skill("lieyan-dao",85);
        set_skill("yingzhua-shou",85);
        map_skill("claw","yingzhua-shou");
        map_skill("force","shenghuo-shengong");
        map_skill("dodge","qingfu-shenfa");
        map_skill("blade","lieyan-dao");
        map_skill("parry","lieyan-dao");
        
        prepare_skill("claw","yingzhua-shou");

        create_family("����",36,"��ɢ��");

        set("inquiry", ([
                "�赶"     : (: ask_blade :),
                "���浶" : "�����ҵ�������������ã����Խ���㡣\n",
        ]));
        set("master_ob",1);
	setup();

        carry_object("/d/mingjiao/obj/yel-cloth")->wear();
        carry_object("/d/mingjiao/obj/qingyan-dao")->wield();
}

string ask_blade()
{ 
        object blade,me,ob;
        me = this_player(); 
        ob = this_object();

        if (count_lt(me->query("combat_exp"), 100000))
                return RANK_D->query_respect(me) + "�Ĺ���̫�����㣬����Ҳ����ס������";
                
        if (present("qingyan dao", me)|| me->query_temp("qydao"))
                return RANK_D->query_respect(me) + "��ֻ��һ�ѣ��Ѿ����������";
                
        if (objectp(blade = present("qingyan dao", ob)))
                blade->move(me);
               
        else 
                return "�������治��ʱ�򣬱����Ѿ������ˡ�";
        
        me->set_temp("qydao", 1);
        return "��Ҷ��ǽ���ͬ������������,������ȥ�á�";
         
}

#include "5san_app.h";

