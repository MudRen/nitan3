// road19.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
��������ˣ����У���˽Σ�����������ϲ����������������������
�򶫺��������ߣ���������һ�������
LONG );
        set("exits", ([
            "north"     : "/d/hangzhou/dadao3",
            "southwest" : "/d/hangzhou/road18",
            "east"      : "/d/hangzhou/road20",
        ]));
        set("objects" , ([
            "/d/hangzhou/npc/dao-ke"  :1,
            "/d/hangzhou/npc/longjun" :1,
        ]));
        set("outdoors", "hangzhou");
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
