// road9.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
��������ˣ����У���˽Σ�����������ϲ����������������������
�������ߡ������ڴ�������ϱߡ��ϱ�������һ�������
LONG );
        set("exits", ([
            "west"      : "/d/hangzhou/road8",
            "south"     : "/d/hangzhou/road10",
            "southwest" : "/d/hangzhou/duanqiao",
        ]));
        set("outdoors", "hangzhou");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
