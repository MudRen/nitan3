// Room: wuguanliu.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "��ţ����Ĳ�");
        set("long", @LONG
�����ǡ���ţ��ݡ������Ĳ���ʦ���������������¼��ܣ������Ṧ������
�ڹ��������мܣ������Ʒ�������������
LONG );
	set("objects", ([
		"/d/city3/npc/liuhongying" : 1,
	]));
        set("no_fight",0);
        set("no_steal",1);
        set("no_beg",1);
	set("no_clean_up", 0);
	set("exits", ([
		"south" : "/d/city3/wuguan",
	]));
	set("coor/x", -410);
	set("coor/y", -140);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
