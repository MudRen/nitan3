// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

inherit ROOM;

void create()
{
	set("short", "��Ϣ��");
	set("long", @LONG
�����һ������ӵ���Ϣ�ҡ�����ľ������������������ݽǣ��輸��
ƿ�в��ż�֦���������¿��һ���ɢ���������㡣�����˳���Ⱦ����
���ǳ�����ɨ��
LONG );

        set("sleep_room", 1);
        set("no_fight", 1);

        set("exits", ([
                "south" : __DIR__"changlang2",
        ]));
	setup();
	replace_program(ROOM);
}
