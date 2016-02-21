#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "���");
        set("long", @LONG
�������Ͻ��Ǳ��߿������ŵ�һ�������Ĵ�����Ϸ���Զ���Ǿ��ǵ�������
�ˣ���ʵ��̵Ĺų�ǽ�߸������š�ÿ�춼������˾�������������뾩�ǡ���
���򾭹���̳ͨ�����ǵ����ġ����������޼���ı����ֶ档
LONG );
	set("exits", ([
		"north" : "/d/beijing/tiantan",
		"south" : "/d/beijing/yongdingmen",
        "east" : "/d/beijing/wjb_bjwfb",
	]));
	set("objects", ([
		"/d/beijing/npc/tiaofu" : 1,
		"/d/beijing/npc/kid1" : 1,
		"/d/beijing/npc/tangzi" : 1,
	]));
	set("outdoors", "beijing");
	set("coor/x", 30);
	set("coor/y", 290);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
