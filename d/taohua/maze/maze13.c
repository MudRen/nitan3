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
		"south" : __DIR__"maze49",
		"west"  : __DIR__"maze6",
	]));

	set("item_desc", ([
	        "shibei" : "
����ͬ�ˣ�ͬ����Ұ���ࡣ ����󴨣��������ꡣ
�������ţ�ͬ�����ţ��޾̡�
����������ͬ�����ڣ��ߡ�
����������������ç��������꣬���겻�ˡ�
�������ģ�����ܭ�����˹�������
�������壺ͬ�ˣ��Ⱥ�������Ц�� ��ʦ��������
�����Ͼţ�ͬ���ڽ����޻ڡ�
\n",
	]));

	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 13);
	check_count(me, 13);
	return;
}
