// Room: /d/xiangyang/juyiyuan.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "��Ժ");
        set("long", @LONG
��������������ʹ���չ��������ص���˼�����������ø���ǰ��Ч������ʿ
�ĵط���������һ��������ͨ�ȣ��������������䳡��
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	set("exits", ([
		"east"  : "/d/xiangyang/juyilianwu1",
		"west"  : "/d/xiangyang/juyilianwu2",
		"south" : "/d/xiangyang/juyilang",
		"north" : "/d/xiangyang/westjie2",
	]));
	set("objects", ([
		"/d/xiangyang/npc/zhuziliu" : 1,
	]));
	set("coor/x", -320);
	set("coor/y", -90);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

