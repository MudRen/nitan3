// quyuanbei.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��Ժ���");
        set("long", @LONG
���С���ţ�ӭ����һͤԺ���Ա�����ʯ�������⡺��Ժ��ɡ��������ǻ�
�յ̡�
LONG );
        set("exits", ([
            "east"     : "/d/hangzhou/suti2",
            "enter"    : "/d/hangzhou/quyuanfenghe",
        ]));
        set("outdoors", "hangzhou");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
