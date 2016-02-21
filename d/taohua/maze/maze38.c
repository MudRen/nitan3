// Copyright (C) 2003, by Slough1 group. All rights reserved.
// This software can not be used, copied, or modified in any
// form without the written permission from authors.

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
		"east"  : __DIR__"maze21",
		"south" : __DIR__"maze54",
		"west"  : __DIR__"maze56",
		"north" : __DIR__"maze58",
	]));

	set("item_desc", ([
	        "shibei" : "
�����С�¼���
�������ţ�������ɥ�������Ը����������޾̡�
�����Ŷ�����������޾̡�
��������������ҷ����ţ�������������棬�޳����ա�
�������ģ�£���Ԫ�򣬽��ڣ����޾̡�
�������壺�����������ɷ������ξ̡�
�����Ͼţ�£� ������Ϳ���ع�һ���� ����֮������˵֮�����˿ܻ�
          �ţ��������򼪡�
\n",
	]));

	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 38);
	check_count(me, 38);
	return;
}
