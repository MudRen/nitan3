// Room: /d/xiangyang/xiaorong2.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "��ͬ");
        set("long", @LONG
���������������ϰ��յľ�ס����ֻ��СŪ��������ЩС���棬�����С�С
�ӻ��̵ȡ�һЩ������������������
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
		"south" : "/d/xiangyang/jiekou2",
	]));
	set("objects", ([
		"/d/xiangyang/npc/boy"  : 1,
		"/d/xiangyang/npc/girl" : 1,
	]));
	set("coor/x", -270);
	set("coor/y", -50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

