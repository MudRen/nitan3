inherit ROOM;

void create()
{
        set("short", "��ͤ");
        set("long", @LONG
����һ��·�ߵ�С��ͤ����ɽ·���˳��ڴ˴�ЪЪ�š�ͤ
�����м������Ӻͼ�֧���ʡ���Χ��һƬ���֡�
LONG );
        set("exits", ([
                "west" : __DIR__"qzroad4",
        ]));
        set("objects", ([
                CLASS_D("riyue") + "/xiang" : 1,
        ]));
        set("outdoors", "quanzhou");
        set("coor/x", 90);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}

