// Room: /d/suzhou/xidajie1.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "�����");
        set("long", @LONG
����һ����������ʯ��ֵ���������ͷ���졣��������������ڣ�����ϡ
�٣������ĵغ������塣�����ǲ���ͤ�ͱ����ţ��ϱ��Ǳ�Ӫ�����߾��������ˡ�
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"west"      : "/d/suzhou/xidajie2",
		"north"     : "/d/suzhou/yamen",
		"south"     : "/d/suzhou/bingying",
		"southeast" : "/d/suzhou/baodaiqiao",
		"northeast" : "/d/suzhou/canlangting",
		"northwest" : "/d/suzhou/yunhematou",
	]));
	set("coor/x", 190);
	set("coor/y", -210);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

