// Room: /d/xiangyang/guofuhuayuan.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "������԰");
        set("long", @LONG
�����ǹ����ĺ�԰��԰�ڼ�ɽ��������������һЩ���񣬶����Ǽ���֦Ҷ
ïʢ��ľ�ʻ�������һ�߽��������ŵ�һ�������µġ������Ļ��㡣
LONG );
	set("exits", ([
		"east"  : "/d/xiangyang/guofuwoshi",
		"west"  : "/d/xiangyang/guofukefang",
		"south" : "/d/xiangyang/guofuting",
		"north" : "/d/xiangyang/guofushufang",
	]));
	set("objects", ([
                // CLASS_D("taohua") + "/rong" : 1,
	]));
	set("coor/x", -300);
	set("coor/y", -50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

