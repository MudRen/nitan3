// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

inherit ROOM;

void create()
{
	set("short", "�ݵ�");
	set("long", @LONG
����һ�鼫��ͨ�Ĳݵأ�����ֻ��һЩѰ���洦�ɼ���Сʯ�Ӻ�С��
֦��������һ��С����������ï�ܵ����֣���������һ���ɰ��֣��ɰ���
��һ��С·�����򱱣���֪���ա�
LONG );
	 set("exits", ([
                "west"  : __DIR__"shucong",
                "east"  : __DIR__"xiaojing",
                "north" : __DIR__"songlin",
        ]));

	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}
