// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
�����Ƕ���ֵľ�ͷ���򶫱�ɵ����ݳǵĶ������ˡ�Զ�������ٱ�
��ߺ���������Զ�֪�ٱ��������������������������ˡ�������һ�һ��꣬
�ϱ��Ǹ�С�г���
LONG );
        set("outdoors", "city");
        set("exits", ([
                "east"  : __DIR__"dongmen",
                "west"  : __DIR__"dongdajie2",
                "north" : __DIR__"yuebing-shop",
                "south" : __DIR__"market",
        ]));

	set("coor/x", 30);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
