inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
����һ����ʯ�������ͨ��������������ȥ��ֻ��һ��
��ɽ���ɹŰأ�һƬ��÷羰��
LONG);
        set("exits", ([
                "northeast" : __DIR__"road2",
                "southwest" : __DIR__"road4",
        ]));

        set("no_clean_up", 0);
        set("outdoors", "city");

        set("coor/x", -320);
	set("coor/y", -180);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}

