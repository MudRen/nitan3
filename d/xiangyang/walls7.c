// Room: /d/xiangyang/walls7.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�ϳ�ͷ");
        set("long", @LONG
�������������ϳ�ͷ��һЩ�α����ڳ�ͷѲ�ߣ�һ��������������������
�����سǲ��ϣ�һЩ���������鹭��������ų��µĶ�����
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
		"northwest" : "/d/xiangyang/wallw8",
		"eastdown"  : "/d/xiangyang/walls5",
	]));
	set("objects", ([
		"/d/xiangyang/npc/ya"   : 1,
		"/d/xiangyang/npc/bing" : 2,
	]));
	set("coor/x", -330);
	set("coor/y", -130);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}
