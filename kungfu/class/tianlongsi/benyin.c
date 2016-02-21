// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// benyin.c

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
        set_name("����", ({ "ben yin","yin"}) );
        set("gender", "����" );
        set("title", "�����µ�ʮ�ߴ�ס��");
        set("long", "һ������������ɮ�ˣ�����������ס�ַ��ɡ�\n");
        set("class", "bonze");
        set("age", 43);
        set("shen_type", 1);
        set("str", 22);
        set("int", 32);
        set("con", 26);
        set("dex", 24);

        set("qi", 3300);
        set("max_qi", 3300);
        set("jing", 1600);
        set("max_jing", 1600);
        set("neili", 4200);
        set("max_neili", 4200);
        set("jiali", 40);
        set("level", 20);
        set("combat_exp", 1200000);

        set_skill("force", 220);
        set_skill("dodge", 220);
        set_skill("parry", 220);
        set_skill("finger", 225);
        set_skill("sword", 200);
        set_skill("tiannan-bufa", 220);
        set_skill("kurong-changong", 220);
        set_skill("duanjia-jian", 200);
        set_skill("sun-finger", 225);
        set_skill("buddhism", 180);
        set_skill("literate", 120);
        set_skill("martial-cognize", 200); 

        map_skill("force", "kurong-changong");
        map_skill("dodge", "tiannan-bufa");
        map_skill("parry", "sun-finger");
        map_skill("finger", "sun-finger");
        map_skill("sword", "duanjia-jian");
        prepare_skill("finger","sun-finger");
        set("inquiry" ,([
                "������"     : (: ask_me() :),
                "��������" : "�ߣ�\n",
                "������"   :  "�ߣ�\n",
        ]));

        create_family("����μ�", 15, "��ɮ");
        setup();
        carry_object("/d/xueshan/obj/b-jiasha")->wear();
}

string ask_me()
{
	object me = this_player();
	
        if (me->query_temp("marks/ask_temp0"))
        {
		me->set_temp("marks/ask_temp1", 1);
		return "�����Ǳ��µ�����֮����������ǰ������ʧ��ʩ�������һش��\n         ���ı�����л����\n";
        }
	else
		return "��ʩ���������ԡ���\n";
}

int accept_object(object who, object ob)
{
        if ((string)ob->query("id") == "jin he")
	{
		message_vision("�����ϲ��������лʩ����ʩ��������Ե�ˣ��뵽Ĳ����ȡ����֮����\n", who);
		who->set_temp("marks/find_temp", 1);
		who->move("/d/tianlongsi/banruotai");
		return 1;
	}
	return 0;
}

#include "ben.h"

