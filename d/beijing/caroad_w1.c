#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��������");
        set("long", @LONG
���ֵ�������������Ͻ��ǵĽ�ͨҪ������������ʯ���������ͷ���죬
�ֵ������˲��ϣ�������ʢ�������Զ��������������ԶԶ����������һ�¶�
�ߴ��ʵ�Ĺų�ǽ�������������찲�Ź㳡�ˡ������Ƿ�������������߲�Զ��
��һ�ҹ�ģ����Ŀ͵ꡣ����Ľֵ�����խ������������ͬ�ĺ�ͬ���ˡ�
LONG );
       set("exits", ([
		"east" : "/d/beijing/caroad_w2",
		"west" : "/d/beijing/kedian",
		"north" : "/d/beijing/xi_1",
		"south" : "/d/beijing/yangliu1",
	]));
	set("objects", ([
		"/d/beijing/npc/kid1" : 1,
		"/d/beijing/npc/haoke1" : 1,
	]));
	set("outdoors", "beijing");
	set("coor/x", -60);
	set("coor/y", 260);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
