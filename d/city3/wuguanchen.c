// Room: wuguanchen.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "��ţ���һ��");
        set("long", @LONG
�����ǡ���ţ��ݡ�����һ����ʦ����䰽������¼��ܣ������Ṧ��������
���������мܣ�����ȭ���������ȷ�������������
LONG );
	set("objects", ([
		"/d/city3/npc/chenhu" : 1,
	]));
        set("no_fight",0);
        set("no_steal",1);
        set("no_beg",1);
	set("no_clean_up", 0);
	set("exits", ([
		"west" : "/d/city3/wuguan",
	]));
	set("coor/x", -400);
	set("coor/y", -150);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
