// road13.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
�غ�����Ե������������ֹ��ӣ������۴��αȣ���������������һƬ̫ƽ
���־��󡣽ֶ�����һ�ҿ͵ꡣ
LONG );
        set("exits", ([
            "north"     : "/d/hangzhou/road12",
            "southwest" : "/d/hangzhou/road14",
            "east"      : "/d/hangzhou/kedian",
        ]));
        set("outdoors", "hangzhou");
        setup();
        replace_program(ROOM);
}
