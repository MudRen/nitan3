#include <room.h>
inherit ROOM;

void create()
{
	set("short", "������Ժ");
        set("long", @LONG
���ǿ����������Ŷ��ߵ�һ�������Ĵ�Ժ��Ժ�ڴ�ɨ�÷ǳ��ɾ�����Χ����
���˸��໨�ݣ�����������˴������У�������һ��ľ�����ȣ�ͨ�������Ĵ�����
LONG );
       set("exits", ([
		"west" : "/d/beijing/kangfu_men",
		"north" : "/d/beijing/kangfu_zoulang1",
	]));
	set("objects", ([
		"/d/beijing/npc/jiading_k" : 2,
		"/d/beijing/npc/yuanding" : 1,
	]));
	set("outdoors", "beijing");
	set("coor/x", -30);
	set("coor/y", 280);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}