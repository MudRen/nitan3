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
		"north" : "/d/city/ml3",
	]));
	set("outdoors", "city");
	set("coor/x", 50);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}