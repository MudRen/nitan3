// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һƬ��ͨ���֣��뵺��һ�����ʧ��������ֲ���һ��������һ
��С·��ᶫ�������������Խ��Խ�ߣ��ƺ�����ɽ�壻��������������
ï�ܣ�������̫���ߡ�
LONG );
	 set("exits", ([
                "west" : __DIR__"shulin",
                "east" : __DIR__"citeng",
        ]));

	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}
