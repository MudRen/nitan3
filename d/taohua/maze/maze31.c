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
		"east"  : __DIR__"maze58",
		"south" : __DIR__"maze56",
		"west"  : __DIR__"maze45",
		"north" : __DIR__"maze33",
	]));

	set("item_desc", ([
	        "shibei" : "
�����̣��࣬���꣬ȡŮ����
��������������Ĵ��
���������������裬�ף��Ӽ���
��������������ɣ�ִ���棬���ߡ�
�������ģ��꼪����������������Ӷ�˼��
�������壺��������޻ڡ�
�������������丨���գ��ࡣ
��  �� �� �� ÿ
\n",
	]));

	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 31);
	check_count(me, 31);
	return;
}
