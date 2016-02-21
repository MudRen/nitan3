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
		"east"  : __DIR__"maze56",
		"south" : __DIR__"maze16",
		"west"  : __DIR__"maze14",
		"north" : __DIR__"maze45",
	]));

	set("item_desc", ([
	        "shibei" : "
������������������ެ�����������ӡ�
�������������磬���磬�꼪�� ���ڣ�ԣ�޾̡�
�������������磬���磬�꼪�� ���Ƚ鸣��������ĸ��
�������������ʣ�������
�������ģ�����˶��������
�������壺������ʧ�������������޲�����
�����Ͼţ�����ǣ�ά�÷��أ������޾̣����ߡ�
\n",
	]));
	
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 35);
	check_count(me, 35);
	return;
}