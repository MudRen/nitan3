// Room: /guiyun/shanlu2.c
// Date: Nov.18 1998 by Winder

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������һƬũ���Զ����һЩ��ׯ�������������𡣴�ׯ��Χ
��һ������أ�������һЩ���ڸ�����ũ�ˡ�
LONG );
        set("outdoors", "guiyun");
	set("exits", ([
		"northeast" : __DIR__"zhulin",	
		"southwest" : __DIR__"shanlu1",
		"southeast" : "/d/suzhou/road1",
	]));
        set("objects", ([
                "/d/guiyun/npc/qiuqianzhang" : 1,
        ]));
	set("coor/x", -210);
	set("coor/y", -150);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}