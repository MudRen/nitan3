inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������һƬ���̵��������У�����ȫ����������Χ�����
����ʧ�˷��򡣶��Բ�ʱ����һ�����ö������������������
�е��Ŀ�������
LONG);
        set("outdoors", "jingzhou");

	set("exits", ([
		"northup" : __DIR__"shijie",
		"south" : __DIR__"zizhulin1",
	]));
        set("objects", ([
                "/clone/npc/walker" : 1,
        ]));
	set("coor/x", -450);
	set("coor/y", -240);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

