inherit ROOM;

void create()
{
        set("short", "��ͷ��");
        set("long", @LONG
һ��޴����ʯ����ȥ����һ����ͷ���Ŵ���Ѫ������
�������������ڲ�ľ���С�
LONG);
        set("objects", ([
                "/clone/quarry/laohu" : 1,
        ]));
        set("exits", ([
                "northdown" : __DIR__"wulaofeng",
                "southup"   : __DIR__"chaotiangong",
        ]));

        set("outdoors", "wudang");
	set("coor/x", -350);
	set("coor/y", -360);
	set("coor/z", 140);
	setup();
        replace_program(ROOM);
}