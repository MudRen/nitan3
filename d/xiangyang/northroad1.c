// Room: /d/xiangyang/northroad1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "���ڴ��");
        set("long", @LONG
����һ������ʯ�̾͵Ĵ����ֻ��������һ������ܴ���ӻ��̣���˵����
������ණ�����򶫾��Ƕ��ֽֿڣ�����Ҳ��һ����ֿڣ�����󿴵�һ����
��ͨ�����档������һ���ϸǺ�ɫ�����ߵĸ�ǽ����������������ʹ���ĵ°���
�����Ĳ��¿��䡢�˳ƹ����������ĸ�ۡ��
LONG );
        set("outdoors", "xiangyang");

	set("no_clean_up", 0);
	set("exits", ([
		"west"  : "/d/xiangyang/jiekou1",
		"east"  : "/d/xiangyang/dingzi",
		"north" : "/d/xiangyang/xinluofang",
	]));
	set("coor/x", -310);
	set("coor/y", -50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

