// dalu1.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��·");
        set("long", @LONG
·�Ķ�����һ��Сɽ��ɽ�������дУ�����������ɽ�ϱ���һ������������
�õط�����ȴ��������ռΪ˽�С���·�򶫱��������졣
LONG );
        set("exits", ([
            "northeast" : "/d/hangzhou/dadao2",
            "south"     : "/d/hangzhou/dadao3",
        ]));
        set("objects", ([
            "/d/hangzhou/npc/tiao-fu": 1,
            "/d/hangzhou/npc/honghua1" : 2,
        ]));
//        set("no_clean_up", 0);
        set("outdoors", "hangzhou");
        setup();
}
