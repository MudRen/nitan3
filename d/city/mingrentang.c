// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <room.h>

inherit BUILD_ROOM;
string look_shu();

void create()
{
        set("short", HIY "������" NOR);
        set("long",
"���������̶�������á������﹩����д�����Ҳ��ħͷ��Ҳ�в���\n"
"��������ħͷ����ҡ���������һλ�������ھ�һʱ������һ����������\n"
"�Ķ��ǵĹ��£�ÿһ�����¶�������Զ��Ӱ����һ��������������ҡ���\n"
"Ȼ���Ƕ�����������������������ķ��꣬���������Ҳ�����ڽ�����\n"
"���ˡ����Ƕ��Ѿ��˳������������ǵ���Ӱħ�ٺܳ�ʱ���Ժ�����һ����\n"
"˵��\n"
);

        set("no_fight", "1");
        set("no_steal", "1");
        set("no_beg", "1");
        set("no_sleep_room", "1");
        set("no_clean_up", 0);

        set("exits", ([
                "down" : __DIR__"wumiao2",
        ]));
        set("objects", ([
                // __DIR__"npc/mingren/gzf" : 1,
        ]));
	set("coor/x", -10);
	set("coor/y", 20);
	set("coor/z", 20);
	setup();
}

