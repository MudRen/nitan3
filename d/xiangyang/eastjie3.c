// Room: /d/xiangyang/eastjie3.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�����");
        set("long", @LONG
����һ����������ʯ�ֵ���������ͷ���졣�������������ţ��ϱ���ľ��
�̣���ľ������ľ����������������������ǵĶ���Ӫ���������������洫����
���Ĳ�������������һ��ʮ�ֽֿڣ�ֻ���������������ﲻ����
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	set("exits", ([
		"east"  : "/d/xiangyang/eastgate1",
		"west"  : "/d/xiangyang/eastjie2",
		"south" : "/d/xiangyang/mujiang",
		"north" : "/d/xiangyang/bingying2",
	]));
	set("coor/x", -260);
	set("coor/y", -90);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

