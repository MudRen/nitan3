// Room: /city/dongdajie1.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "�����");
        set("long", @LONG
����һ����������ʯ��ֵ���������ͷ���졣���߲�ʱ�ش�������ײ������
�����������ӡ�������һ�����ӵ�Ժ�ӣ������εĴ����Ϸ�д�š���¹��Ժ����
���̽���֣��Ծ����������治ʱ�ش���ѧ��������ٴ�Ķ��������ϱ���һ��
�ӻ��̡�
LONG );
        set("outdoors", "city");
	set("exits", ([
		"east" : "/d/city/dongdajie2",
		"south" : "/d/city/zahuopu",
		"west" : "/d/city/guangchang",
		"north" : "/d/city/shuyuan",
	]));

	set("objects", ([
		"/clone/npc/xunbu" : 1,
	]));
	set("coor/x", 10);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
