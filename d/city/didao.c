// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

inherit ROOM;
#include <ansi.h>

void create()
{ 
       set("short","�ص�");
       set("long",
"��������һ���ص��С����Ե�ǽ���Ϲ���Щ�͵ƣ��е��Ѿ�Ϩ���ˡ�\n"
"���Ϻͽ��µĳ������˺ܲ�����������ǽ�ƺ�����(pull)��\n"
        );
        set("exits", ([
                 "out" : "/d/city/xiaofang",
        ]));       

        set("no_clean_up", 0);
        set("open_count", 1);
        setup();

}

void init() 
{
        add_action("do_pull","pull"); 
}

int do_pull() 
{ 
        object ob, me = this_player(); 
        if (query("open_count") > 0) 
        { 
                message_vision(HIY  
                        "$N������ǽ�����˼��£���һ����������ǽ����������ȥ��һֻ����¶�˳�����\n" NOR, 
                        this_player()); 
                add("open_count", -1); 
                ob = new("/d/city/obj/tiexiang"); 
                ob -> move(me); 
                return 1; 
        } 
        else 
                return notify_fail("�����Ѿ������˴򿪹��ˡ�\n"); 
} 
