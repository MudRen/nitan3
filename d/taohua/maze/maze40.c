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
		"east"  : __DIR__"maze55",
		"south" : __DIR__"maze59",
		"west"  : __DIR__"maze32",
		"north" : __DIR__"maze64",
	]));

	set("item_desc", ([
	        "shibei" : "
�����⣺�����ϣ������������������� ������������
�����������޾̡�
�����Ŷ�������������û�ʸ���꼪��
�������������ҳˣ��¿��������ߡ�
�������ģ����Ĵ������˹�ڡ�
�������壺����ά�н⣬����������С�ˡ�
���������������������ڸ�ܭ֮�ϣ���֮���޲�����
\n",
	]));

	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 40);
	check_count(me, 40);
	return;
}
