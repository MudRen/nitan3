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
                "west" : __DIR__"caroad5",
                "south" : __DIR__"caroad7",
        ]));

        set("coor/x", -480);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
