// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

inherit ROOM;

void create()
{
	set("short", "��ҩʦ�Ӵ�");
	set("long", @LONG
�����һ�������ҩʦ�����ң�һ����齿����ݶ����ǣ���ǰһ������
��һ�����٣�һ�����ס�������ɫ���ɣ���β����ȫ�ս������������һ
��ֽ�����Կ���һЩ�ּ���������ȥ���������Կ���һ�����㡣
LONG );
	set("objects", ([
		// __DIR__"obj/paper2"       : 1,
		CLASS_D("taohua") + "/huang" : 1,
                "/d/taohua/npc/shitong" : 2,
	]));
	 set("exits", ([
                "south" : __DIR__"wofang",
                "east" : __DIR__"changlang2",
        ]));
        
	setup();
         "/clone/board/taohua_b"->foo();
}
int valid_leave(object me, string dir)
{
        object guarder;

        if (! objectp(guarder = present("huang yaoshi", this_object())))
        {
                return 1;
        }

        if (dir == "south")
                return guarder->permit_pass(me, dir);

        return 1;
}

