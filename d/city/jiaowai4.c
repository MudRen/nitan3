// Room: /d/city/jiaowai4.c
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
        "north"     : "/d/city/jiaowai3",
        "west"      : "/d/city/jiaowai5",
        "southeast" : "/d/guiyun/shulin1",
    ]));
    set("objects", ([
        CLASS_D("gaibang")+"/zhao-gouer" : 1,
        "/d/city/obj/shuzhi": 2,
        "/d/city/obj/shitou": 2,
    ]));
//    set("no_clean_up", 0);
	set("coor/x", 40);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
    replace_program(ROOM);
}
