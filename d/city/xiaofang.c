// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "С��");
        set("long",
"����һ���ǳ���ª�ķ��ӣ�һ��һ�������Ϲ���ɴ�ʣ�ǽ�Ϲ���һ��\n"
"�������ҵĻ�(picture),����������\n"
        );
        set("exits", ([
                "east" : "/d/zhongzhou/yangzhoudu",
        ]));

        set("objects", ([
                __DIR__"npc/guisan" : 1,
        ]));
        set("item_desc", ([
                "picture" : "�������������\n",
        ]));

        set("no_clean_up", 0);

	set("coor/x", -20);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "enter") 
        {
                say (me->name() + "�߽������������ְѰ��Ź�������\n");
                me->set_temp("new_valid_dest", "/d/city/didao");
                me->move("/d/city/didao");
                delete("exits/enter");
                me->set_temp("search", 0);
        }
        return ::valid_leave(me, dir);
}
