// suti3.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�յ�");
        set("long", @LONG
��������ѩ�����У���������̤ѩ�۾����ӵ��ϼ�ĿԶ����ֻ������������
�֡������Ƕ����ţ�������ѹ���š�
LONG );
        set("exits", ([
            "north"     : "/d/hangzhou/suti2",
            "south"     : "/d/hangzhou/suti4",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "hangzhou");
        setup();
        replace_program(ROOM);
}
