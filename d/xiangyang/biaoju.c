// Room: /d/xiangyang/biaoju.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�����ھ�");
        set("long", @LONG
������һ���ṹ��ΰ�Ľ���ǰ������ʯ̳�ϸ�����һ�����ɶ�ߵ���ˣ���
������Ʈ����������ý�������һͷ������צ��ʨ�ӣ�ʨ����ͷ��һֻ�����
�衣����������д�š������ھ������ֺš��˸����֣������������վ��Ƿ�����
�������������ʣ�������ͷ���Ű��ء�
LONG );
	set("exits", ([
		"west" : "/d/xiangyang/eastroad1",
	]));
	set("objects", ([
		"/d/xiangyang/npc/biaotou" : 2,
	]));
	set("coor/x", -260);
	set("coor/y", -80);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

