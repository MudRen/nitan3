// Room: /d/suzhou/beidajie1.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "�����");
        set("long", @LONG
������һ����æ�Ľֵ��ϣ����Ų�����ǻ������������ɫ�Ҵң�����˶���
�ϱ���ȥ��������һ�����ֵ�ͤ�ӡ���������һ��Ϸ԰�ӣ���ʱ�����к�������
�Ը��ص����ǽ����������ڶ�����һ���͵ꡣ������һ����ǡ�
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"      : "/d/suzhou/kedian",
		"west"      : "/d/suzhou/majiu",
		"north"     : "/d/suzhou/beidajie2",
		"south"     : "/d/suzhou/canlangting",
		"southwest" : "/d/suzhou/xiyuan",
	]));
	set("coor/x", 200);
	set("coor/y", -190);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

