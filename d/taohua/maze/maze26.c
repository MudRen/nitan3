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
		"east"  : __DIR__"maze23",
		"south" : __DIR__"maze11",
		"north" : __DIR__"maze5",
	]));

	set("item_desc", ([
	        "shibei" : "
    �������꣬����ʳ��������󴨡�
�������ţ��������ѡ�
�����Ŷ�����˵����
���������������������ꡣ Ի������������������
�������ģ�ͯ��֮����Ԫ����
�������壺����֮��������
�����Ͼţ�����֮�飬�ࡣ
��  �� �� �� ��

\n",
	]));
	
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 26);
	check_count(me, 26);
	return;
}
