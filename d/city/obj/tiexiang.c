// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("����", ({"tie xiang", "box"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long",
                              "����ֻ���䣬�����ܴ�(open)\n");
                set("unit", "ֻ");
                set("open_count", 1);
                set("weight", 1000);
        }
}

void init()
{
        add_action("do_open","open");
}

int do_open()
{
        object ob, me = this_player();
        
        if (query("open_count") > 0)
        {
                message_vision(
                        HIY "$N���ִ����䣬��������һ���飬��д����ħ�������֡�\n" NOR, 
                        this_player());
                add("open_count", -1);
                ob = new("/clone/book/tianmo-jue");
                ob -> move(me);
                return 1;
        }
        else 
                return notify_fail("�����Ѿ������˴򿪹��ˡ�\n");
}
