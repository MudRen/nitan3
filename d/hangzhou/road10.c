// road10.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
�غ�����Ե������������ֹ��ӣ������۴��αȣ���������������һƬ̫ƽ
���־��󡣽ֵĶ�����һ����¥��
LONG );
        set("exits", ([
            "north"     : "/d/hangzhou/road9",
            "south"     : "/d/hangzhou/road11",
            "east"      : "/d/hangzhou/jiulou",
            "west"      : "/d/hangzhou/marryroom",
        ]));
        set("outdoors", "hangzhou");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
