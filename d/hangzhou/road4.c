// road4.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
��������ˣ����У���˽Σ�����������ϲ�����������������������
�鴺�š�����������򶫱��ߡ�
LONG );
        set("exits", ([
            "south"     : "/d/hangzhou/hongchunqiao",
            "northeast" : "/d/hangzhou/road5",
        ]));
        set("outdoors", "hangzhou");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
