// faxisi.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ϲ��");
        set("long", @LONG
��ϲ��������������������ĵ�һ����������οͲ�ʱ�Ľ�������������
�ɴ���������������ɽ��·��
LONG );
        set("exits", ([
                "eastdown"  : "/d/hangzhou/shanlu4",
                "northdown" : "/d/hangzhou/shanlu3",
        ]));
        set("objects", ([
            "/d/hangzhou/npc/guest" : 2,
            "/d/hangzhou/npc/seng" : 1,
        ]));
//        set("no_clean_up", 0);
        set("outdoors", "hangzhou");
        setup();
        replace_program(ROOM);
}
