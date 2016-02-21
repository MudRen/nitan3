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
		"east"  : __DIR__"maze59",
		"south" : __DIR__"maze48",
		"west"  : __DIR__"maze42",
		"north" : __DIR__"maze32",
	]));

	set("item_desc", ([
	        "shibei" : "
�����㣺С�࣬���������������ˡ�
�������������ˣ�������֮�ꡣ
�����Ŷ������ڡ��£���ʷ�׷��������޾̡�
����������Ƶ�㣬�ߡ�
�������ģ������������Ʒ��
�������壺�꼪�������޲����� �޳����գ��ȸ����գ�������գ�����
�����Ͼţ����ڡ��£�ɥ���ʸ������ס�
��  �� �� �� ľ
\n",
	]));
	
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 57);
	check_count(me, 57);
	return;
}
