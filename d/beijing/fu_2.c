#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����·");
        set("long", @LONG
�����Ǿ��ǵĻ���·�������ӷ����š�ֻҪ����������Ǯ����������ͻ���
��������к����κ��㲻֪�����£����������һ�£�������֪�����˾Ų���ʮ��
�����ڽִ���һ�Ҳ���Ŀ�ջ���ϱ���һ���޴��լԺ������ĳ����ٹ��˾�ס
�ĳ�����
LONG );
	set("exits", ([
		"south" : "/d/beijing/hai_men",
		"north" : "/d/beijing/fukedian",
		"east" : "/d/beijing/tianqiao",
		"west" : "/d/beijing/fu_1",
	]));
	set("objects", ([
		"/d/beijing/npc/haoke1" : 1,
		"/d/beijing/npc/girl2" : 1,
	]));
	set("outdoors", "beijing");
	set("coor/x", 20);
	set("coor/y", 320);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
