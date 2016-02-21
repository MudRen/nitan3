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
		"east"  : __DIR__"maze60",
		"south" : __DIR__"maze52",
		"west"  : __DIR__"maze8",
		"north" : __DIR__"maze53",
	]));

	set("item_desc", ([
	        "shibei" : "
����忣������ϣ������������������ˣ��꼪��
������������忣�������
���������������忣��˹�֮�ʡ�
�������������������
�������ģ����������
�������壺���������
���������������˶�������������ˡ�
\n",
	]));

	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 39);
	check_count(me, 39);
	return;
}
