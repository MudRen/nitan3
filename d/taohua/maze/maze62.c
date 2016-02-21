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
		"east"  : __DIR__"maze54",
		"south" : __DIR__"maze53",
		"west"  : __DIR__"maze16",
		"north" : __DIR__"maze56",
	]));

	set("item_desc", ([
	        "shibei" : "
����С�����࣬���꣬��С�£����ɴ��¡�������֮�������������£���
          ����
�����������������ס�
���������������棬��������������������䳼���޾̡�
����������������֮���ӻ���֮���ס�
�������ģ��޾̣�������֮�� �����ؽ䣬�������ꡣ
�������壺���Ʋ��꣬������������߮ȡ����Ѩ��
����������������֮��������֮���ף���ν����
\n",
	]));

	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 62);
	check_count(me, 62);
	return;
}
