// Room: /d/city/jiaowai10.c
// Jan. 8.1998 by Venus
#include <room.h>
inherit ROOM;

void create()
{
    set("short", "����");
        set("long", @LONG
���ݽ����ï�����֣���ɭ�ɲ���̧ͷ�������ա�����Ҳ����������������
��ĵط��������߳��ε����
LONG );
    set("exits", ([
        "east"  : "/d/city/jiaowai9",
        "west"  : "/d/city/jiaowai11",
        "north" : "/d/city/jiaowai12",
    ]));
    set("objects", ([
        CLASS_D("gaibang")+"/jiang-sy" : 1,
        "/d/city/obj/shuzhi": 2,
        "/d/city/obj/shitou": 1,
    ]));
//    set("no_clean_up", 0);
	set("coor/x", -30);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
    replace_program(ROOM);
}