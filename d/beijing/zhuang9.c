#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "С����");
        set("long", @LONG
����һ��С���䣬���ϵ������򡣷���ֻ��һ��һ��������򵥣�ȴʮ�ָ�
�����������ű��졣
LONG );
    set("exits", ([
		"south" : "/d/beijing/zhuang8",
    ]));
    set("objects", ([
	"/d/beijing/npc/furen": 1,
          "/d/beijing/npc/shuanger": 1,
    ]));
    set("outdoors", "beijing");
    setup();
    replace_program(ROOM); 
}
