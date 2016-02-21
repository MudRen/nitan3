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
		"south" : __DIR__"maze37",
		"west"  : __DIR__"maze40",
		"north" : __DIR__"maze30",
	]));

	set("item_desc", ([
	        "shibei" : "
�����᣺�࣬����֮�����ǣ������С�
�������ţ�������������Ѯ�޾̣������С�
����������������٣����м����������ɼ������ڷ���������
���������������棬���м������������ţ��޾̡�
�������ģ�������٣����м�������������������
�������壺���£�������������
���������������ݣ�������ң����仧�����������ˣ����겻�����ס�
���� �� ��ܳ �²�
���� �� ���� �ڳ�  �ֵ����?
\n",
	]));

	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 55);
	check_count(me, 55);
	return;
}
