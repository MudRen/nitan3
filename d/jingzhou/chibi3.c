inherit ROOM;

void create()
{
        set("short", "С·");
        set("long", @LONG
����һ��ͨ�򽭱ߵ�С·��·ʮ�ֵĶ�����������С��һ
�㣬���ܾ����ĵģ�ֻ�ŵ�����質��������
LONG);
        set("outdoors", "jingzhou");
        set("exits", ([
                "northup" : __DIR__"chibi2",
		"southdown" : __DIR__"chibi4",                
        ]));
        set("coor/x", -350);
	set("coor/y", -220);
	set("coor/z", -10);
	setup();
        replace_program(ROOM);
} 
