// liuheta.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
��������ɽ����������������֮ǰ�������������������������͡�֮����֮
��ҵ����ֹ�Լ�������ϡ����ǡ��죬�أ��ķ�������˼�������˽�����ʮ���㣬
�����ķ����̽�������һ������ֻ�����塣
LONG );
        set("exits", ([
            "eastdown" : "/d/hangzhou/qiantang",
            "enter"    : "/d/hangzhou/liuhe1",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
