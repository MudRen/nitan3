// xiongdan.c
inherit ITEM;
#include <ansi.h>

void init()
{
        add_action("do_eat", "eat");
        remove_call_out("destdan");
        call_out("destdan", 10);
}

void destdan()
{
        object ob;
        message_vision("$N�������紵�ţ�һ��Ͳ��������ˡ�\n",this_object());
        ob = new("/d/guanwai/npc/xiongdan1");
        ob->move(environment(this_object()));
        destruct(this_object());
}

void create()
{
        set_name(HIG"�����ܵ�"NOR, ({"dan", "xiong dan"}));
        set("unit", "��");
        set("long", "����һ�������ܵ����������ڵģ�ʮ�����ˡ�\n");
        setup();
}

int do_eat(string arg)
{
        object me=this_player();
        if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
        if (me->is_fighting()) return notify_fail("ս���в��ܳԶ�����\n");
        if (me->is_busy()) return notify_fail("����æ���أ�\n");
        if(arg=="dan")
        {
                me->add("max_neili",2);
                me->set("neili",me->query("max_neili"));
                me->set("qi",me->query("eff_qi"));
                message_vision("$N����һ�������ܵ���ֻ���þ���������������ԴԴ��������Ѫ��ӯ��\n",me);

                destruct(this_object());
        }
        return 1;
}

