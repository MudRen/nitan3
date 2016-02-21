// Room: /d/xiangyang/northgate2.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "��������");
        set("long", @LONG
�����������ǵı����ţ�ֻ�������Ϸ����š������š��������֡����Ÿ���
�ɣ���Լ�������࣬�����ĳ�����������ȭͷ���С���������Ŷ���Լ���ɣ�
��Լÿ������ʱ���ͻ��ٱ����ء��������ɹ��Ŵ��ַ������ǣ�����������൱
���ܣ�����һЩ�ٱ��������̲�Ҫ�������ǵ��ˡ�
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
		"south"  : "/d/xiangyang/northgate1",
		"north"  : "/d/xiangyang/caodi3",
		"east"   : "/d/xiangyang/caodi1",
		"west"   : "/d/xiangyang/caodi2",
	]));
	set("objects", ([
		"/d/xiangyang/npc/pi"   : 1,
		"/d/xiangyang/npc/bing" : 2,
	]));
	set("coor/x", -300);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

