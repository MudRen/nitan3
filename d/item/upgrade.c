// Upgrade Armor: upgrade.c
// Created by Lonely@nitan(1)
// At 12/7/2002

#include <ansi.h>
#include <command.h>

inherit ROOM;

int do_promote(string arg);

void create()
{

        set("short", HIR "����������" NOR);
        set("long",
		"������ŷұ���������ߵĵط�����������һ���յ�ͨ��Ļ�¯������\n"
                "�����޵Ļ��磬��¯������һλ��������Ĵ󺺣����Ż�¯���Բ��\n\n"
	);
        set("no_fight", 1);
        set("no_magic", 1);
        set("no_sleep_room",1);

        set("objects", ([
                "/adm/npc/ouyezi" : 1,
        ]));
        set("exits", ([
                "north" : __DIR__"road5", 
        ]));
        
        setup();
}

int valid_leave(object me, string dir)
{
        if (me->query_temp("upgrade"))
        {
        	this_player()->delete_temp("upgrade");
                message_vision("ŷұ�Ӷ�$N��������Ҫ�������ߣ��������Ū�����ҿɲ����𰡡�\n", me);
        }

        return ::valid_leave(me, dir);
}
