// Room: /d/fuzhou/ximen.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
�����Ǹ������š������������ɴ���ԭ��
LONG );
	set("exits", ([
                "east" : __DIR__"ximendajie",
                "west" : __DIR__"fzroad11",
	]));
	set("outdoors", "fuzhou");
	set("coor/x", 120);
	set("coor/y", -110);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

