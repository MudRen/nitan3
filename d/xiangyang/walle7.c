// Room: /d/xiangyang/walle7.c
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
		"southwest" : "/d/xiangyang/walls8",
		"northdown" : "/d/xiangyang/walle5",
	]));
	set("objects", ([
		"/d/xiangyang/npc/ya"   : 1,
		"/d/xiangyang/npc/bing" : 2,
	]));
	set("coor/x", -250);
	set("coor/y", -130);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}
