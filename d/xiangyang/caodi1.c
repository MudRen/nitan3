// Room: /d/xiangyang/caodi1.c
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
		"west"  : "/d/xiangyang/northgate2",
	]));
	set("objects", ([
		"/d/xiangyang/npc/tuolei"   : 1,
		"/d/xiangyang/npc/menggubing" : 2,
	]));
	set("coor/x", -290);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

