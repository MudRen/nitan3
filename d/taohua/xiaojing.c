// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
����һ���ɴ�����ʯ�̳ɵ�С·���䲻��˵��һ����Ⱦ����Ҳ������
�࣬�����������˴�ɨ����������һ��С����������һ��ݵأ�������
һ�����֡�
LONG );
	set("exits", ([
                "west"  : __DIR__"caodi",
                "east"  : __DIR__"shulin",
                "north" : __DIR__"tuqiu",
		"south" : __DIR__"haitan",
        ]));

	set("outdoors", "taohua");

	setup();
}
