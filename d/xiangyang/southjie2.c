// Room: /d/xiangyang/southjie2.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�ϴ��");
        set("long", @LONG
��������������ķ����ضΣ���Ȼ�þ�ս�𣬵��ڹ������˵ı����£�����
���ϰ��չ��ŷǳ��������ȵ����������������������һ�Ҷĳ���������һ
�������¥�󣬹��š��ơ����������Ŷ�������һ�����ң����顺����¥�����֡�
һ���������ζ�˱Ƕ�����
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	set("exits", ([
		"east"  : "/d/xiangyang/nixianglou",
		"west"  : "/d/xiangyang/duchang",
		"south" : "/d/xiangyang/southjie3",
		"north" : "/d/xiangyang/southjie1",
	]));
	set("objects", ([
		"/d/city/npc/liumang" : 1,
	]));
	set("coor/x", -290);
	set("coor/y", -110);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
