#include <room.h>
inherit ROOM;

void create()
{
        set("short", "��ľ��");
        set("long", @LONG
������һ�俴�ƺ���ͨ����ӣ�����ȴҪ��ͨ������Ӵ�����������������
��һ��������ͷ��������ϱ�����һ���š�
LONG );
       set("exits", ([
                "south" : "/d/beijing/qingmu_dating",
                "west" : "/d/beijing/qingmu_dayuan",
        ]));
        set("objects", ([
                "/d/beijing/npc/xutianchuan" : 1
        ]));
        set("outdoors", "beijing");
        set("coor/x", -50);
	set("coor/y", 210);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}

