// Room: /d/xiangyang/dingzi.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "���ֽֿ�");
        set("long", @LONG
�����������Ǳ����Ķ��ֽֿڡ���һֱͨ�������ţ������������һ����
ֱ����ʯ��֣�ͨ����ڡ�������һ���ϸǺ�ɫ�����ߵĸ�ǽ����������������
ʹ���ĵµĸ�ۡ��
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	set("exits", ([
		"east"  : "/d/xiangyang/northroad2",
		"west"  : "/d/xiangyang/northroad1",
		"north" : "/d/xiangyang/northjie",
	]));
	set("coor/x", -300);
	set("coor/y", -50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

