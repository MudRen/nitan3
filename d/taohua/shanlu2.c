// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
ɽ·�ߵ������ѷǳ����ͣ�ɽ·Ҳ���������������������ò����죬
ÿ�߼�����Ҫ�Ѳ���������̧ͷ��ȥ���������Ƿ嶥��
LONG );
	 set("exits", ([
                "southdown" : __DIR__"shanlu1",
                "northup"   : __DIR__"tzfeng",
        ]));

	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}
