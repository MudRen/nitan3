#include <room.h>
inherit ROOM;

void create()
{
        set("short", "��ľ�ô���");
        set("long", @LONG
����һ������ͨ���ĺ�Ժ���ƾɵĴ��ų����ţ���������һ����Ժ��Ժ����
���Ǽ�����ͨ����ӡ�
LONG );
       set("exits", ([
                "north" : "/d/beijing/yangliu3",
                "south" : "/d/beijing/qingmu_dayuan",
        ]));

        set("outdoors", "beijing");
        set("coor/x", -60);
	set("coor/y", 220);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}

