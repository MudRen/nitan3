// Room: /d/xiangyang/westjie1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�����");
        set("long", @LONG
����һ����������ʯ��ֵ���������ͷ���졣������һ����ʮ�ֽֿڡ���
��������������㳡���������˳ƹ����������ĸ�ۡ���ţ���ʱ�����˴������
��������������һ�ҵ��̣���˵���泣����������Ķ�����
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	set("exits", ([
		"east"  : "/d/xiangyang/guangchang",
		"west"  : "/d/xiangyang/westjie2",
		"south" : "/d/xiangyang/dangpu",
		"north" : "/d/xiangyang/guofugate",
	]));
	set("objects", ([
		"/d/xiangyang/npc/poorman" : 1,
	]));
	set("coor/x", -300);
	set("coor/y", -90);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

