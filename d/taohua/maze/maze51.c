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
		"east"  : __DIR__"maze32",
		"south" : __DIR__"maze42",
		"west"  : __DIR__"maze54",
		"north" : __DIR__"maze21",
	]));

	set("item_desc", ([
	        "shibei" : "
�����𣺺ࡣ �������١��٣�Ц�����ơ� �𾪰����ɥذ�ˡ�
�������ţ��������١��٣���Ц�����ƣ�����
��������������������ɥ�������ھ��꣬�������յá�
���������������գ���������
�������ģ������ࡣ
�������壺��������������ɥ�����¡�
�����������������������ǣ����ס� �����乪�������ڣ��޾̡� ����
          ���ԡ�
���� �� ����С ����Ի ����С �һ�
\n",
	]));

	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 51);
	check_count(me, 51);
	return;
}
