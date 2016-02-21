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
		"east"  : __DIR__"maze45",
		"south" : __DIR__"maze14",
		"north" : __DIR__"maze1",
	]));

	set("item_desc", ([
	        "shibei" : "
�������٣�������ͥ���ںţ������������أ��������֣�����������
�������ţ�׳��ǰֺ������ʤΪ�ߡ�
�����Ŷ�����ţ�Īҹ���֣�������
����������׳�ڡ��ڣ����ס� ���ӡ��١��٣��������꣬�����㳣��޾̡�
�������ģ����޷������д��ҡ� ǣ����������Բ��š�
�������壺��½���١��٣������޾̡�
�����������޺ţ������ס�
���� �� Ȳ �� ��
���� �� �� �� ҳ
\n",
	]));

	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 43);
	check_count(me, 43);
	return;
}
