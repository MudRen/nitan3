#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�ش���ҩ������");
        set("long", @LONG
�����ǻش���ҩ�����������һ�߽��������ҩ����ζ�����滹ҪŨ�Ϻ�
�ࡣ�㿴��һ��Сͯ������������ͷ����ҩ�ġ�
LONG );
        set("no_fight", 1);
        set("objects", ([
                "/d/beijing/npc/liandan_tongzi"     : 1,
        ]));
        set("exits", ([
                "west" : "/d/beijing/huichuntang",
                "north": "/d/beijing/liandan_yaoshi",
        ]));

	set("coor/x", -30);
	set("coor/y", 270);
	set("coor/z", 0);
	setup();
}
