// Room: /d/xiangyang/hutong1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "��ͬ");
        set("long", @LONG
���������������ϰ��յľ�ס����ֻ����ͬ��������ЩС���棬�����С�С
�ӻ��̵ȡ�һЩ������������������
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
		"east" : "/d/xiangyang/jiekou1",
	]));
	set("objects", ([
		"/d/xiangyang/npc/kid" : 1,
		"/d/xiangyang/npc/boy" : 1,
	]));
	set("coor/x", -330);
	set("coor/y", -50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

