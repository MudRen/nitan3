// Room: /d/xiangyang/shudian.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "���");
        set("long", @LONG
������ϰ�մ�������������˵��ǰ��������ɽ�����³����ң���֪ʲô
ԭ���ֻ����ף�ר������Ϊ����ֻ���������ܴ���ǰ����һ��������
LONG );
	set("exits", ([
		"east" : "/d/xiangyang/westroad2",
	]));
	set("objects", ([
		"/d/xiangyang/npc/shudianboss" : 1,
	]));
	set("coor/x", -330);
	set("coor/y", -60);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
