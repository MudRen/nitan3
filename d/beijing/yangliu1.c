#include <room.h>
inherit ROOM;

void create()
{
	set("short", "������ͬ");
        set("long", @LONG
������������ͬ�ĺ�ͬ�ڣ��������������ϱ����۵�������ȥ������ʱ�֣�
��ͬ�ڲ�Զ�����ߴ������죬���Ǿ�ס�ż����˼ҡ�ֻ�������������������
��ߺ�����໥���壬������ǹᴩ���ǵĳ�����֡�
LONG );
       set("exits", ([
		"north" : "/d/beijing/caroad_w1",
		"south" : "/d/beijing/yangliu2",
		"west" : "/d/beijing/minju_y",
	]));
	set("objects", ([
		"/d/beijing/npc/old1" : 1,
	]));
	set("outdoors", "beijing");
	set("coor/x", -60);
	set("coor/y", 250);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

