// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

inherit ROOM;

#include "maze.h"

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
����һ����ԼĪ���˶�ߵĴ�ʯ�鹹�ɵ���ʯ�󣬹�ģ�ƺ����󣬵�
̧����ȥ�����ܾ������ص�������Ᾱ�ʯ����ȫ��������·ͨ��ʯ��֮�⣬
��֮���г�������������������������ͷ����ʯ������һ��б����ʯ��(s
hibei)�������ڸ����С�
LONG );

	set("exits", ([
		"east"  : __DIR__"maze10",
		"south" : __DIR__"maze31",
		"west"  : __DIR__"maze12",
	]));

	set("item_desc", ([
	        "shibei" : "
���������࣬С���ꡣ
������������β������������������
����������ִ֮�û�ţ֮�Ī֮ʤ˵��
����������ϵ�����м�������檼���
�������ģ��á����Ӽ���С�˷�
�������壺�Ρ����꼪��
�����Ͼţ��ʡ����޲�����
�� ��  �� �� ؼ �� �� 
\n",
	]));

	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 33);
	check_count(me, 33);
	return;
}
