#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�����η�");
        set("long", @LONG
����һ���谵�ķ��䣬�����������������Ϸ���Ƥ�ޡ�ľ�����̾ߣ���Ȼ��
������˽�����ã���Ѷ�˷������ڡ�һ������������ǽ�ϣ���Ѫ���죬�������ˡ�
LONG );
	set("exits", ([
		"south" :  "/d/beijing/aofu_houyuan",
	]));
	set("objects", ([
		 "/d/beijing/npc/zhuangyu" : 1,
	]));

	set("coor/x", -50);
	set("coor/y", 390);
	set("coor/z", 0);
	setup();
}

