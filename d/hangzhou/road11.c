// road11.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
�غ�����Ե������������ֹ��ӣ������۴��αȣ���������������һƬ̫ƽ
���־��󡣽ֶ��ߵ�һ�ҵ����ﴫ�����������Ĵ�������
LONG );
        set("exits", ([
            "north"     : "/d/hangzhou/road10",
            "south"     : "/d/hangzhou/road12",
            "east"      : "/d/hangzhou/tiejiangpu",
        ]));
        set("outdoors", "hangzhou");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
