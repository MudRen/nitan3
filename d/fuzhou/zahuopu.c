inherit ROOM;

void create()
{
	set("short", "杂货铺");
	set("long", @LONG
这里是一间颇为陈旧的铺面，柜台上面奚奚落落摆放着些
女人专用的杂货。
LONG);
	set("exits", ([
		"east" : __DIR__"xiangyang",
	]));
	set("objects", ([
		__DIR__"npc/chen" : 1,
	]) );
	set("coor/x", 120);
	set("coor/y", -130);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

