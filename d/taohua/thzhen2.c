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

string* dirs2 = ({
        "e", "se", "se", "sw", "ne", "ne",
        "w", "s", "s", "nw", "n", "n",
});

void create()
{

	set("short", "桃花林");
	set("long", @LONG
这桃林似乎无穷无尽一般，其中小径更却是纵横交错，匪夷所思。你
拼命想离开原地，但几个转折又回到了原地。一连几次，似乎只是在同一
个地方兜圈子。
LONG );

        set("exits", ([
		"east"      : __DIR__"thzhen2",
		"south"     : __DIR__"thzhen2",
		"west"      : __DIR__"thzhen2",
		"north"     : __DIR__"thzhen2",
		"northeast" : __DIR__"thzhen2",
		"southeast" : __DIR__"thzhen2",
		"southwest" : __DIR__"thzhen2",
		"northwest" : __DIR__"thzhen2",
        ]));

	set("outdoors", "taohua");

	setup();

}

void init()
{
        this_player()->set_temp("die_reason", "误入桃花迷阵被桃花瓣射死");
        this_player()->receive_damage("qi", 15);
        this_player()->receive_wound("qi",  15);
        message_vision(HIR "突然一阵桃花瓣象雨点般疾射$N！\n" NOR, this_player());
}

int valid_leave(object me, string dir)
{
	mixed local;
  	int   count, gain;
  	mapping myfam;

	myfam = (mapping)me->query("family");

  	local = localtime(time()*60);

  	count = ((local[LT_HOUR] + 1) % 24) / 2;
  	gain = random((me->query_skill("qimen-wuxing", 1)) / 30) + 1;
  	if (dirs[count] == dir || dirs2[count] == dir) 
  	{
        	me->move("/d/taohua/thzhen3");
        	if (! myfam || myfam["family_name"] == "桃花岛") 
        	{
                        if (count_lt(me->query("combat_exp"), 20000+  random(10000))) 
			{ 
            		        me->add("combat_exp", gain);
          		}
        	}

        	me->start_busy(random(3));
                // return notify_fail("\n");
                return 1;
  	}
  	return ::valid_leave(me, dir);
}


