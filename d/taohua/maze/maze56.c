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
		"east"  : __DIR__"maze38",
		"south" : __DIR__"maze62",
		"west"  : __DIR__"maze35",
		"north" : __DIR__"maze31",
	]));

	set("item_desc", ([
	        "shibei" : "
�����ã�С�࣬���꼪��
������������������˹����ȡ�֡�
�����������ü��Σ������ʣ���ͯ���ꡣ
�����������÷���Σ�ɥ��ͯ�ͣ�������
�������ģ����ڴ��������ʸ������Ĳ��졣
�������壺����һʸ��������������
�����Ͼţ�����䳲��������Ц������� ɥţ���ף��ס�
\n",
	]));

	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 56);
	check_count(me, 56);
	return;
}
