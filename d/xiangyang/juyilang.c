// Room: /d/xiangyang/juyilang.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "ˮ������");
        set("long", @LONG
��ʱһ����ֱ�����ȣ�������һ����ˮ����ˮӳ�ų��������������峺����
�ܿ���һЩ����������ȥ���������һ����԰��Բ�ڶ����������һ���᷿��
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	set("exits", ([
		"south" : "/d/xiangyang/juyihuayuan",
		"north" : "/d/xiangyang/juyiyuan",
	]));
	set("coor/x", -320);
	set("coor/y", -100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

