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
                "north" : __DIR__"caroad2",
                "southeast" : __DIR__"caroad4",
        ]));

        set("coor/x", -510);
	set("coor/y", 50);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
