inherit ROOM;
#include <ansi.h>

void create()
{
	set("short","��������");
        set("long", @LONG
һ�������ûʵĴ�լԺ�����������ǰ����ͷ�ߴ��ʯʨ����ס�˴������ࡣ
�Ŷ�������һ�����ң�д�š����޵�һ��ʿ���ݸ����������֣������йٱ����أ�
�䱸ɭ�ϡ����Ϲ���������������Ȼд�š������֡�������ǵ�����һ�󳼣���
����Ϊ�����޵�һ��ʿ�������ݵĸ�ۡ��
LONG );
	set("exits", ([
		"north" : "/d/beijing/aofu_zoulang1",
		"south" : "/d/beijing/di_4",
	]));
	set("objects", ([
		 "/d/beijing/npc/shi_a" : 2,
	]));
	set("coor/x", -50);
	set("coor/y", 330);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (objectp(present("shi wei", environment(me))) && dir == "north")
		return notify_fail("��������һ����ס�㣬�����ȵ�������Ҫ�أ����������˵���������\n\n");
	return ::valid_leave(me, dir);
}