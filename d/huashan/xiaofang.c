// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

inherit ROOM;

void reset();

void create()
{
    set("short", "Сľ��");
    set("long", @LONG
һ������򵥵�Сľ�ݡ�������һ����¯��ǽ�Ϲ���һ������������
����һλ���ߣ�������Ȼ���أ�ȴ���˲��ɵ�����������
LONG );

    set("exits", ([
	        "out" : __DIR__"xiaojing2",
    ]));

    set("objects", ([
                CLASS_D("huashan") + "/feng" : 1,
    ]));

    set("no_clean_up", 0);
    setup();
    //replace_program(ROOM);
}
