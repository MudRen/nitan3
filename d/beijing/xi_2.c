#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
        set("long", @LONG
�����������������Ҳ�Ǿ�����ķ����ضΡ�����������ʮ�����֡�������
Ȼ�࣬����ֻ�Ĵ����ƣ��Ŷ������������Ҳ��������ʲô�����ұ�Ʈ��һ��
ŨŨ��ҩ����ζ��������������ġ��ش��á�ҩ���ˡ��������˴ӱ�����������
������Ҳͦ���֡��ϱ����Ǿ��������������֡�
LONG );
       set("exits", ([
		"east" : "/d/beijing/huichuntang",
		"west" : "/d/beijing/xi_1",
		"north" : "/d/beijing/bei_2",
		"south" : "/d/beijing/caroad_w2",
	]));
	set("objects", ([
		"/d/beijing/npc/boy3" : 1,
		"/d/beijing/npc/xiaofan" : 1,
		"/d/beijing/npc/girl2" : 1,
	]));
	set("outdoors", "beijing");
	set("coor/x", -50);
	set("coor/y", 270);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
