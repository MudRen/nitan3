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
		"east"  : __DIR__"maze12",
		"south" : __DIR__"maze43",
	]));

	set("item_desc", ([
	        "shibei" : "
����Ǭ��Ԫ���࣬�����ꡣ

�������ţ�Ǳ�������á�
�����Ŷ�����������������ˡ�
������������������ǬǬ��Ϧ���������޾̡�
�������ģ���Ծ��Ԩ���޾̡�
�������壺�������죬�������ˡ�
�����Ͼţ������лڡ�
�����þţ���Ⱥ�����ף�����
\n",
	]));

	setup();
}

void init()
{
	object me;
	me = this_player();

	me->add_temp("taohua/count", 1);
	check_count(me,1);
	return;
}
