inherit ROOM;
#include <ansi.h>

void create()
{
        set("short",RED"����"NOR);
        set("long", @LONG
������Ǿ��ǵ�����������������������ں��ǿ��������ﾯ�����ϣ�����
�Ʒ��������ٱ���̫�������������߶����������ﲻ�˾������Ͽ��뿪Ϊ�[2;37;0m
LONG );
	set("exits", ([
		"north" : "/d/beijing/xichang_men",
	]));
	set("objects", ([
		"/d/beijing/npc/bing3" : 4,
		"/d/beijing/npc/taijian" : 1,
	]));
	set("no_fight", 0);
	set("coor/x", -40);
	set("coor/y", 280);
	set("coor/z", 0);
	setup();
}