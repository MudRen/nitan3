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
                "east" : "/d/beijing/qingmu_dayuan",
        ]));

        set("objects", ([
                "/d/beijing/npc/qibiaoqing" : 1,
                "/d/beijing/npc/fangang" : 1,
                "/d/beijing/npc/fengjizhong" : 1,
        ]));
        set("outdoors", "beijing");
        set("coor/x", -70);
	set("coor/y", 210);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}

