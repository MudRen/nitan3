inherit ROOM;

void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
������һ����ʯ����ϣ��˽�����������ֻ����ʱ������
����ҴҶ�����
LONG);
        set("outdoors", "lanzhou");
        set("exits", ([
                "northwest" : __DIR__"caroad3",
                "southeast" : __DIR__"caroad5",
        ]));

        set("coor/x", -500);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
