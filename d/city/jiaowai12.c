// Room: /d/city/jiaowai12.c
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
        "south" : "/d/city/jiaowai10",
        "west"  : "/d/city/jiaowai13",
    ]));
    set("objects", ([
        "/clone/beast/dushe" : 2,
        "/d/city/obj/shuzhi": 1,
    ]));
//    set("no_clean_up", 0);
	set("coor/x", -30);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
    replace_program(ROOM);
}