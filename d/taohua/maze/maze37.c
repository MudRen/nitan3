// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from the
// Slough develop group

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
		"south" : __DIR__"maze63",
		"west"  : __DIR__"maze59",
		"north" : __DIR__"maze55",
	]));

	set("item_desc", ([
	        "shibei" : "
�������ˣ���Ů�ꡣ
�������ţ����мң�������
���������������죬���������꼪��
�������������ˡ��������������������������ߡ�
�������ģ����ң��󼪡�
�������壺�����мң���������
�����Ͼţ��������磬�ռ���
��  �� �� �� ��
\n",
	]));

	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 37);
	check_count(me, 37);
	return;
}
