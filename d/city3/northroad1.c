// Room: northroad1.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "�����");
        set("long", @LONG
������Ǳ�����ˣ�����������һ�ֵֹֹ���ζ������̫���š�·�ܿ���
��ȴ���࣬�������ڻƻ��Ժ���������һ����֣�����ִӴ�һֱ����������
��һ�ұ����̣������������˶����ޱ��飬����������
LONG );
        set("outdoors", "chengdu");
	set("exits", ([
	    "east"       : "/d/city3/northroad2",
	    "southwest"  : "/d/city3/westroad3",
	    "northwest"  : "/d/city3/bingqidian",
	]));
	set("no_clean_up", 0);
	set("coor/x", -440);
	set("coor/y", -160);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
