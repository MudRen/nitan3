// Room: /d/xiangyang/caodi3.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "�ݵ�");
        set("long", @LONG
������������Ĳݵء��ɹű���������������İ���ȫ�����ˣ��ɹű��۳�
��ȥ����Ϊ��������������������š�
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
		"south"  : "/d/xiangyang/northgate2",
                "north"  : "/d/changan/hanguguan",
                "northeast"  : "/d/luoyang/guandaos6",
	]));
	set("objects", ([
		"/d/xiangyang/npc/menggubing" : 2,
	]));
	set("coor/x", -300);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

