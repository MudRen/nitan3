inherit ROOM;

void create()
{
        set("short", "��ʯ·");
        set("long", @LONG
����һ������ʯ�̳ɵ�·����Ȼ��Щ������ȴ�ܿ�������
ȥ���ǳ����ˡ�����ǰ��һƬ��ʯ����ס��ȥ·����˵�ǵ���
�����Ϊ����ֹ���׷�϶���ġ�
LONG);
	set("objects", ([
		__DIR__"npc/boy" : 1,
		__DIR__"npc/girl" : 1,
	]));
        set("exits", ([
                "north" : __DIR__"nanshilu",
                "south" : "/d/kunming/road1",
        ]));

        set("no_clean_up", 0);
        set("outdoors", "jingzhou");

        set("coor/x", -450);
	set("coor/y", -260);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}

