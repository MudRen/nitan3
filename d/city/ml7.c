// Room: /city/milin.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һƬï�ܵ������֣�һ�߽�������·���ʧ�˷���
LONG );
	set("exits", ([
		"east" : __FILE__,
		"west" : __FILE__,
		"south" : "/d/city/dongmen",
		"north" : "/d/city/pomiao",
	]));
	set("outdoors", "city");
	set("coor/x", 40);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}