// July 31,2000
// Code by April
// yaofang.c

inherit ROOM;

void create()
{
	set("short","ҩ��");

	set("long",@LONG
����һ��ҩ��������һ���и�ҩ¯���������µĹ�Ĺʥҩ�����������ơ�
LONG);

	set("exits",([ 
		"east" : __DIR__"xiaowu1",
        ]));

	set("objects", ([
                __DIR__"obj/yaolu" : 1,
                __DIR__"npc/baiyi_yaofang" : 1,
        ]));

	setup();
}

