#include <room.h>
inherit ROOM;

void create()
{
	set("short", "Τ���鷿");
        set("long", @LONG
������Τ��ү���鷿�����������������������һ���ľ������������һ
�����߸ߵĻ�ͭ��¯�����ܵ�����϶ѷ����˸����鼮�����������׿����Ѿ���
��û�˶����ˡ�
LONG );

	set("exits", ([
		"south" : "/d/beijing/weifu_dating",
	]));
	set("objects", ([
		"/d/beijing/npc/shizhe" : 1,
	]));
	set("coor/x", -30);
	set("coor/y", 310);
	set("coor/z", 0);
	setup();
}
