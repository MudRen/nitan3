#include <room.h>
inherit ROOM;

void create()
{
	set("short", "���������");
        set("long", @LONG
�����Ǳ����ǵ���������֣������Ĵ�����ϱ��������졣�ֵ��ϵ����˽�
��������о������������ٱ����������Լ�С��С����ߺ�������ϣ�����������
�У��������֡������ߵ�ͨ�����ţ�������һ�������ûʵĽ������Ŷ�������һ
�����ң�д�š������������ĸ����֡�
LONG );
       set("exits", ([
		"east" : "/d/beijing/kangfu_men",
		"west" : "/d/beijing/bei_1",
		"north" : "/d/beijing/bei_4",
		"south" : "/d/beijing/xi_2",
	]));
	set("outdoors", "beijing");
	set("coor/x", -50);
	set("coor/y", 280);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
