// Room: /d/xiangyang/guofugate.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;
void create()
{
	set("short", "��������");
	set("long", 
"һ���������ӵĴ�լԺ�����������ǰ��ֻ����¥������������������\n\n"
HIG"                     ��   ��\n\n"NOR
"ȫ��̵ڶ�������Ү����ͼ����Ҷ�վ����ǰ�Ӵ�ǰ�����������ĸ�����ʿ��\n"
 );
        set("outdoors", "xiangyang");
	set("exits", ([
		"south" : "/d/xiangyang/westjie1",
		"north" : "/d/xiangyang/guofuyuan",
	]));
	set("objects", ([
		"/d/xiangyang/npc/yelvqi" : 1,
		"/d/xiangyang/npc/jiading" : 2,
	]));
	set("coor/x", -300);
	set("coor/y", -80);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

