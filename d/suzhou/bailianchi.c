// Room: /d/suzhou/bailianchi.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "������");
        set("long", @LONG
������λ�ڶ���ͤ�ı��棬��������ǧҶ���������ϼܲ������ţ��ഫ����
�������ʩ���ڴ˲����ͺɡ�
LONG );
	set("outdoors", "suzhou");
//	set("no_clean_up", 0);
	set("exits", ([
		"south" : "/d/suzhou/erxianting",
	]));
	set("objects", ([
		"/d/suzhou/npc/lady2" : 1,
	]));
	set("coor/x", 200);
	set("coor/y", -180);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

