// Room: /d/xiangyang/caodi3.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "�ݵ�");
        set("long", @LONG
������������Ĳݵء��ɹű���������������İ���ȫ�����ˣ���Ȼ�ɹű�
û�������ţ�����ɱ��Χ˿��������
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);
	set("exits", ([
		"north"  : "/d/xiangyang/southgate2",
		"south"  : "/d/wudang/wdroad5",
                "southwest"  : "/d/jingzhou/road1",
		"west"   : "/d/xiangyang/hunanroad1",
	]));
	set("coor/x", -290);
	set("coor/y", -150);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

