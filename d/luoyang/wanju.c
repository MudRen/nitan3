inherit ROOM;

void create()
{
	set("short", "��ߵ�");
	set("long", @LONG
����һ�����յ꣬���治�󣬵�������ָ������ֹ���Ʒ���治���أ�
��ʽ������С���ˣ�������ɫ�Ĳ����ޣ�����һЩ��ľ�ĺ��������ɵ�С
���գ��������������С�����ǵ�ע�⣬�벻��Ҳ������档
LONG);
        set("outdoors", "luoyang");
        set("no_clean_up", 0);
        set("exits", ([
  		"south" : __DIR__"miaohui",
                "west" : __DIR__"fengwei",
                "east" : __DIR__"hutong2",
                "north" : __DIR__"roudian",
	]));
        set("objects", ([
                __DIR__"npc/kid1" : 1,
        ]));

	set("coor/x", -130);
	set("coor/y", 20);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
