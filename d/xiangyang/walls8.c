// Room: /d/xiangyang/walls8.c
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
		"northeast" : "/d/xiangyang/walle7",
		"westdown"  : "/d/xiangyang/walls6",
	]));
	set("objects", ([
		"/d/xiangyang/npc/ya"   : 1,
		"/d/xiangyang/npc/bing" : 2,
	]));
	set("coor/x", -260);
	set("coor/y", -140);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}
