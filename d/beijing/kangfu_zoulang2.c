#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��������");
        set("long", @LONG
����һ��ľ�Ƶ����ȣ�������ǹ⻬����������һ����Ⱦ����������������
�ڴ��߶����ϱ��ǿ����Ĵ��������������������᷿�������ǿ��������鷿���ڡ�
����վ��һ��ͺͷ���У����ǿ���������ͷ�졣
LONG );
       set("exits", ([
		"north" : "/d/beijing/kangfu_shufang",
		"south" : "/d/beijing/kangfu_dating",
		"west" : "/d/beijing/kangfu_xifang",
		"east" : "/d/beijing/kangfu_dongfang",
	]));
	set("objects", ([
		"/d/beijing/npc/jiading_k" : 1,
		"/d/beijing/npc/yahuan_k" : 1,
		"/d/beijing/npc/shenzhao" : 1,
	]));
	set("outdoors", "beijing");
	set("coor/x", -30);
	set("coor/y", 310);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}