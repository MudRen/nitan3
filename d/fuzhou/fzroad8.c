// Room: /d/fuzhou/fzroad8.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���Ӹ��ŷŽ����£�������ɽ�д䣬���㷺����С�۴�����
̲֮�У����ϻ���ˮ�죬����ƽ������������ʮ��ˮ·������Ϧ
����
LONG );
	set("exits", ([
		"northwest" : __DIR__"yanping",
		"southeast" : __DIR__"fzroad9",
	]));
	set("outdoors", "fuzhou");
	set("coor/x", 90);
	set("coor/y", -100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

