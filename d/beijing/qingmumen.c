#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��ľ��");
        set("long", @LONG
��δ���š�
LONG );
        set("exits", ([
		"north" : "/d/beijing/yangliu3",
	]));
	replace_program(ROOM);
}

