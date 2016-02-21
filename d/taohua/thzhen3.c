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

	set("short", "�һ���");
        set("long", @LONG
�����˼�������Ȼ�뵽����������ˣ�������ԭ�ؾ������䣬�����
���վ����Ǹ��˾֡�˵Ҳ��֣���ʼ���������Ҳ�벻��ԭ�أ���������
·��ȥ��ȴ�����Լ���ԭ�غ���Խ��ԽԶ�ˡ�
LONG );

                set("exits", ([
                "east" : __DIR__"thzhen3",
                "south" : __DIR__"thzhen3",
                "west" : __DIR__"thzhen3",
                "north" : __DIR__"thzhen3",
                "northeast" : __DIR__"thzhen3",
                "southeast" : __DIR__"thzhen3",
                "southwest" : __DIR__"thzhen3",
                "northwest" : __DIR__"thzhen3",
                ])); 
	
	set("cost", 25);
	set("outdoors", "taohua");

	setup();
     
}

int valid_leave(object me, string dir)
{
  mixed local;
  int count,gain;
  mapping myfam;

  myfam = (mapping)me->query("family");

  local = localtime(time()*60);

  count = ((local[LT_HOUR]+1)%24)/2;
  gain = random((me->query_skill("qimen-wuxing", 1)) / 30) + 1;
  if (dirs[count] == dir || dirs2[count] == dir) {
        me->move("/d/taohua/xiaojing");
        if (!myfam || myfam["family_name"] == "�һ���") {
                if (count_lt(me->query("combat_exp"), 20000+random(10000))) {
            		me->add("combat_exp", gain);
                        if (count_lt(me->query("potential"), me->query("max_potential")))
	    		me->add("potential", gain);
		} 
	}

	me->start_busy(random(3));
        return notify_fail("\n");
  }
  return ::valid_leave(me,dir);
}
