// Room: /d/xiangyang/westgate2.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "�׻�����");
        set("long", @LONG
�����������ǵ������ţ�ֻ�������Ϸ����š��׻��š��������֡����Ÿ���
�ɣ���Լ�������࣬�����ĳ�����������ȭͷ���С���������Ŷ���Լ���ɣ�
��Լÿ������ʱ���ͻ��ٱ����ء��������ɹ��Ŵ��ַ������ǣ�����������൱
���ܣ�����һЩ�ٱ��������̲�Ҫ�������ǵ��ˡ�
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
		"east"  : "/d/xiangyang/westgate1",
                "west"  : "/d/city2/yidao1",
	]));
	set("objects", ([
		"/d/xiangyang/npc/pi"   : 1,
		"/d/xiangyang/npc/bing" : 2,
	]));
	set("coor/x", -350);
	set("coor/y", -80);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

