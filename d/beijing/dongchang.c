inherit ROOM;
#include <ansi.h>

void create()
{
        set("short",RED"����"NOR);
        set("long", @LONG
������Ǿ��ǵ�����������������������ں��ǿ��������ﾯ�����ϣ�����
�Ʒ��Ķ����ٱ���̫�������������߶����������ﲻ�˾������Ͽ��뿪Ϊ�[2;37;0m
LONG );
	set("exits", ([
		"north" : "/d/beijing/dongchang_men",
	]));
	set("objects", ([
		"/d/beijing/npc/bing2" : 4,
		"/d/beijing/npc/taijian" : 1,
	]));
	set("no_fight", 0);
	setup();
}
