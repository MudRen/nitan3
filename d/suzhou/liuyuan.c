// Room: /d/suzhou/liuyuan.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "��԰");
        set("long", @LONG
��԰�����ݵ�һ������֮һ�����Խṹ���ֽ��ܡ����û�����֡�װ�ξ���
���Ŷ����С����е�һ��԰��֮����
LONG );
	set("outdoors", "suzhou");
//	set("no_clean_up", 0);
	set("exits", ([
		"east"  : "/d/suzhou/nandajie2",
		"west"  : "/d/suzhou/hehuating",
	]));
	set("objects", ([
		"/d/suzhou/npc/lady1" : 1,
	]));
	set("coor/x", 190);
	set("coor/y", -240);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

