#include <room.h>
inherit ROOM;

void create()
{
	set("short", "������");
        set("long", @LONG
�����ڳ�������ĳ������ϣ���·��������������������֣���ʱ��������
�������߷ɳ۶���������һ·���������߾��ǳ������ˣ����߲�Զ���Ƿ�����
��������֣��������У�ʮ�����֡�
LONG );
       set("exits", ([
		"west" : "/d/beijing/chaoyang_dao1",
		"east" : "/d/beijing/chaoyangmen",
	]));
	set("objects", ([
                "/kungfu/class/hu/pingsi" : 1,
		"/d/beijing/npc/tiaofu" : 1,
	]));
	set("outdoors", "beijing");
	set("coor/x", 20);
	set("coor/y", 280);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
