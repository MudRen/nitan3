// suti5.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�յ�");
        set("long", @LONG
ÿ��ʢ�ģ��ο͵��˷׷�Ѱ��СϢ�������������£�������ġ���������ɽ
�ţ����������š�
LONG );
        set("exits", ([
            "north"     : "/d/hangzhou/suti4",
            "south"     : "/d/hangzhou/suti6",
        ]));
        set("outdoors", "hangzhou");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
