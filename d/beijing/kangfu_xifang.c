#include <room.h>
inherit ROOM;

void create()
{
	set("short", "���᷿");
        set("long", @LONG
�����ǿ�����������ߵ�һ���᷿���ǹ������Ŀ��˾�ס�ġ�����վ��һ��
����ݸߵ���ʦ�����ֱ��������ƺ���һ����书��
LONG );
	set("exits", ([
		"east" : "/d/beijing/kangfu_zoulang2",
	]));

	set("objects", ([
		"/d/beijing/npc/qiyuankai" : 1,
	]));

	set("sleep_room", "1");
	set("outdoors", "beijing");
	set("coor/x", -40);
	set("coor/y", 310);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}