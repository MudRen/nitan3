// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һƬ�������ܵ����ԣ�֦Ҷ�������أ�һ����ȥ�����˻�������
��������ȫ��������档ͻȻ��ǰ��ԼĪ����Զ��һ���۾���ӨӨ������
���⡣����һ���������������������۾�ȴһ���Ͳ����ˡ����е㺦�£�
���ǻ�ȥ�ɡ�
LONG );
        set("exits", ([
                "north" : __DIR__"shidong",
     		"east"  : __DIR__"caodi",
                "west"  : __DIR__"harbor",
        ]));

        set("objects", ([
                __DIR__"obj/taoshu" : 1,
        ]));

	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}
