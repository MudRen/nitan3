// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
����һ��ƽ����ɽ·��������������ȥ��ɽ·������ֲ���ɰ���֮��
�ĸߴ���ľ�������Ը��ֺ���ҩ�ݣ�����֥������֮�ࡣԽ�����У�ɽ·
Խ�����ͣ����Һû�����̫���ߡ�
LONG );
	 set("exits", ([
                "south"   : __DIR__"citeng",
                "northup" : __DIR__"shanlu2",
        ]));

	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}
