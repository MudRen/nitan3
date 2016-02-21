// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// benchen.c

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("����", ({ "ben chen","chen"}) );
	set("gender", "����" );
	set("long", "����������Ϊ�۵Ĵ������۶���������������������ѷλ
�����³���Ϊɮ���������಻���⡣\n" );
	set("title", "�����µ�ʮ�ߴ�ɮ��");
	set("class", "bonze");
	set("age", 45);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("qi", 2500);
	set("max_qi", 2500);
	set("jing", 1000);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 100);
	set("level", 20);
	set("combat_exp", 800000);
	set("score", 1000000);

        set_skill("force", 220);
        set_skill("dodge", 210);
        set_skill("parry", 210);
        set_skill("finger", 220);
        set_skill("sword", 210);
        set_skill("tiannan-bufa", 210);
        set_skill("kurong-changong", 220);
        set_skill("duanjia-jian", 210);
        set_skill("sun-finger", 220);
        set_skill("buddhism", 140);
        set_skill("literate", 60);
        set_skill("martial-cognize", 200); 

        map_skill("force", "kurong-changong");
        map_skill("dodge", "tiannan-bufa");
        map_skill("parry", "sun-finger");
        map_skill("finger", "sun-finger");
        map_skill("sword", "duanjia-jian");
        prepare_skill("finger","sun-finger");
        create_family("����μ�", 15, "��ɮ");
	
        set("inquiry" ,([
                "��������" : "�ߣ�\n",
                "������" :  "�ߣ�\n",
        ]));
        
	setup();
	carry_object("/d/xueshan/obj/b-jiasha")->wear();
}
#include "ben.h"
