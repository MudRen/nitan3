// Room: /d/xiangyang/eastjie2.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�����");
        set("long", @LONG
����Ǻܴ��ʮ�ֽֿڣ������Ƕ��ڴ�֣�������һ���ֵ�����˵��Ǯ��һ
�㶼ס�����棬����ͨ�������ǵ������ţ������ɵ�������㳡��
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	set("exits", ([
		"east"  : "/d/xiangyang/eastjie3",
		"west"  : "/d/xiangyang/eastjie1",
		"south" : "/d/xiangyang/jiedao",
		"north" : "/d/xiangyang/eastroad1",
	]));
	set("coor/x", -270);
	set("coor/y", -90);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

