#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "���Ӽ�");
        set("long", @LONG
������Ǿ��ǵĹ��Ӽࡣ���Ӽ��ǳ�͢�����˲ŵĵط����߸ߵ͵͵�������
�����š������ﲻʱ���Կ�������������ѧ��ģ�����˴���������ʲô���⣬��
��һЩ������������üͷ�Ҵҵ��߹���������˼����ʲô���⡣[2;37;0m
LONG );
        set("exits", ([
                "south" : "/d/beijing/dong_2",
        ]));
        set("objects", ([
                "/d/beijing/npc/shusheng1" : 3,
        ]));
        set("outdoors", "beijing");
	set("coor/x", -20);
	set("coor/y", 330);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
