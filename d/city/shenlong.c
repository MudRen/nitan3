// Room: /city/shenlong.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
shen long
��Ҫ�����˵������
LONG );

	set("exits", ([
		"west" : "/d/city/road7",
	]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

