#include <room.h>
inherit ROOM;

void create()
{
	set("short", "���������");
        set("long", @LONG
�����Ǳ����ǵ���������֣������Ĵ�����ϱ��������졣�ֵ��ϵ����˽�
��������о������������ٱ����������Լ�С��С����ߺ�������ϣ�����������
�У��������֡����������ֵı��ֲ��У������������ı�����ˡ�
LONG );
       set("exits", ([
		"east" : "/d/beijing/bei_4",
		"west" : "/d/beijing/caishi",
		"north" : "/d/beijing/shi_1",
		"south" : "/d/beijing/bei_1",
	]));
	set("objects", ([
		"/d/beijing/npc/girl3" : 1,
	]));
	set("outdoors", "beijing");
	set("coor/x", -60);
	set("coor/y", 290);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
