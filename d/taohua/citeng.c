// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
������һ��ǰ�����һƬ�޷�ͨ�������֣������Ӻò��Ź֣�ÿ��
���������˳��ٹ��̣�������š��߲����������ͱ����ٲ�ס������Զ����
ǰ����������ܲ�㣬��֪���ܲ����߳�ȥ��
LONG );
	 set("exits", ([
                "west"  : __DIR__"shulin2",
                "east"  : __DIR__"beach",
                "north" : __DIR__"shanlu1",
        ]));

	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}
