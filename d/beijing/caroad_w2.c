#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��������");
        set("long", @LONG
���ֵ�������������Ͻ��ǵĽ�ͨҪ������������ʯ���������ͷ���죬
�ֵ������˲��ϣ�������ʢ�������Զ��������������ԶԶ����������һ�¶�
�ߴ��ʵ�Ĺų�ǽ�������������찲�Ź㳡�ˡ�������ת�����������ˣ���Ҳ��
������ķ����ضΡ��ϱ߲����ﲻʱ����һ�������ӵĳ�������
LONG );
       set("exits", ([
		"west" : "/d/beijing/caroad_w1",
		"east" : "/d/beijing/cagc_w",
		"north" : "/d/beijing/xi_2",
		"south" : "/d/beijing/gaosheng",
	]));
	set("objects", ([
		"/d/beijing/npc/boy2" : 1,
		"/d/beijing/npc/richman1" : 1,
		"/d/beijing/npc/shusheng1" : 1,
	]));
	set("outdoors", "beijing");
	set("coor/x", -50);
	set("coor/y", 260);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
