// road5.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
��������ˣ����У���˽Σ�����������ϲ�����������������������
ȥ��Ȫ�µ�·������������򶫱ߺ����ϱߡ�
LONG );
        set("exits", ([
            "southwest" : "/d/hangzhou/road4",
            "westup"    : "/d/hangzhou/yuquan",
            "south"     : "/d/hangzhou/dadao1",
            "east"      : "/d/hangzhou/road6",
        ]));
        set("objects" , ([
            "/d/hangzhou/npc/honghua1" :1,
            "/d/hangzhou/npc/tiao-fu" :1,
        ]));
        set("outdoors", "hangzhou");
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
