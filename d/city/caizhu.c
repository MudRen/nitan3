// Room: /city/caizhu.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
һ�������ûʵĴ�լԺ�����������ǰ����ͷ�ߴ��ʯʨ���������˴�����
�࣬���������������������Ϲ�������������д�š��ޡ��֡��޼��ǵ�����
�����������������ơ������ǹ�������������˹�����
LONG );
	set("exits", ([
		"south" : "/d/city/xidajie2",
		"north" : "/d/city/dayuan",
	]));
	set("objects", ([
		"/d/city/npc/wolfdog" : 2,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -20);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
