// Room: /city/beidajie2.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
����һ����������ʯ�ֵ������ϱ���ͷ���졣�����Ǳ�����ͨ����⡣�ϱ�
�Եúܷ�æ��������һ�������¥�󣬹��š�̫���ŷ硱���������Ŷ�������һ
�����ң�������¥�����ֲ�������������������ѧʿ���ֱʡ���������������
�㴹�����Ρ�������һ�����ӵ����������ƣ��Ǿ�������ѧ��֮������ͬ��
���������ˡ�
LONG );
        set("outdoors", "city");
        set("objects", ([
            "/d/city/npc/meipo" : 1,
        ]));
        set("exits", ([
                "east"  : "/d/city/zuixianlou",
                "south" : "/d/city/beidajie1",
                "west"  : "/d/city/wumiao",
                "north" : "/d/city/beimen",
        ]));
	set("coor/x", 0);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
