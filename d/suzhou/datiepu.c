// Room: /d/suzhou/datiepu.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "������");
        set("long", @LONG
����һ�Ҽ�ª�Ĵ����̣�����һ����¯��¯�������࣬�������ˡ�һλ��
��������ͷ�󺹻�����������ר����־���ڴ�����ǽ�Ƕ��������깤��δ�깤��
�������
LONG );
	set("exits", ([
		"north" : "/d/suzhou/dongdajie2",
	]));
        set("objects", ([
		"/d/city/npc/smith": 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", 240);
	set("coor/y", -210);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

