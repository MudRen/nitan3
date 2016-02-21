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
		"east"  : __DIR__"maze61",
		"south" : __DIR__"maze39",
		"west"  : __DIR__"maze20",
		"north" : __DIR__"maze62",
	]));

	set("item_desc", ([
	        "shibei" : "
��������Ů�鼪�����ꡣ
�����������轥�ڸɣ�С���������ԣ��޾̡�
�����������轥���ͣ���ʳ����������
�����������轥��½���������������в������ף������ܡ�
�������ģ��轥��ľ������������޾̡�
�������壺�轥���꣬�����겻�У���Ī֮ʤ������
�����Ͼţ��轥���ӣ��������Ϊ�ǣ�����
��  �� �� �� �� �� ء
\n",
	]));

	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 53);
	check_count(me, 53);
	return;
}
