// Room: /city/datiepu.c
// sun
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
����һ�Ҽ�ª�Ĵ����̣����İ���һ����¯��¯��������յ�һƬͨ�죬һ
�߽�ȥ�͸е�������ȡ�ǽ�Ƕ��������깤��δ�깤�Ĳ˵���������������ذ�ס�
���׵��һλ������ͷ�󺹻�����������ר����־���ڴ�����
LONG
        );

        set("exits", ([
                "south" : "/d/city/wofang",
                "north" : "/d/city/dongdajie2",
        ]));
        set("objects", ([
                 "/d/city/npc/smith": 1,]));

	set("coor/x", 20);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{

        if ( me->query_temp("smith_times") && dir == "north" )
                return notify_fail("���Ѿ���Ӧ�����������ˣ���Ҫ�������ܡ�\n");

        if ( !me->query_temp("smith_times") && dir == "south" )
                return notify_fail("��Ҫ�ڱ��˼����Ҵڣ�\n");

        return ::valid_leave(me, dir);
}