inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
�����Ǹ������ţ��ƺ�ûʲô��������Ҳû�йٱ���������ء�
LONG );
	set("exits", ([
		"south" : __DIR__"zhongzhou",
                "north" : __DIR__"nanmendou",
	]));
        set("objects", ([
                "/clone/npc/walker" : 1,
        ]));
	set("outdoors", "fuzhou");
	set("coor/x", 150);
	set("coor/y", -140);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

