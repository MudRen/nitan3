inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
����һ����ʯ�����������Լ���Կ��������ǵĳ�ǽ����
����ȥ��ֻ��Ⱥɽ����������̣���֪ͨ�����
LONG);
        set("exits", ([
                "northeast" : __DIR__"road1",
                "southwest" : __DIR__"road3",
        ]));

        set("no_clean_up", 0);
        set("outdoors", "city");

        set("coor/x", -310);
	set("coor/y", -170);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}

