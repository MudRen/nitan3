// Room: /d/suzhou/hehuating.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "�ɻ���");
        set("long", @LONG
�ɻ������������������䣬��ָ�ˬ������ȡ���䣺��һˮ�����̣�ǧ����
��졻֮ʫ�⡣��ǰ����ƽ̨���ٺɳأ�Ϊ�����ͺ�����ʤ�����ʳơ��ɻ���
���������л�̨ͥԺ����ʯ�������Գ�һ����
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : "/d/suzhou/liuyuan",
		"west"  : "/d/suzhou/gumujiaohe",
                "north"  : "/d/suzhou/zsh_szdamen",
	]));
	set("coor/x", 180);
	set("coor/y", -240);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

