// Room: /d/xiangyang/eastroad2.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "���ڴ��");
        set("long", @LONG
����һ����ʯ�̾͵Ĵ�֡�������һ�¸��ź�ɫ�����ߵĸ�ǽ������������
�سǴ�����ĸ�ۡ��Ժ������������������Ϊʮ��������Ϊ�����������ֿ���
�ž������Զ����������ر�࣬ǰ���������������ﲻ����������һ��ʮ�ֽ�
����ֻ�������������ǳ����֣�����������ʯ�̵Ľֵ���
LONG );
        set("outdoors", "xiangyang");

	set("no_clean_up", 0);
	set("exits", ([
		"east"  : "/d/xiangyang/zhonglie",
		"south" : "/d/xiangyang/eastroad1",
		"north" : "/d/xiangyang/jiekou2",
	]));
	set("coor/x", -270);
	set("coor/y", -70);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

