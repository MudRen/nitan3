// suti2.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�յ�");
        set("long", @LONG
�յ��ϣ��ο����е���������������ʫ����̸���ۣ��е������ʯ����ˮ
�������е��������ߣ���������������ǿ���ţ������Ƕ����ţ�������ȥ��԰
��ɡ�
LONG );
        set("exits", ([
            "north"     : "/d/hangzhou/suti1",
            "south"     : "/d/hangzhou/suti3",
            "west"      : "/d/hangzhou/quyuanbei",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "hangzhou");
        setup();
        replace_program(ROOM);
}
