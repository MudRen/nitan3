// Room: /d/city/jiaowai9.c
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
        "east"  : "/d/city/jiaowai8",
        "west"  : "/d/city/jiaowai10",
    ]));
    set("objects", ([
        "/d/city/obj/shuzhi": 2,
        "/clone/beast/dushe" : 1,
    ]));
//    set("no_clean_up", 0);
	set("coor/x", -20);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
    replace_program(ROOM);
}