#include <ansi.h>
inherit ITEM;

inherit F_LIQUID;

void create()
{
        set_name(NOR + YEL "ţƤˮ��" NOR, ({ "shui dai", "shui", "dai" }));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + YEL "����һ֧�ش�ŵ�ţƤˮ��������"
                            "�൱��������������������ԽɳĮ��\n" NOR);
                set("unit", "֧");
                set("value", 5000);
                set("max_liquid", 9000);
                set("can_drink", 1);
                set("only_do_effect", 1);
        }
        set("liquid", ([
                "type"         : "water",
                "name"         : "��ˮ",
                "remaining"    : 9000,
                "drunk_supply" : 1000,
        ]));
}

int do_effect(object me)
{
        int remain;

        if ((remain = query("liquid/remaining")) < 1)
        {
                write(name() + "���" + query("liquid/name") + "�Ѿ����ȵ�һ��Ҳ��ʣ�ˡ�\n"); 
                return 1;
        }
        
        if (me->query("water") >= me->max_water_capacity())
        {
                write("���Ѿ���̫���ˣ���Ҳ�಻��һ��ˮ�ˡ�\n"); 
                return 1;
        }

        message_vision("$N����" + name() + "������غ��˼����" + query("liquid/name") + "��\n" NOR, me);
        
        if (remain < 1500)
        {
                me->add("water", remain);
                set("liquid/remaining", 0);
        } else
        {
                me->add("water", 1500);
                add("liquid/remaining", -1500);
        }

        if (query("liquid/remaining") < 1 &&
            me->query("env/auto_drinkout") && 
            environment() != environment(me)) 
        {
                message_vision("$N����һ��$n��\n", me, this_object()); 
                this_object()->move(environment(me)); 
        }
        
        return 1;
}

