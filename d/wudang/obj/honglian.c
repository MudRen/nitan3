//honglian.c С����

inherit ITEM;

#include <ansi.h>

void create()
{
        set_name(HIR"С����"NOR, ({"hong lian", "honglian"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���ɫС��������һ��С������\n");
                set("only_do_effect", 1);
        }
        setup();
}

int do_effect(object me)
{
        message_vision("$N��" + name() + "�ӽ�������¾�������ȥ��\n", me);
        me->add("neili",100);
        if (me->query("neili") > me->query("max_neili"))
                me->set("neili",me->query("max_neili"));
        destruct(this_object());
        return 1;
}


