// Room: /d/suzhou/beidajie2.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "�����");
        set("long", @LONG
����һ����������ʯ�ֵ������ϱ���ͷ���졣�����Ǳ�����ͨ����⡣�ϱ�
�Եúܷ�æ��������һ�������¥����Ϊ����¥��������һ�����֣�������һ
����ֱ�Ĵ�֣�ʮ�ַ�����
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"      : "/d/suzhou/jiudian",
		"west"      : "/d/suzhou/zijinan",
		"north"     : "/d/suzhou/beimen",
		"south"     : "/d/suzhou/beidajie1",
	]));
	set("coor/x", 200);
	set("coor/y", -180);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

