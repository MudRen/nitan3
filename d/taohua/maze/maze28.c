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
		"east"  : __DIR__"maze47",
		"south" : __DIR__"maze50",
		"west"  : __DIR__"maze17",
		"north" : __DIR__"maze44",
	]));

	set("item_desc", ([
	        "shibei" : "
  ����������㣬�����������ࡣ
�������������ð�é���޾̡�
�����Ŷ��������������Ϸ����Ů�ޣ��޲�����
�������������㣬�ס�
�������ģ���¡�����������ߡ�
�������壺�����������ϸ���ʿ���޾�������
���������������𶥣��ף��޾̡�
���� �� �� �� ��
\n",
	]));

	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 28);
	check_count(me, 28);
	return;
}
