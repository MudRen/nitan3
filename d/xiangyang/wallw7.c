// Room: /d/xiangyang/wallw7.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "����ͷ");
        set("long", @LONG
����������������ͷ��һЩ�α����ڳ�ͷѲ�ߣ�һ��������������������
�����سǲ��ϣ�һЩ���������鹭��������ų��µĶ�����
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
		"northeast" : "/d/xiangyang/walln8",
		"southdown" : "/d/xiangyang/wallw5",
	]));
	set("objects", ([
		"/d/xiangyang/npc/ya"   : 1,
		"/d/xiangyang/npc/bing" : 2,
	]));
	set("coor/x", -340);
	set("coor/y", -40);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}
