// Room: /d/xiangyang/westroad2.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "���ڴ��");
        set("long", @LONG
����һ����ʯ�̾͵Ĵ�֡�������ʮ�ֽֿڡ�������������������һ���ܸ�
�Ĳ�¥��������һ�¸��ź�ɫ�����ߵĸ�ǽ�������ǹ�����Ժ����������������
�¿���һ����꣬��˵�������򵽺ܺõ��顣
LONG );
        set("outdoors", "xiangyang");

	set("no_clean_up", 0);
	set("exits", ([
		"west"  : "/d/xiangyang/shudian",
		"south" : "/d/xiangyang/westroad1",
		"north" : "/d/xiangyang/jiekou1",
	]));
	set("coor/x", -320);
	set("coor/y", -60);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

