// Room: /d/fuzhou/fzroad9.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "���д��");
	set("long", @LONG
������������������ϡ�����������ɽ���࣬��ˮ���䣬ɽ
�����������ˣ����������㷡������й�����ð���ƺ��м�Ұ
�ꡣ
LONG );
	set("exits", ([
		"northwest" : __DIR__"fzroad8",
		"north"     : __DIR__"fzroad10",
		"east"      : __DIR__"fzroad11",
	]));
        set("objects", ([
		"/d/qingcheng/npc/jia" : 1,
	]));
	set("outdoors", "fuzhou");
	set("coor/x", 100);
	set("coor/y", -110);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

