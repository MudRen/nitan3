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
		"south" : __DIR__"maze22",
		"west"  : __DIR__"maze29",
		"north" : __DIR__"maze37",
	]));

	set("item_desc", ([
	        "shibei" : "
�����ȼã��࣬С���꣬�������ҡ�
�������ţ�ҷ���֣����β���޾̡�
������������ɥ����٣��������յá�
�������������ڷ����������֮��С�����á�
�������ģ��������¡��ۣ����ս䡣
�������壺����ɱţ����������֮���ܼ���ʵ���丣��
��������������ף�����
���� �� ���� �¸�
���� �� �� �� ��
���� �� �� �� ��
���� �� �� �� ��
\n",
	]));

	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 63);
	check_count(me, 63);
	return;
}
