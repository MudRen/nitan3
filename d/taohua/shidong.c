// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
����֮����һ���ͺͺ��ʯ�ڣ������޻��������������ط��γ�ǿ��
���ʯ������һ���Ҷ����Ҷ��������ģ��������������ʲô������
������Ӱ�ζ���
LONG );

         set("exits", ([
                "south" : __DIR__"shucong",
        ]));


	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}
