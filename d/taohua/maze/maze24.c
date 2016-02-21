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
		"east"  : __DIR__"maze46",
		"west"  : __DIR__"maze19",
		"north" : __DIR__"maze27",
	]));

	set("item_desc", ([
	        "shibei" : "
���������ࡣ �����޼��������޾̡� �����������������������������
�������ţ�����Զ����ֻ�ڣ�Ԫ����
�����������ݸ�������
����������Ƶ�������޾̡�
�������ģ����ж�����
�������壺�ظ����޻ڡ�
    �������Ը����ף�����������ʦ�����д�ܣ�����������ף�����
          ʮ�꣬��������
\n",
	]));

	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 24);
	check_count(me, 24);
	return;
}
