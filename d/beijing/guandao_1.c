#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��ٵ�");
        set("long", @LONG
������һ����������Ĵ�ٵ��ϡ���ʱ��������������߷ɳ۶���������
һ·��������·��������������������֡�
LONG );
       set("exits", ([
		"east" : "/d/beijing/shi_2",
		"north" : "/d/beijing/guandao_2",
	]));
	set("objects", ([
		"/d/beijing/npc/tangzi" : 1,
	]));
	set("outdoors", "beijing");
	set("coor/x", -70);
	set("coor/y", 310);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
