#include <room.h>
inherit ROOM;

void create()
{
	set("short", "Τ������");
        set("long", @LONG
����һ��ľ�Ƶ����ȣ�������ǹ⻬����������һ����Ⱦ������Τ��������
�ڴ��߶��������Ǹ��޴�Ļ�԰��
LONG );
       set("exits", ([
		"north" : "/d/beijing/weifu_dayuan",
		"east" : "/d/beijing/weifu_men",
	]));
	set("objects", ([
		"/d/beijing/npc/shizhe" : 1,
	]));
	set("outdoors", "beijing");
	set("coor/x", -30);
	set("coor/y", 270);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
