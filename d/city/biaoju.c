// Room: /city/biaoju.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "�����ھ�");
	set("long", @LONG
������һ���ṹ��ΰ�Ľ���ǰ������ʯ̳�ϸ�����һ�����ɶ�ߵ���
�ˣ���������Ʈ����������ý�������һͷ������צ��ʨ�ӣ�ʨ����ͷ
��һֻ������衣����������д�š������ھ֡��ĸ����֣�������������
���Ƿ�����ڴ������������ʣ�������ͷ���Ű��ء�����ͷ��������˵Ц��
LONG );

	set("exits", ([
		"south" : __DIR__"zhengting",
                "north" : __DIR__"xidajie3",
	]));
	set("objects", ([
		__DIR__"npc/biaotou" : 2,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -30);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
