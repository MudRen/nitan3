// Room: /city/dayuan.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "������Ժ");
	set("long", @LONG
���߽���Ժ��ӭ����һ����ɽˮ�أ����ϰ���һ�����ι�״��ʯͷ����˵��
���껨ʯ�ٵ���ʯ��ˮ�ص����������˻��ݡ�������һ�û����������дУ��ڸ�
�˴���Ժ�ӣ��Ե���ɭ�ֲ���һ�������ߵ�ͨ����Ժ���м����Ҷ����ء�
LONG );
	set("exits", ([
		"north" : "/d/city/houyuan",
		"south" : "/d/city/caizhu",
	]));
	set("objects", ([
		"/d/city/npc/guanjia" : 1,
		"/d/city/npc/jiading" : 2,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -20);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
