// Room: wuguanchen.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "��ţ��ݶ���");
        set("long", @LONG
�����ǡ���ţ��ݡ����ڶ�����ʦ�������������¼��ܣ������Ṧ��������
���������мܣ�����צ��������������
LONG );
	set("objects", ([
		"/d/city3/npc/longquan" : 1,
	]));
        set("no_fight",0);
        set("no_steal",1);
        set("no_beg",1);
	set("exits", ([
		"north" : "/d/city3/wuguan",
	]));
	set("coor/x", -410);
	set("coor/y", -160);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
