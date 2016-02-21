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
		"east"  : __DIR__"maze31",
		"south" : __DIR__"maze35",
		"west"  : __DIR__"maze43",
		"north" : __DIR__"maze12",
	]));

	set("item_desc", ([
	        "shibei" : "
�����ͣ��ࡣ ���������������ˣ��࣬���ꡣ �ô�����������������
�������������ڲ��գ��������ͣ�����һ��ΪЦ�����������޾̡�
�����������������޾̣��������á��١�
�������������磬��磬�����������޾̣�С�ߡ�
�������ģ��󼪣��޾̡�
�������壺����λ���޾̡� ���ڣ�Ԫ���꣬������
��������������������ۣ��޾̡�
���� �� �� �� ��
���� �� ������ �� �°벿 د��ح ���һ����
���� �� �� �� ��
\n",
	]));

	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 45);
	check_count(me, 45);
	return;
}
