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
		"west"  : __DIR__"maze7",
		"north" : __DIR__"maze22",
	]));

	set("item_desc", ([
	        "shibei" : "
�������ģ������ꡣ
�������ţ������ڷɣ������� �������У����ղ�ʳ�� ��������������
          �ԡ�
�������������ģ�������ɣ�������׳������
����������������������������ף����ɼ��ꡣ
�������ģ������󸹣�������֮�ģ�������ͥ��
�������壺����֮���ģ����ꡣ
���������������ޣ��������죬�����ڵء�
\n",
	]));

	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 36);
	check_count(me, 36);
	return;
}
