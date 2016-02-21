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
		"east"  : __DIR__"maze18",
		"south" : __DIR__"maze24",
		"west"  : __DIR__"maze41",
		"north" : __DIR__"maze3",
	]));

	set("item_desc", ([
	        "shibei" : "
�����ã��꼪�� ���ã������ʵ��
�������ţ������꣬���Ҷ��ã��ס�
�������������ã������������ã����ס�
�������������ã����ף�ʮ�����ã���������
�������ģ����ü��������������������޾̡�
�������壺���������꼪��������󴨡�
 �� �Ͼţ����ã�����������󴨡�
\n",
	]));

	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 27);
	check_count(me, 27);
	return;
}
