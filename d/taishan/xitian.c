// Room: /d/taishan/.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����������ʯ�������������ն�����Ƶģ�����᷶���������ڡ�
LONG );
	set("exits", ([
		"southdown" : __DIR__"yueguan",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 70);
	set("coor/y", 140);
	set("coor/z", 110);
	setup();
	replace_program(ROOM);
}

