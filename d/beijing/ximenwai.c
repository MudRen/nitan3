inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����Ǳ������������⡣����������ɷ�����֡�
LONG );
        set("exits", ([
                "east" : "/d/beijing/xichengmen",
                "west" : "/d/heimuya/road3",
                "north" : "/d/beijing/liandan_lin1",
                "south" : "/d/beijing/liandan_lin2",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "beijing");
	set("coor/x", -90);
	set("coor/y", 280);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
