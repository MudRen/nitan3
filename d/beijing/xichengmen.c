#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "������");
        set("long", @LONG
�����Ǿ��ǵ������ţ���ʵ��̵Ĺų�ǽ�߸������š��������������վ��
������������ϸ�ļ��������ÿ�춼������˾���������뾩�ǡ����������ţ�
һ����ֱ�Ĵ�ٵ������������졣���ߵĹٵ��������������������������
��ͨ�����ǵ���������֡�
LONG );
	set("exits", ([
		"east" : "/d/beijing/ximenkou",
                "west" : "/d/beijing/ximenwai",
	]));
	set("objects", ([
		"/d/beijing/npc/ducha" : 1,
		"/d/beijing/npc/bing1" : 2,
		"/d/beijing/npc/tangzi" : 1,
	]));
	set("outdoors", "beijing");
	set("coor/x", -80);
	set("coor/y", 280);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
