// Room: /d/xiangyang/northroad2.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "���ڴ��");
        set("long", @LONG
����һ������ʯ�̾͵Ĵ����ֻ�����治ʱ�������ɱ��������ޣ�������
���С��������Ƕ��ֽֿڣ�����Ҳ��һ����ֿڣ�����󿴵�һ�����ͨ�����档
������һ���ϸǺ�ɫ�����ߵĸ�ǽ�������������سǴ�����ĸ�ۡ��
LONG );
        set("outdoors", "xiangyang");

	set("no_clean_up", 0);
	set("exits", ([
		"east"  : "/d/xiangyang/jiekou2",
		"west"  : "/d/xiangyang/dingzi",
		"north" : "/d/xiangyang/majiu",
	]));
	set("coor/x", -280);
	set("coor/y", -60);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

