// shenxudong.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
�����񷶥�ϵ�ʯ���������һ����⣬��������һ���졻�����ϱ�����ɽ
��·��
LONG );
        set("exits", ([
                "southeast" : "/d/hangzhou/longhongdong",
        ]));
        set("objects", ([
             "/d/hangzhou/npc/mengmian":1,
        ]));
        set("outdoors", "hangzhou");
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
