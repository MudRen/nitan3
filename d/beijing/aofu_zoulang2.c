#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��������");
        set("long", @LONG
һ��ľ�ƽṹ�����ȣ����汻������һ����Ⱦ�����ǹ⻬��������Ѿ�ߺ���
�˴��������С��ϱ��������Ĵ�����������ͨ�������ĺ�Ժ��
LONG );

	set("exits", ([
		"north" : "/d/beijing/aofu_houyuan",
		"south" : "/d/beijing/aofu_dating",
	]));
	set("objects", ([
		"/d/beijing/npc/jiading_a" : 1,
	]));
	set("coor/x", -50);
	set("coor/y", 370);
	set("coor/z", 0);
	setup();
}