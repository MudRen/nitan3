// xilingqiao.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�������ν��ɽ��������������ŵĶ��ϱ��ǹ�ɽ����������һ����ʯ�����
LONG );
        set("exits", ([
            "southeast" : "/d/hangzhou/gushan",
            "north"     : "/d/hangzhou/road7",
        ]));
        set("outdoors", "hangzhou");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
