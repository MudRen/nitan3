#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����������������Ҳ�Ǿ�����ķ����ضΡ�����������ʮ�����֡����ϱ�
������һ���������������Ǿ��ǵĳ�����֡�������һ�����У�����ר��Ϊ����
����Ĺ��Ӹ������ġ����߲�Զ��������������ˡ�
LONG );
       set("exits", ([
		"east" : "/d/beijing/xi_2",
		"west" : "/d/beijing/niaoshi",
		"north" : "/d/beijing/bei_1",
		"south" : "/d/beijing/caroad_w1",
	]));
	set("objects", ([
		"/d/beijing/npc/boy1" : 1,
		"/d/beijing/npc/tiaofu" : 1,
	]));
	set("outdoors", "beijing");
	set("coor/x", -60);
	set("coor/y", 270);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
