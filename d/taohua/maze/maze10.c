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
		"east"  : __DIR__"maze25",
		"south" : __DIR__"maze58",
		"west"  : __DIR__"maze33",
	]));

	set("item_desc", ([
	        "shibei" : "
�����ģ��Ļ�β���������ˣ��ࡣ
�������ţ����ģ����޾̡�
�����Ŷ����ĵ�̹̹�������꼪��
���������������ӣ������ģ��Ļ�β�������ˣ��ס� ����Ϊ�ڴ����
�������ģ��Ļ�β�����ڡ����ռ���
�������壺�����ģ�������
�����Ͼţ����Ŀ��飬����Ԫ����
����  �� �� �� ��
���� �� ��˷ �� ����
����  �� Ȳ �� �� 
\n",
	]));

	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 10);
	check_count(me, 10);
	return;
}
