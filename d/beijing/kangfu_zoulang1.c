#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��������");
        set("long", @LONG
����һ��ľ�Ƶ����ȣ�������ǹ⻬����������һ����Ⱦ����������������
�ڴ��߶����ϱ��ǿ����Ĵ�Ժ���������ǿ����Ĵ����ˡ�
LONG );
       set("exits", ([
		"north" : "/d/beijing/kangfu_dating",
		"south" : "/d/beijing/kangfu_dayuan",
	]));
	set("objects", ([
		"/d/beijing/npc/jiading_k" : 1,
		"/d/beijing/npc/shizhe" : 1,
	]));
	set("outdoors", "beijing");
	set("coor/x", -30);
	set("coor/y", 290);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}