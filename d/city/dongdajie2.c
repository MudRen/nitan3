// Room: /city/dongdajie2.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����ڶ�����ϣ����ż�ʵ����ʯ����档�����Ƕ����ţ����������سǹ�
����ߺ���������������ʵĶ�����������һ�𡣱�����һ�����ֺŵ�ҩ�̣��ϱ�
�Ǵ����̣�����������������Զ����������
LONG );
        set("outdoors", "city");
	set("exits", ([
		"east"  : "/d/city/dongdajie3",
		"south" : "/d/city/datiepu",
		"west"  : "/d/city/dongdajie1",
		"north" : "/d/city/yaopu",
	]));

	set("coor/x", 20);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
