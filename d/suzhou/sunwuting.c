// Room: /d/suzhou/sunwuting.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "����ͤ");
        set("long", @LONG
������Ļ��������ϣ���һ��Сͤ�ӣ���Ϊ����ͤ���ഫ����ʱ����������
���ڴ�ѵ�����ӹ�Ů���������������輧�ֱ��ζӳ������ڳ輧�빬Ů�ǲ���
������������꣬���������ţ������������ն�����ھ�ǰ�������͡�����
������ͤ��
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"south"  : "/d/suzhou/zhenniang",
	]));
	set("coor/x", 200);
	set("coor/y", -160);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

