#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
        set("long", @LONG
��һ�ߵ�����������������ɸ��ָ���������Ľ�����֯�ɵĶ�������
��������Կ����ܶྩ�������Ż����Ĺ��Ӹ�������ﾫ��ϸѡ��һ������ͷ��
�棬ƽʱ���¿������Ϳ���Щ�����Ż����ӡ�
LONG );
       set("exits", ([
		"east" : "/d/beijing/xi_1",
                "west" : "/d/beijing/majiu",
	]));
	set("objects", ([
		"/d/beijing/npc/richman1" : 1,
		"/d/beijing/npc/shusheng2" : 1,
	]));
	set("outdoors", "beijing");
	set("coor/x", -70);
	set("coor/y", 270);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
