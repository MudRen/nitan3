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
		"east"  : __DIR__"maze7",
		"west"  : __DIR__"maze24",
		"north" : __DIR__"maze18",
	]));

	set("item_desc", ([
	        "shibei" : "
��������Ԫ�࣬�ü����ˣ���������������
�����������������󼪡�
�����Ŷ����������á����޾̡�
���������������ء�
�������ģ����ú����ɽ�����޾̡�
�������壺�꼪�����ס�
����������ڤ�������ڲ�Ϣ֮�ꡣ
��  �� �� �� ��
\n",
	]));

	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 46);
	check_count(me, 46);
	return;
}
