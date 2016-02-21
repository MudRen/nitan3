// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
inherit ROOM;
#include <localtime.h>

string* dirs = ({
	"east", "southeast", "southeast", "southwest", "northeast", "northeast",
	"west", "south", "south", "northwest", "north", "north",
});


void create()
{

	set("short", "�һ���");
	set("long", @LONG
��һ�߽����֣�������һ���һ�����һ����������ʱĿѣ���ԣ���ʧ
�˷���������и����˳�����ͷһ�ƣ���·���ڻ�������ʧ����Ӱ���٣�
����ֻ��Ӳ��ͷƤ��ǰ���ˡ�
LONG );

        set("exits", ([
		"east"      : __DIR__"thzhen4",
		"south"     : __DIR__"thzhen4",
		"west"      : __DIR__"thzhen4",
		"north"     : __DIR__"thzhen4",
		"northeast" : __DIR__"thzhen6",
		"southeast" : __DIR__"thzhen6",
		"southwest" : __DIR__"thzhen6",
		"northwest" : __DIR__"thzhen6",
        ]));

	set("outdoors", "taohua");

	setup();

}
void init()
{
        this_player()->set_temp("die_reason", "�����һ������һ�������");
        this_player()->receive_damage("qi", 15);
        this_player()->receive_wound("qi",  15);
        message_vision(HIR "ͻȻһ���һ��������㼲��$N��\n" NOR, this_player());
}

int valid_leave(object me, string dir)
{
	mixed local;
  	int   count;
  	mapping myfam;

	myfam = (mapping)me->query("family");

  	local = localtime(time()*60);
  	count = ((local[LT_HOUR] + 1) % 24) / 2;

        if (dirs[count] == dir) 
        {
                me->move("/d/taohua/thzhen5");
  	        me->start_busy(random(3));
                return notify_fail("\n");
        }
        return ::valid_leave(me, dir);
}


