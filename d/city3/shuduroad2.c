// Room: shuduroad2.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "�񶼴��");
        set("long", @LONG
�������񶼴����������������ٳǡ��򶫾Ϳ��Ե��ᶽ���ˡ�ƽͷ������
�ˣ�·�ϴ������ͷ������ү�ǡ������ٱ�������״����Ź������ˡ�
LONG );
        set("outdoors", "chengdu");
	set("exits", ([
	    "west"  : "/d/city3/westroad2",
	    "east"  : "/d/city3/guangchang",
	]));
	set("objects", ([
	    "/d/city/npc/bing" : 2,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -440);
	set("coor/y", -180);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
