#include <room.h>
inherit ROOM;

void create()
{
	set("short", "������ͬ");
	set("long", @LONG
������������ͬ������ߵ��������Խ���İ�����������խ��ͨ������
���ϵ����ϱ����졣
LONG );
       set("exits", ([
		"north" : "/d/beijing/yangliu1",
		"south" : "/d/beijing/yangliu3",
	]));

	set("outdoors", "beijing");
	set("coor/x", -60);
	set("coor/y", 240);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

