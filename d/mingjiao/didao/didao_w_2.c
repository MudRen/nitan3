// Code of ShenZhou
// Room: didao_w_2.c �ص���
// Zhangchi 7/00

inherit ROOM;
#include "didao.h"

void create()
{
	set("short", "�ص�");
	set("long", @LONG
����һ���ո��ڳɵĵص������������������졣
LONG
	);
	set("exits", ([
		"east": "/d/mingjiao/didao/didao_w_1",
]));
	
	set("cost", 1);
	set("valid_dig","west");

	setup();
//	replace_program(ROOM);
}

void init()
{
	int num=get_room("west");
	if (num >= 3)
		set("exits/west","/d/mingjiao/didao/didao_w_3");
	else
		delete("exits/west");

	add_action("do_dig","wa");
	add_action("do_dig","dig");
}

