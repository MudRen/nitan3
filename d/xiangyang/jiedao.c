// Room: /d/xiangyang/jiedao.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�ֵ�");
        set("long", @LONG
����������������Ǯ�˵ľ�ס�����ֵ�������һЩ������סլ����Ȼ������
��ս�ң������������Ǯ��û���ߣ�Ϊ���������ǳ�Ǯ������
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
		"east"  : "/d/xiangyang/minju1",
		"west"  : "/d/xiangyang/minju2",
		"north" : "/d/xiangyang/eastjie2",
	]));
	set("objects", ([
		"/d/xiangyang/npc/poorman" : 2,
	]));
	set("coor/x", -270);
	set("coor/y", -100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

