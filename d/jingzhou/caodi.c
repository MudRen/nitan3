// Room: /d/xiangyang/caodi1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "�ݵ�");
	set("long", @LONG
���Ǿ��ݳ���Ĳݵء�
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
                "south"  : __DIR__"guandao3",
	]));
	set("objects", ([
                "/d/jingzhou/npc/obj/juhua" : 1,
	]));
	set("coor/x", -420);
	set("coor/y", -190);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

