inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
�����ڵ�ɽ��·���ϣ�·�����Ҹ���һ����������������
������ɽ��ɽ��������ȥ����������ľ�е�����������Ļ�С�
LONG);
        set("exits", ([
                "west" : __DIR__"guangchang",
                "east" : __DIR__"shanlu3",
        ]));
        set("outdoors", "wudang");
        set("no_clean_up", 0);
	set("coor/x", -360);
	set("coor/y", -290);
	set("coor/z", 90);
	setup();
        replace_program(ROOM);
}