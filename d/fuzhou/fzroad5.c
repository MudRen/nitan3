// Room: /d/fuzhou/fzroad5.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "���ӹŵ�");
	set("long", @LONG
����������������ɽ�������������Ĺ���̣����ղ�����⡣
ɽ�ж������޳�û�޳�����·������·����һ���Ẻ����������
���ۿ����㡣
LONG );
	set("exits", ([
		"westup"    : __DIR__"fzroad6",
		"northeast" : __DIR__"fzroad4",
	]));
        set("objects", ([
		"/d/qingcheng/npc/fang" : 1,
	]));
	set("outdoors", "fuzhou");
	set("coor/x", 60);
	set("coor/y", -110);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

