// road16.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
��������ˣ����У���˽Σ�����������ϲ��������������������߿�
���׷壬�ϱ��Ǿ����¡�
LONG );
        set("exits", ([
            "northup" : "/d/hangzhou/xizhaoshan",
            "south"   : "/d/hangzhou/jingcisi",
            "east"    : "/d/hangzhou/road15",
            "west"    : "/d/hangzhou/road20",
        ]));
        set("objects", ([
            "/d/hangzhou/npc/baizhen" : 1,
                "/clone/npc/walker"  : 1, 
        ]));
        set("outdoors", "hangzhou");
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
