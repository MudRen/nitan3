// Room: /d/fuzhou/fzroad11.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "���д��");
	set("long", @LONG
�������ǳǽ�����������Ҳ�����������������ݵĹٻ�����
���̶��Ѷ�����������ٴ죬����һ����ζ��
LONG );
	set("exits", ([
		"east"   : __DIR__"ximen",
		"west"   : __DIR__"fzroad9",
	]));
	set("outdoors", "fuzhou");
	set("coor/x", 110);
	set("coor/y", -110);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

