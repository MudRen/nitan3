#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�����鷿");
        set("long", @LONG
�����������鷿��ȴû��һ���顣���ֹ���������Ŀ��������ͭ�����ߵ���
�����ʣ����鱦ʯ��Ӧ�о��У�ֻҪӵ��һ�����͹����һ�����ˡ�����ǽ����
һ��������������һ���顣
LONG );

	set("exits", ([
		"east" : "/d/beijing/aofu_zoulang3",
	]));
	set("objects", ([
		"/d/beijing/npc/shizhe" : 1,
	]));
	set("coor/x", -70);
	set("coor/y", 380);
	set("coor/z", 0);
	setup();
}