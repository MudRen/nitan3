// Room: /d/xiangyang/xiaorong1.c
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
		"west" : "/d/xiangyang/jiekou2",
                "north" : "/d/xiangyang/wjb_damen",
	]));
	set("objects", ([
		"/d/xiangyang/npc/kid" : 2,
	]));
	set("coor/x", -260);
	set("coor/y", -60);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

