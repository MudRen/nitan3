// road3.c
// by Xiang

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����·");
        set("long", @LONG
������һ������·�ϡ�������ȥ���������Կ���ƽ���ݡ������������ǿ쵽
�ˡ�
LONG );
        set("outdoors", "heimuya");
        set("exits", ([
                "east" : "/d/beijing/ximenwai",
                "west" : "/d/heimuya/pingdingzhou",
        ]));
        setup();
}

void init()
{
        object me = this_player();
        if (!objectp(me) || !userp(me)) return;
        message_vision(HIB "ҹ�Ѿ����ˣ��������ߵ�С�߸ڿ�����С·�����¡�\n"NOR, me);
        remove_call_out("mes");
        call_out("mes",3,this_player());
        this_player()->set_temp("want_enter",1);
        add_action("do_enter", "enter");
}

void mes(object me)
{
        if (!me) return;
        if (environment(me) == this_object())
        message_vision(HIR "���Ƿ�Ը�����(enter)���£�\n"NOR, me);
} 

int do_enter()
{
        object me = this_player();
        if (me->query_temp("want_enter")) 
        {
                tell_object(me, HIR "������������¡�\n" NOR);
                me->move("/d/tulong/yitian/was_damen");
        }
        return 1;
}
