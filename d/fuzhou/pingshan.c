inherit ROOM;

void create()
{
	set("short", "������ɽ");
	set("long", @LONG
��ɽ�ų�Խ��ɽ����ب���ݳǱ���ɽ�»����£�������
������ɽ�ϸ���ųǣ������续��
LONG );
	set("exits", ([
                "southdown" : __DIR__"beidajie",
	]));
        set("objects", ([
                "/clone/npc/walker" : 1,
        ]));
	set("outdoors", "fuzhou");
	set("coor/x", 150);
	set("coor/y", -90);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

