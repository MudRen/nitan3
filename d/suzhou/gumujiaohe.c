// Room: /d/suzhou/gumujiaohe.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "��ľ��ڭ");
        set("long", @LONG
��ľ��ڭ�ںɻ��������棬һ�Ų�ͬͼ����©����ʹ��͸��©������������
����ˮ��ɽɫ�͸ߵʹ����¥�󣬴˴��;����С��Ʋ���Ӱ��֮��������׿�
��ң������������ɪ¥������һ�֡�ͥԺ��������Ϳռ䲻��֮�С�
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"      : "/d/suzhou/hehuating",
		"southwest" : "/d/suzhou/chitang",
	]));
	set("coor/x", 170);
	set("coor/y", -240);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

