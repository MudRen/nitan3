#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��������");
        set("long", @LONG
һ��ľ�ƽṹ�����ȣ����汻������һ����Ⱦ�����ǹ⻬��������Ѿ�ߺ���
�˴��������С����������ݵ��鷿�����������ݸ��ĺ�Ժ��
LONG );

	set("exits", ([
		"east" : "/d/beijing/aofu_houyuan",
		"west" : "/d/beijing/aofu_shufang",
	]));
	set("objects", ([
		"/d/beijing/npc/jiading_a" : 1,
		"/d/beijing/npc/yahuan_a" : 1,
	]));
	set("coor/x", -60);
	set("coor/y", 380);
	set("coor/z", 0);
	setup();
}