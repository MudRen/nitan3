// Room: /d/xiangyang/walln8.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "����ͷ");
        set("long", @LONG
�����������ı���ͷ��һЩ�α����ڳ�ͷѲ�ߣ�һ��������������������
�����سǲ��ϣ�һЩ���������鹭��������ų��µĶ�����
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
		"southwest" : "/d/xiangyang/wallw7",
		"eastdown"  : "/d/xiangyang/walln6",
	]));
	set("objects", ([
		"/d/xiangyang/npc/ya"   : 1,
		"/d/xiangyang/npc/bing" : 2,
	]));
	set("coor/x", -330);
	set("coor/y", -30);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}
