inherit ROOM;
#include <ansi.h>

void create()
{
	set("short","��������");
        set("long", @LONG
������ǿ������������������ڡ��������һ�������ûʵľ�լԺ������
�����ǰ��������������ͷ�ߴ��ʯʨ�ӡ����Ϲ���������������Ȼд�Ŵ���
�������֡���ǰվ�������ᵶ�������������ע���Ź��������ˡ�
LONG );
	set("exits", ([
		"west" : "/d/beijing/bei_2",
		"east" : "/d/beijing/kangfu_dayuan",
	]));
	set("objects", ([
		"/d/beijing/npc/shi_k" : 2,
	]));
	set("coor/x", -40);
	set("coor/y", 280);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (objectp(present("shi wei", environment(me))) && dir == "east")
		return notify_fail("��������һ����ס�㣬�����ȵ�������Ҫ�أ����������˵���������\n\n");
	return ::valid_leave(me, dir);
}