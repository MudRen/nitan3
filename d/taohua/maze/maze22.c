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
		"south" : __DIR__"maze36",
		"west"  : __DIR__"maze4",
		"north" : __DIR__"maze63",
	]));

	set("item_desc", ([
	        "shibei" : "
�����ڣ��ࡣ С����������
�������ţ�����ֺ���ᳵ��ͽ��
���������������롣
����������������磬���꼪��
�������ģ�������磬�����磬�˿ܻ��š�
�������壺������԰�������ꧣ��ߣ��ռ���
�����Ͼţ����ڣ��޾̡�
\n",
	]));

	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 22);
	check_count(me, 22);
	return;
}
