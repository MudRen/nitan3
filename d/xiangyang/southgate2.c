// Room: /d/xiangyang/southgate2.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "��ȸ����");
        set("long", @LONG
�����������ǵ��ϳ��ţ�ֻ�������Ϸ����š���ȸ�š��������֡����Ÿ���
�ɣ���Լ�������࣬�����ĳ�����������ȭͷ���С���������Ŷ���Լ���ɣ�
��Լÿ������ʱ���ͻ��ٱ����ء��������ɹ��Ŵ��ַ������ǣ�����������൱
���ܣ�����һЩ�ٱ��������̲�Ҫ�������ǵ��ˡ�
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
		"east"   : "/d/xiangyang/caodi4",
		"west"   : "/d/xiangyang/caodi5",
		"south"  : "/d/xiangyang/caodi6",
		"north"  : "/d/xiangyang/southgate1",
	]));
	set("objects", ([
		"/d/xiangyang/npc/pi"   : 1,
		"/d/xiangyang/npc/bing" : 2,
	]));
	set("coor/x", -290);
	set("coor/y", -140);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

