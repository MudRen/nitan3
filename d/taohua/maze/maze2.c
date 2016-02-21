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
		"east"  : __DIR__"maze15",
		"west"  : __DIR__"maze11",
		"north" : __DIR__"maze23",
	]));

	set("item_desc", ([
	        "shibei" : "
��������Ԫ���࣬������֮�ꡣ ���������������Ժ�����������ϵ���
      ����ɥ�� ���꣬����
������������˪���������
����������ֱ�������󣬲�ϰ�޲�����
�������������¿��ꡣ ������£��޳����ա�
�������ģ����ң��޾̣�������
�������壺���ѣ�Ԫ����
����������ս���Ұ����Ѫ���ơ�
���������������ꡣ
\n",
	]));

	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 2);
	check_count(me, 2);
	return;
}
