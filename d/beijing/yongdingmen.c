#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "������");
        set("long", @LONG
���������Ͻ��������ţ��ߴ�ĳ������Ϸ����š������š��������֣���ʵ
��̵Ĺų�ǽ�߸������š��������������վ�ż�����������ϸ�ļ��������
ÿ�춼������˾���������뾩�ǡ����������ţ�һ����ֱ�Ĵ�ٵ����ϱ�����
���졣�ϱߵĹٵ����������������������������ͨ�����ǵ����ġ�
LONG );
	set("exits", ([
		"north" : "/d/beijing/yongdingdao",
		"south" : "/d/beijing/road5",
	]));
	set("objects", ([
		"/d/beijing/npc/ducha" : 1,
		"/d/beijing/npc/bing1" : 2,
	]));
	set("outdoors", "beijing");
	set("coor/x", 30);
	set("coor/y", 280);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}