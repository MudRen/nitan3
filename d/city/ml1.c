// Room: /city/milin.c

#include <room.h>
inherit BUNCH_ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һƬï�ܵ������֣�һ�߽�������·���ʧ�˷���
LONG );
	set("exits", ([
		"east" : "/d/city/ml2",
		"west" : __FILE__,
		"south" : "/d/city/dongmen",
		"north" : __FILE__,
	]));
	set("outdoors", "city");
	set("coor/x", 40);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
}