inherit ROOM;
#include <ansi.h>

void create()
{
	set("short","���ι�����Ժ");
        set("long", @LONG
���ǽ��ź��һ������Ļ�԰��������һ���᷿��������һ��������ͨ����
�ι����Ļ����������Ǻ��ι����Ĵ��ţ�������Ǵ����ˡ�
LONG );
	set("exits", ([
		"north" : "/d/beijing/hai_men",
		"south" : "/d/beijing/hai_dating",
		"east" : "/d/beijing/hai_huating",
		"west" : "/d/beijing/hai_fang",
	]));
	set("objects", ([
		"/d/beijing/npc/yuqian1" : 1,
		"/d/beijing/npc/yuqian2" : 1,
	]));

	set("coor/x", 20);
	set("coor/y", 300);
	set("coor/z", 0);
	setup();
}