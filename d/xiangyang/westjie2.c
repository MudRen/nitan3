// Room: /d/xiangyang/westjie2.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�����");
        set("long", @LONG
����Ǻܴ��ʮ�ֽֿڣ����������ڴ�֣�������һ����¥��¥ǰ�߸ߵĹ�
��һ�����ң�����������д�š�����ݡ�������������������ͨ������㳡��
����ɴ�׻��š�
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	set("exits", ([
		"east"  : "/d/xiangyang/westjie1",
		"west"  : "/d/xiangyang/westjie3",
		"south" : "/d/xiangyang/juyiyuan",
		"north" : "/d/xiangyang/westroad1",
	]));
	set("objects", ([
		"/d/xiangyang/npc/wusantong" : 1,
	]));
	set("coor/x", -320);
	set("coor/y", -80);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

