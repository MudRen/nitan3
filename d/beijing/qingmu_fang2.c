#include <room.h>
inherit ROOM;

void create()
{
        set("short", "��ľ��");
        set("long", @LONG
������һ�俴�ƺ���ͨ����ӣ�����ȴҪ��ͨ������Ӵ�����������������
һ�ų�������ػ����ľ�õ�Ⱥ��Χ��������������̸��
LONG );
       set("exits", ([
                "north" : "/d/beijing/qingmu_dayuan",
        ]));
        set("objects", ([
                 "/d/beijing/npc/guananji" : 1,
                 "/d/beijing/npc/qianlaoben" : 1,
                 "/d/beijing/npc/jialaoliu" : 1,
        ]));
        set("outdoors", "beijing");
        set("coor/x", -60);
	set("coor/y", 200);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}

