inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
�����Ǽ��˵����š���Χ����ï�ܵ����֡������������
���Ͽ��븣�������Ͼ��Ǻų����õĺ��ݳ��ˡ�
LONG );
        set("exits", ([
                "north"    : __DIR__"jiaxing",
                "east"     : __DIR__"tieqiang",
                "south"    : __DIR__"qzroad4",
                "southwest": __DIR__"majiu2",
                "southeast": "/d/hangzhou/road1",
        ]));
        set("outdoors", "jiaxing");
        set("coor/x", 80);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}

