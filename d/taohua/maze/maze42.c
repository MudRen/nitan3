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
		"east"  : __DIR__"maze57",
		"south" : __DIR__"maze3",
		"west"  : __DIR__"maze61",
		"north" : __DIR__"maze51",
	]));

	set("item_desc", ([
	        "shibei" : "
�����棺��������������󴨡�
�������ţ�����Ϊ������Ԫ�����޾̡�
��������������֮��ʮ��֮�긥��Υ�����꼪�� �������ڵۣ�����
������������֮�����£��޾̡� �������У��湫�ù硣
�������ģ����У��湫�ӡ� ����Ϊ��Ǩ����
�������壺���ڻ��ģ�����Ԫ���� ���ڻ��ҵ¡�
�����Ͼţ�Ī��֮�����֮��������㣬�ס�
\n",
	]));

	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 42);
	check_count(me, 42);
	return;
}
