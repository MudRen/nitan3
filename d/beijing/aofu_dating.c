inherit ROOM;
#include <ansi.h>

void create()
{
	set("short","��������");
        set("long", @LONG
���������ݸ��Ĵ����������൱�Ŀ����������ܵ�ǽ���������˸�������
���漣����������һ��������룬��Ŀ��࣬���Ż���ӵ��������ӣ������Ǿ�
�ǵ�����һ�󳼣�������Ϊ�����޵�һ��ʿ���������ˡ�����������һ�����ȣ�
����ͨ�������ĺ�Ժ���ڡ�
LONG );
	set("exits", ([
		"north" :  "/d/beijing/aofu_zoulang2",
		"south" :  "/d/beijing/aofu_dayuan",
	]));
	set("objects", ([
		"/d/beijing/npc/aobai" : 1,
		"/d/beijing/npc/yahuan_a" : 1,
	]));
	set("coor/x", -50);
	set("coor/y", 360);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (objectp(present("ao bai", environment(me))) && dir == "north")
                return notify_fail("���ݴ����ȵ��������̵ģ���Ҫ���\n\n");
	return ::valid_leave(me, dir);
}