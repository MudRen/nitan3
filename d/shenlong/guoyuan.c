// /d/shenlong/guoyuan.c
// ALN Sep / 97

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��԰");
        set("long", @LONG
����һƬ��԰���ֵ���һЩˮ������ƻ������ͷ��ɽ�ꡢ���ӡ����ӡ�÷��
�ȣ��е��ѵ����ջ�ʱ�ڣ�֦ͷ�ѱ���ʵѹ�������������ģ���һ��֦ͷһ��
һ���ģ����˿���ֱ����ˮ�����桢�����ƺ�����ũ�������ɽ��������ֱ
ͨ�����̵ĳ�����
LONG );
        set("outdoors", "shenlong");
        set("exits", ([
                "west" : __DIR__"chufang",
        ]));
        set("objects", ([
            __DIR__"obj/apple" : 2 + random(8),
        ]));
        set("cost", 3);
        set("snaketype", ({"yinhuan"}));
        setup();
}

#include "snakeroom.h"

