// Room: /d/suzhou/road3.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "��ʯ�ٵ�");
        set("long", @LONG
������һ����ʯ����ϣ����������ǳ���æ����ʱ������������ҴҶ�����
���������һЩС��̯���ƺ���һ�����С�����������ݳ��ˡ�
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"west"  : "/d/suzhou/road4",
		"east"  : "/d/suzhou/road2",
	]));
	set("coor/x", 150);
	set("coor/y", -210);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

