// Room: /d/xiangyang/walle8.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "����ͷ");
        set("long", @LONG
�����������Ķ���ͷ��һЩ�α����ڳ�ͷѲ�ߣ�һ��������������������
�����سǲ��ϣ�һЩ���������鹭��������ų��µĶ�����
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
		"northwest" : "/d/xiangyang/walln7",
		"southdown" : "/d/xiangyang/walle6",
	]));
	set("objects", ([
		"/d/xiangyang/npc/ya"   : 1,
		"/d/xiangyang/npc/bing" : 2,
	]));
	set("coor/x", -250);
	set("coor/y", -50);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}
