#include <room.h>
inherit ROOM;

void create()
{
	set("short", "Τ����Ժ");
        set("long", @LONG
����¹����������ǰ���һ�������Ĵ�Ժ����Ժ����ֲ�Ÿ��໨�ݣ���ɽˮ
�أ���¥��̨���ǳ�������Ժ�ڴ�ɨ�÷ǳ��ɾ���Τ��������˴������У�����
��һ��ľ�����ȣ�ͨ�������Ĵ�����
LONG );
       set("exits", ([
		"south" : "/d/beijing/weifu_zoulang1",
		"north" : "/d/beijing/weifu_zoulang2",
	]));
	set("objects", ([
		"/d/beijing/npc/yuanding" : 1,
	]));
	set("outdoors", "beijing");
	set("coor/x", -30);
	set("coor/y", 280);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
