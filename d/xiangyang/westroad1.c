// Room: /d/xiangyang/westroad1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "���ڴ��");
        set("long", @LONG
����һ����ʯ�̾͵Ĵ�֡�������������������һ���ܸߵĲ�¥��������һ
�¸��ź�ɫ�����ߵĸ�ǽ�������ǹ�����Ժ�����������������ֺŵĿ͵꣬����
����ʯ�̵Ĵ�֡�
LONG );
        set("outdoors", "xiangyang");

	set("no_clean_up", 0);
	set("exits", ([
		"west"  : "/d/xiangyang/kedian",
		"south" : "/d/xiangyang/westjie2",
		"north" : "/d/xiangyang/westroad2",
	]));
	set("coor/x", -320);
	set("coor/y", -70);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

