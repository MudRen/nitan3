inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�������Ĵ��������������Ľ��磬�׳������ܡ�С��·��
���������������ũ������ֻţ�����ڳԲݡ�·�����˺�
�٣����ҴҸ�·��
LONG);
        set("outdoors", "wudang");
        set("exits", ([
                "east"      : __DIR__"wdroad8",
                "southeast" : __DIR__"wdroad9",
                "southwest" : "/d/emei/wdroad",
        ]));
        set("objects", ([
                "/d/wudang/npc/cow": 1,
        ]));
	set("coor/x", -330);
	set("coor/y", -160);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
