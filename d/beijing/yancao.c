#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�̲ݵ�");
        set("long", @LONG
�������������������������˵����ѵ���Ʒ�����������ǳɰٳ�ǧ���ķ�
����ȥ���������������е�����ķ�ʽ�����̡�������Զ��ס�������к������ģ�
����������ϰ屻��������ͷ�ϡ������ĲƵ������Ǳ�������ġ�
LONG );
       set("exits", ([
		"north" : "/d/beijing/caroad_e2",
	]));
	set("objects", ([
		"/d/beijing/npc/old2" : 1,
	]));
	set("outdoors", "beijing");
        set("no_fight",1);
	setup();
	replace_program(ROOM);
}

