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
		"east"  : __DIR__"maze8",
		"south" : __DIR__"maze26",
		"north" : __DIR__"maze9",
	]));

	set("item_desc", ([
	        "shibei" : "
�����裺���ڣ���࣬�꼪�� ����󴨡�
�������ţ����ڽ��� ���ú㣬�޾̡�
�����Ŷ�������ɳ�� С���ԣ��ռ���
���������������࣬�¿�����
�������ģ�����Ѫ������Ѩ��
�������壺���ھ�ʳ���꼪��
��������������Ѩ���в���֮������������֮�ռ���
\n",
	]));

	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 5);
	check_count(me, 5);
	return;
}
