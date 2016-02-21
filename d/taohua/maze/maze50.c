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
		"east"  : __DIR__"maze64",
		"south" : __DIR__"maze32",
		"west"  : __DIR__"maze21",
		"north" : __DIR__"maze28",
	]));

	set("item_desc", ([
	        "shibei" : "
��������Ԫ�����ࡣ
��������������ֺ�������񣬵�������ӣ��޾̡�
�����Ŷ�������ʵ���ҳ��м��������ܼ�������
��������������������������಻ʳ��������ڣ��ռ���
�������ģ������㣬�������������ף��ס�
�������壺���ƶ����磬���ꡣ
�����Ͼţ������磬�󼪣��޲�����
��  �� � �� ��  
\n",
	]));

	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 50);
	check_count(me, 50);
	return;
}
