// Room: /city/xidajie1.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ����������ʯ��ֵ���������ͷ���졣��������������ڣ�����ϡ
�٣������ĵغ������塣������һ�����ֵĹ㳡���ϱ��Ǳ�Ӫ�����߾��������ˡ�
LONG );
        set("outdoors", "city");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : "/d/city/guangchang",
		"south" : "/d/city/bingyindamen",
		"west"  : "/d/city/xidajie2",
		"north" : "/d/city/yamen",
	]));

	set("coor/x", -10);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
