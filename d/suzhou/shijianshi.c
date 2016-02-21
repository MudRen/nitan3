// Room: /d/suzhou/shijianshi.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "�Խ�ʯ");
        set("long", @LONG
��ɽ���������Խ�ʯ������Բ�Σ���������������ѵ��ѷ죬�ഫ�����á�
�ɽ�������Īа������Ϊ�����������ʯ������ʯ�Կ���Ԫ��������ʫ�䡺��
��һ�������ˮ��������ΰ���󣬲�ն�Ը�ͷ������ʫ�䡣
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"northeast" : "/d/suzhou/zhenniang",
		"south"     : "/d/suzhou/qianrenshi",
		"north"     : "/d/suzhou/zhenshi",
		"westdown"  : "/d/suzhou/wanjing",
	]));
	set("objects", ([
		"/d/taishan/npc/jian-ke" : 1,
	]));
	set("coor/x", 190);
	set("coor/y", -180);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

