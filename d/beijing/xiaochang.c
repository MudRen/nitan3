#include <room.h>
inherit ROOM;

void create()
{
	set("short", "У��");
        set("long", @LONG
�����Ǿ��Ǳ�Ӫ������һ����У����У�����������鵽�����ǹٱ������佫
��ָ�����жӲ�����һ�����ٱ������������������š�����Щ̫�����Ĵ���
���������Ǿ�������������������֡�
LONG );
	set("exits", ([
		"east" : "/d/beijing/wang_3",
	]));

	set("objects", ([
		"/d/beijing/npc/taijian" : 1,
		"/d/beijing/npc/bing1" : 2,
		"/d/beijing/npc/bing2" : 2,
		"/d/beijing/npc/bing3" : 2,
		"/d/beijing/npc/yuqian1" : 1,
	]));

	set("coor/x", -20);
	set("coor/y", 280);
	set("coor/z", 0);
	setup();
}

