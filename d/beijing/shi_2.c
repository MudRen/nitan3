#include <room.h>
inherit ROOM;

void create()
{
	set("short", "���ı����");
        set("long", @LONG
�����Ǿ��ǵ����ı���֣���ʯ������·��ͨ�ϱ����ֵ��ϵ���������������
����һ�������Ĵ�ٵ������������ϣ������������ͨ�����ı���ֽ�������
��֡�
LONG );
       set("exits", ([
		"north" : "/d/beijing/shi_3",
		"south" : "/d/beijing/shi_1",
		"west" : "/d/beijing/guandao_1",
	]));
	set("objects", ([
		"/d/beijing/npc/boy1" : 1,
	]));
	set("outdoors", "beijing");
	set("coor/x", -60);
	set("coor/y", 310);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
