// Room: wuguanxiao.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "��ţ�������");
        set("long", @LONG
�����ǡ���ţ��ݡ�����������ʦ�����ɽ������¼��ܣ������Ṧ��������
���������мܣ�����ָ��������������
LONG );
	set("objects", ([
		"/d/city3/npc/xiaofei" : 1,
	]));
        set("no_fight",0);
        set("no_steal",1);
        set("no_beg",1);
	set("no_clean_up", 0);
	set("exits", ([
		"east" : "/d/city3/wuguan",
	]));
	set("coor/x", -420);
	set("coor/y", -150);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
