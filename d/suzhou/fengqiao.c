// Room: /d/suzhou/fengqiao.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "����");
        set("long", @LONG
�µı�����һ���ſ׳ʰ�Բ�ĵ���ʯ��--���ţ��������˺ӵķ����塣�ŵ�
����������أ�����׻��أ�����أ��ϳ��������ء�
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"enter" : "/d/suzhou/hanshidian",
		"north" : "/d/suzhou/tielingguan",
	]));
	set("coor/x", 140);
	set("coor/y", -200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

