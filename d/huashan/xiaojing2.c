// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

inherit ROOM;

void create()
{
	set("short", "Сľ��ǰ");
	set("long", @LONG
һ���ª��Сľ��ǰ����������һ��С����
LONG );

	set("outdoors", "huashan");

	set("exits", ([ /* sizeof() == 1 */
	        "enter":__DIR__"xiaofang",
	        "northwest":__DIR__"shaluo",
	        "southwest":__DIR__"taogu",
        ]));

	setup();
	replace_program(ROOM);
}
 
