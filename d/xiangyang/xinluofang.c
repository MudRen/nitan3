// Room: /d/xiangyang/xinluofang.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "���޷�");
        set("long", @LONG
���޷�������˼���Ǹ�������ס�ĵط���������ʵ���������Ѿ�����������
��������Ӧ�ý����������ġ����Ǵ���Ѿ�ϰ���ˣ����Ǳ㻹��ô�С�����ס��
���������ˣ�Ҳ��Щ������ʹ����������·����������Ҳס���������ĸ�
���������кܶ�ܺõĻ����Ҷ�ϲ��������������ͷǳ��������ˡ�
LONG );
	set("exits", ([
		"south" : "/d/xiangyang/northroad1",
	]));
	set("objects", ([
		"/d/xiangyang/npc/gaoli" : 1,
	]));
	set("coor/x", -310);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

