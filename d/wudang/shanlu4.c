inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
�����ڵ�ɽ��·���ϣ�·�����Ҹ���һ����������������
������ɽ��ɽ��������ȥ����������ľ�е�����������Ļ�С�
LONG);
        set("exits", ([
                "northdown": __DIR__"shanlu3",
                "southup"  : __DIR__"taiziyan",
        ]));
        set("outdoors", "wudang");
        set("no_clean_up", 0);
	set("coor/x", -350);
	set("coor/y", -300);
	set("coor/z", 100);
	setup();
        replace_program(ROOM);
}