// Room: /city/zxlpath.c
// YZC 1995/12/04 

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "����¥����");
	set("long", @LONG
��������¥���ã����������Ŀ��˺�����С��������������������̶��ĺ�
���������������������������������ַǷ����������������ǰ�����Ž��ĸ���
�����֣�����ʳ��
    ������õ���������ϵ���ĵ����������ܽ������
LONG);
	set("exits", ([
		"east"   : "/d/city/meigui",
		"north"  : "/d/city/furong",
		"south"  : "/d/city/mudan",
		"west"   : "/d/city/zuixianlou2",
	]));
        set("no_fight","1");
	set("no_clean_up", 0);
	set("coor/x", 20);
	set("coor/y", 20);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
