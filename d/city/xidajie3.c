inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
������������ϣ��е�����Ľ���Ҫ�ȱ𴦵ĸɾ������ࡣ�����Ϊ
�������š���Ӫ���ܱ�����Ե�ʣ������Ƕ�ϲ��ס��������߾����ĵ�
û�м������ˣ�������������ͨ�����⡣�ϱ���һ���ھ֣����ߵ�¥��д
�š��챦�󡱣����������Ƕ�����ǲ�ĺ�ȥ����
LONG );
        set("outdoors", "city");
        set("no_clean_up", 0);
        set("exits", ([
                "east"  : __DIR__"xidajie2",
                "south" : __DIR__"biaoju",
                "west"  : __DIR__"ximen",
                "north" : __DIR__"tianbaoge",
        ]));

        set("objects", ([
                "/clone/npc/walker" : 1,
                __DIR__"npc/gongzi" : 1,
        ]));

	set("coor/x", -30);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
