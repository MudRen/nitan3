// road7.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
��������ˣ����У���˽Σ�����������ϲ����������������������
�������ߺͶ����ߡ������߱����ϱ�ɽ���ϱ���ͨ�������š�
LONG );
        set("exits", ([
            "northeast" : "/d/hangzhou/road8",
            "north"     : "/d/hangzhou/shanlu8",
            "south"     : "/d/hangzhou/xilingqiao",
            "west"      : "/d/hangzhou/road6",
        ]));
        set("objects", ([
            "/d/hangzhou/npc/youfang" : 1,
        ]));
        set("outdoors", "hangzhou");
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

