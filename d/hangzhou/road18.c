// road18.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
��������ˣ����У���˽Σ�����������ϲ����������������������
�򶫱��������ߣ�������ʯ�ݶ���
LONG );
        set("exits", ([
            "northeast" : "/d/hangzhou/road19",
            "west"      : "/d/hangzhou/shiwudong",
            "south"     : "/d/hangzhou/road17",
            "east"      : "/d/hangzhou/yuhuangshan",
        ]));
        set("outdoors", "hangzhou");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
