// Room: /d/city/jiaowai6.c
// Jan. 8.1998 by Venus
#include <room.h>
inherit ROOM;

void create()
{
    set("short", "����");
        set("long", @LONG
���ݽ�������֣���֦ͦ�Σ���ľ��б���ּ�С����������Զ�����в�����
�֣�������ת��ʹ���ʱ���⾡����    
    �������˺ܶ���֦ʯ�顣
LONG );

    set("exits", ([
        "east" : "/d/city/jiaowai5",
        "west" : "/d/city/jiaowai7",
    ]));
    set("objects", ([
        CLASS_D("gaibang")+"/kuai-huosan" : 1,
        "/d/city/obj/shitou": 2,
    ]));
//    set("no_clean_up", 0);
    set("outdoors", "yangzhou");
	set("coor/x", 20);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
    replace_program(ROOM);
}