// road6.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
��������ˣ����У���˽Σ�����������ϲ����������������������
���������ߡ��ϱ���ͨ���յ̡�������������
LONG );
        set("exits", ([
            "north"     : "/d/hangzhou/yuelang",
            "south"     : "/d/hangzhou/suti1",
            "west"      : "/d/hangzhou/road5",
            "east"      : "/d/hangzhou/road7",
        ]));
        set("objects" , ([
            "/d/hangzhou/npc/liumang" :4,
            "/d/hangzhou/npc/liumangtou" :1,
        ]));
        set("outdoors", "hangzhou");
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
