// Room: yizhan.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
����ר�����ڴ��ݹٸ�����������վ���ߴ��ľ�����注��������û����
���ż��ͷ����Ķ���������Ϊ������һЩ���ݽ������ĵ���ʹֱ�ӳ���������
Լʱ�䡣�ڶ���ķ�����Ϊ���մ����ź��ġ�
LONG );
    set("objects", ([
        "/d/city/npc/yiguan":1,
    ]));

        set("exits", ([
                "north" : "/d/city/wumiao",
                "east" : "/d/city/youyi",
        ]));

        set("coor/x", -10);
	set("coor/y", 15);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
