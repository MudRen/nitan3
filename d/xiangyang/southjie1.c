// Room: /d/xiangyang/southjie1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�ϴ��");
        set("long", @LONG
����һ����������ʯ��ֵ������ϱ���ͷ���졣�ϱ߾�����ȸ�ţ���������
��㳡��������Ǯׯ���������������ڵ�Ψһһ��ѧ�á���Ȼ����ս�𲻶ϣ���
��������ѧ���ﴫ��ѧ�������ʵض�������
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	set("exits", ([
		"east"  : "/d/xiangyang/xuetang",
		"west"  : "/d/xiangyang/qianzhuang",
		"south" : "/d/xiangyang/southjie2",
		"north" : "/d/xiangyang/guangchang",
	]));
	set("coor/x", -290);
	set("coor/y", -100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
