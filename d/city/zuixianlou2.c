// Room: /city/zuixianlou2.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "����¥��¥");
	set("long", @LONG
����������¥�����Ž���Ķ�¥������ѧʿ��������ʫ������������������
������ã�������������Ȼ�����û��ƣ���������ˡ����ߵļ����᷿������
���ھٰ�ϲ�磬������͡�
LONG );
	set("item_desc", ([
		"paizi" : "������ۿ�Ѽ���ϵȻ���ơ�\n",
	]));
	set("objects", ([
		"/d/city/npc/xian" : 1,
		"/d/city/npc/guidao" : 1,
                /*CLASS_D("gaibang") + "/kongkong" : 1,*/
	]));
	set("exits", ([
		"down" : "/d/city/zuixianlou",
                "up"   : "/d/city/zuixianlou3",
		"east": "/d/city/zxlpath",
	]));
//	set("no_clean_up", 0);
	set("coor/x", 10);
	set("coor/y", 20);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}