// Room: /city/bingqiku.c
// YZC 1995/12/04 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����Ǳ����⣬�������������������ۻ����ҡ��������������𹿰�����
�����������ڰ����̵����̽����̹�����ɫ�����ı���Ӧ�о��У���һʱ��֪
����ʲô�á�
LONG );
	set("exits", ([
		"north" : "/d/city/bingyin",
	]));
	set("no_clean_up", 0);
	create_door("north", "����", "south", DOOR_CLOSED);
	set("coor/x", -10);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
