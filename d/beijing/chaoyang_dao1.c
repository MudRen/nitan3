#include <room.h>
inherit ROOM;

void create()
{
	set("short", "������");
        set("long", @LONG
�����ڳ�������ĳ������ϣ���·��������������������֣���ʱ��������
�������߷ɳ۶���������һ·���������߲�Զ�����ǳ������ˣ������Ƿ�����
��������֣��������У�ʮ�����֡�
LONG );
       set("exits", ([
		"west" : "/d/beijing/wang_4",
		"east" : "/d/beijing/chaoyang_dao2",
	]));
	set("objects", ([
		"/d/beijing/npc/tangzi" : 1,
	]));
	set("outdoors", "beijing");
	set("coor/x", 10);
	set("coor/y", 280);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
