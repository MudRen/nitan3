inherit ROOM;

void create()
{
        set("short", "�ּ��");
        set("long", @LONG
������һ���ּ�С���������������ѡ�����������һ����
��·������ĵ�·Ҫ��һЩ��
LONG );
        set("outdoors", "hengyang");

        set("exits", ([
                "northwest" :"/d/wudang/wdroad9",
                "south"     : __DIR__"hsroad7",
        ]));

        set("coor/x", -40);
	set("coor/y", -80);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
