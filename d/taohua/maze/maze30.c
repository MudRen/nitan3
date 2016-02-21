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
		"south" : __DIR__"maze55",
		"west"  : __DIR__"maze64",
		"north" : __DIR__"maze49",
	]));

	set("item_desc", ([
	        "shibei" : "
�����룺���꣬�ࡣ ����ţ������
�������ţ��Ĵ�Ȼ����֮�޾̡�
�������������룬Ԫ����
�������������֮�룬�������裬�����֮ൣ��ס�
�������ģ�ͻ�������磬���磬���磬���硣
�������壺���������������������
�����Ͼţ����ó������м����ף�����˳��޾̡�
\n",
	]));

	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 30);
	check_count(me, 30);
	return;
}
