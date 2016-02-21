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
		"east"  : __DIR__"maze63",
		"south" : __DIR__"maze4",
		"west"  : __DIR__"maze48",
		"north" : __DIR__"maze59",
	]));

	set("item_desc", ([
	        "shibei" : "
��������ϰ�������ڣ�ά�ĺ࣬�����С�
����������ϰ�������ڿ����ڣ��ס�
�����Ŷ��������գ���С�á�
������������֮���������������ڿ����ڣ����á�
�������ģ��׾���������󾣬��Լ��뻣����޾̡�
�������壺����ӯ��ֻ��ƽ���޾̡�
 �� ���������ûա��ۣ����ڴԼ������겻�ã��ס�
���� �� ��Ѩ �� ���� �� ��
���� �� �� �� ī
\n",
	]));

	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 29);
	check_count(me, 29);
	return;
}
