// Room: /d/city/jiaowai2.c
// Jan. 8.1998 by Venus
#include <room.h>
inherit ROOM;

void create()
{
    set("short", "����");
        set("long", @LONG
���ݽ�������֣���֦ͦ�Σ���ľ��б���ּ�С����������Զ�����в�����
�֣�������ת��ʹ���ʱ���⾡����    �������˺ܶ���֦ʯ�顣
LONG );
    set("exits", ([
        "north" : "/d/city/jiaowai1",
        "south" : "/d/city/jiaowai3",
    ]));
    set("objects", ([
        CLASS_D("gaibang")+"/qiu-wanjia": 1,
        "/d/city/obj/shuzhi": 1,
        "/d/city/obj/shitou": 1,
    ]));
//    set("no_clean_up", 0);
    set("outdoors", "yangzhou");
	set("coor/x", 40);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
    replace_program(ROOM);
}