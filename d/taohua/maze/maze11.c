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
		"east"  : __DIR__"maze2",
		"north" : __DIR__"maze26",
	]));

	set("item_desc", ([
	        "shibei" : "
����̩��С�����������ࡣ
�������ţ���é�㣬����⹣�������
�����Ŷ������ģ��÷�ӣ������ţ����������������С�
������������ƽ���飬���������������޾̡� �������ڣ���ʳ�и���
�������ģ����治���������ڣ��������ڡ�
�������壺���ҹ��ã�����Ԫ����
�����������Ǹ���������ʦ�� ���ظ��������ߡ�
\n",
	]));

	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 11);
	check_count(me, 11);
	return;
}
