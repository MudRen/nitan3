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
		"east"  : __DIR__"maze51",
		"south" : __DIR__"maze61",
		"west"  : __DIR__"maze62",
		"north" : __DIR__"maze38",
	]));

	set("item_desc", ([
	        "shibei" : "
�������ã����ף���������
�������ţ�������淣������ģ�������
�����Ŷ��������ӣ�������֮�ꡣ
�����������������룬������淡�
�������ģ�������ڣ��ٹ���ʱ��
�������壺���ҹ��ã����֮�ǣ��������֮�������¼���������
����������Ů�п���ʵ��ʿ������Ѫ����������
��  �� �� �� ��
\n",
	]));

	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 54);
	check_count(me, 54);
	return;
}
