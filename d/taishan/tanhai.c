// Room: /d/taishan/.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "̽��ʯ");
	set("long", @LONG
����һ���ɽ�����ͻ���ľ�ʯ����Լ�����࣬��ֱָ������
��ʯ��������ƾ������Ұ�������������о��ߵ�ɫ���ˣ���ͨ��һ��
�������ʵ����̽��ʯ��
LONG );
	set("exits", ([
		"westdown" : __DIR__"riguan",
		"east" : __DIR__"dongtian",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 100);
	set("coor/y", 140);
	set("coor/z", 110);
	setup();
	replace_program(ROOM);
}

