inherit ROOM;

void create()
{
        set("short", "����С·");
        set("long", @LONG
����ɽ�������е�С·�����߳�������ĺ�������ֻ�ܿ�
��һ����ա�·���е�ʿ�ڷ�������������ͨ�����������
�߿ɻش����
LONG);
        set("outdoors", "wudang");
        set("exits", ([
                "west" : __DIR__"slxl2",
                "east" : __DIR__"wdroad10",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -330);
	set("coor/y", -180);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}