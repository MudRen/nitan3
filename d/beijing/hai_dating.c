inherit ROOM;
#include <ansi.h>

void create()
{
	set("short","���ι�������");
        set("long", @LONG
���Ǻ��ι����Ĵ�������������װ��Ҳ�������������������ﾹȻ��һ��
�����ľ�������ʱ��������һƬ���ӣ�������������Ѱ�µ���ǰ������
LONG );
	set("exits", ([
		"north" : "/d/beijing/hai_dayuan",
		"south" : "/d/beijing/hai_houyuan",
	]));
	set("objects", ([
		"/d/beijing/npc/duolong" : 1,
		"/d/beijing/npc/zheng" : 1,
		"/d/beijing/npc/feng" : 1,
	]));

	set("coor/x", 20);
	set("coor/y", 290);
	set("coor/z", 0);
	setup();
}