// Room: zhulin.c ����С��
// By Dumbness, 2003-4-28 21:34

inherit ROOM;
void create()
{
        set("short", "����С��");
        set("long", @LONG
�������ؿݻƵ���Ҷ����������ɳɳ�����죬����������ӳ�Ŵ���������ũ
��СԺ�����������������������ӵ���������
LONG
        );
        set("exits", ([ 
		"northeast" : __DIR__"nongshe",
		"southwest" : __DIR__"shanlu2",
	]));

	set("coor/x", -200);
	set("coor/y", -140);
	set("coor/z", 0);
	setup();
}
void init()
{
	add_action("do_go","go");
}

int do_go()
{
	if(random(3))
	{
		this_player()->move(this_object());
		return 1;
	}
}