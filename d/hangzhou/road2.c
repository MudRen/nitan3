// road2.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
��������ˣ����У���˽Σ�����������ϲ�����������������������
�ͷ����塣�����������á�
LONG );
        set("exits", ([
                "southup"   : "/d/hangzhou/shanlu1",
                "southwest" : "/d/hangzhou/road1",
                "northeast" : "/d/hangzhou/road3",
        ]));
        set("objects", ([
           "/d/hangzhou/npc/xianghuo" : 1,
        ]));
        set("outdoors", "hangzhou");
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
