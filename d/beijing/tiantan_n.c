#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��̳����");
        set("long", @LONG
��������̳�ı��ţ�վ�������Ѿ����������������̳�м�������ߵĽ���
���������ഫÿ���ʵۼ���֮�����ǵ�����������������λߵͷ����л�⡣
����̳����������ͨ�������ķ����š�
LONG );
	set("exits", ([
		"south" : "/d/beijing/tiantan",
		"north" : "/d/beijing/tianqiao",
	]));
	set("objects", ([
		"/d/beijing/npc/girl2" : 1,
	]));
	set("outdoors", "beijing");
	set("coor/x", 30);
	set("coor/y", 310);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
