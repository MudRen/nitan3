#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�ٵ�");
        set("long", @LONG
������һ���ٵ��ϣ������Ѿ�������Լ�����ɶ��ǵĳ���
�ˣ���ȥ�������
LONG);
        set("exits", ([
                "west" :  __DIR__"road2",
                "east" : __DIR__"shudao18",
        ]));
        set("objects", ([
                "/d/beijing/npc/shusheng2" : 1,
        ]));
        set("no_clean_up", 0);
        set("outdoors", "chengdu");

        set("coor/x", -370);
	set("coor/y", -180);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

