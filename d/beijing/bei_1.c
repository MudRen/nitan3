#include <room.h>
inherit ROOM;

void create()
{
	set("short", "���������");
        set("long", @LONG
�����Ǳ����ǵ���������֣������Ĵ�����ϱ��������졣�ֵ��ϵ����˽�
��������о������������ٱ����������Լ�С��С����ߺ�������ϣ�����������
�У��������֡����ߵĽֵ�ͨ�����š�
LONG );
       set("exits", ([
		"east" : "/d/beijing/bei_2",
		"west" : "/d/beijing/ximenkou",
		"north" : "/d/beijing/bei_3",
		"south" : "/d/beijing/xi_1",
	]));
	set("objects", ([
		"/d/beijing/npc/youren" : 1,
	]));
	set("outdoors", "beijing");
	set("coor/x", -60);
	set("coor/y", 280);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
