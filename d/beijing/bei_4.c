#include <room.h>
inherit ROOM;

void create()
{
	set("short", "���������");
        set("long", @LONG
�����Ǳ����ǵ���������֣������Ĵ�����ϱ��������졣�ֵ��ϵ����˽�
��������о������������ٱ����������Լ�С��С����ߺ�������ϣ�����������
�У��������֡�����ͨ��������֡�
LONG );
       set("exits", ([
		"west" : "/d/beijing/bei_3",
		"north" : "/d/beijing/di_1",
		"south" : "/d/beijing/bei_2",
	]));
	set("objects", ([
		"/d/beijing/npc/youren" : 1,
	]));
	set("outdoors", "beijing");
	set("coor/x", -50);
	set("coor/y", 290);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
