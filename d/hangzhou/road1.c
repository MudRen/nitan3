// road1.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
����ϼ�������������������Ϸ�������ο͡����߹���СϪ�����������ˡ�
�ϱ����Ϸ������·��
LONG );
        set("exits", ([
                "northwest" : "/d/quanzhou/jxnanmen",
                "northeast" : "/d/hangzhou/road2",
                "north"     : "/d/hangzhou/lingyinsi",
                "south"     : "/d/hangzhou/feilaifeng",
        ]));
        set("outdoors", "hangzhou");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
