// road20.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
��������ˣ����У���˽Σ�����������ϲ����������������������
�������ߣ��������յ̡�
LONG );
        set("exits", ([
            "north"     : "/d/hangzhou/suti7",
            "west"      : "/d/hangzhou/road19",
            "east"      : "/d/hangzhou/road16",
        ]));
        set("outdoors", "hangzhou");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
