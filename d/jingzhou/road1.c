inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
����һ��������ֱ�Ĺٵ�������ݵ���ʮ���ۡ�����ͨ
��֬��֮��������������������ͨ�����������ޡ�
LONG);
        set("exits", ([
                "northeast" : "/d/xiangyang/caodi6",
                "southwest" : __DIR__"road2",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "city");

        set("coor/x", -300);
	set("coor/y", -160);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}

