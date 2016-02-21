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
		"east"  : __DIR__"maze27",
		"south" : __DIR__"maze19",
		"west"  : __DIR__"maze52",
		"north" : __DIR__"maze60",
	]));

	set("item_desc", ([
	        "shibei" : "
���������ڣ�Ԫ�����޾̣����꣬����������  ��֮�ã�����������
�������ţ������������޾̣�����֮��
�����Ŷ������꣬���ף�������֮��
���������������У�����һ�ˣ�һ���У�������ѡ�
�������ģ����伲��ʹ����ϲ���޾̡�
�������壺����֮��ʮ��֮�긥��Υ��Ԫ����
�����Ͼţ�������֮���޾̣��꼪�������������ó��޼ҡ�
\n",
	]));

	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 41);
	check_count(me, 41);
	return;
}
