#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��������");
        set("long", @LONG
һ��ľ�ƽṹ�����ȣ����汻������һ����Ⱦ�����ǹ⻬��������Ѿ�ߺ���
�˴��������С��ϱ��������Ĵ��ţ�������һ����԰��
LONG );

	set("exits", ([
		"north" : "/d/beijing/aofu_dayuan",
		"south" : "/d/beijing/aofu_men",
	]));
	set("objects", ([
		"/d/beijing/npc/yahuan_a" : 1,
	]));
	set("coor/x", -50);
	set("coor/y", 340);
	set("coor/z", 0);
	setup();
}