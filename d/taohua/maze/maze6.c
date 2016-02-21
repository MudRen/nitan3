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
		"east"  : __DIR__"maze13",
		"south" : __DIR__"maze47",
		"west"  : __DIR__"maze44",
	]));

	set("item_desc", ([
	        "shibei" : "
�����ϣ����ڣ��ϡ� ���м��� ���ס� �������ˣ�������󴨡�
�����������������£�С���ԣ��ռ���
�����Ŷ��������ϣ�����ͣ����������ٻ�������
����������ʳ�ɵ£��������ռ���������£��޳ɡ�
�������ģ������ϣ����������尲�꣬����
�������壺��Ԫ����
�����Ͼţ�����֮�������ճ�����֮��

��  �� �ϰ� �¸�
\n",
	]));

	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 6);
	check_count(me, 6);
	return;
}
