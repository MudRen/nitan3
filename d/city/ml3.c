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
		"west" : "/d/city/ml4",
		"south" : "/d/city/dongmen",
		"north" : __FILE__,
	]));
	set("outdoors", "city");
	set("coor/x", 50);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}