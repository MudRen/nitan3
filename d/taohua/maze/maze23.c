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
		"east"  : __DIR__"maze52",
		"south" : __DIR__"maze2",
		"west"  : __DIR__"maze26",
		"north" : __DIR__"maze8",
	]));

	set("item_desc", ([
	        "shibei" : "
��������������������
�����������������㣬�����ס�
���������������Ա棬�����ס�
������������֮���޾̡�
�������ģ������Է����ס�
�������壺���㣬�Թ��˳裬�޲�����
�����Ͼţ�˶����ʳ�����ӵ��ߣ�С�˰�®��
��  �� �� �� ľ
\n",
	]));

	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 23);
	check_count(me, 23);
	return;
}
