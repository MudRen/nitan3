// Room: /d/fuzhou/wuxiang.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
һ��СС���á�
LONG );
	set("exits", ([
                "south" : __DIR__"shulin",
	]));
	set("outdoors", "fuzhou");
	set("coor/x", 190);
	set("coor/y", -100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

