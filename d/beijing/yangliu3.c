#include <room.h>
inherit ROOM;

void create()
{
        set("short", "������ͬ");
        set("long", @LONG
������������ͬ�ĵ׶ˣ��ߵ���������Ѿ�������ˡ�һ·�ϣ���ͬ����
�ĺ�Ժ�Ĵ��Ž����ţ�Ψ�������ϱߵ�һ���ĺ�Ժ�����ǳ����ŵġ��㲻��
��ȥ��һ����
LONG );
       set("exits", ([
                "north" : "/d/beijing/yangliu2",
                "south" : "/d/beijing/qingmu_men",
        ]));

        set("outdoors", "beijing");
        set("coor/x", -60);
	set("coor/y", 230);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}

