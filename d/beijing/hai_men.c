inherit ROOM;
#include <ansi.h>

void create()
{
	set("short","���ι���");
        set("long", @LONG
������һ����լ��ǰ����լ�Ĵ��Ž����ر��ţ����Ϲ���һ����ң�����д
�š����ι������ĸ����֣���Ȼ��¹������ͬ�ǹ����������Ǵ�С����ͷȴ��
��ͬ�������Ҷ����ǡ����ι����������Ǻ��֣�һ��Ҳ�����ۡ�
LONG );
	set("exits", ([
		"north" : "/d/beijing/fu_2",
		"south" : "/d/beijing/hai_dayuan",
	]));

	set("coor/x", 20);
	set("coor/y", 310);
	set("coor/z", 0);
	setup();
}