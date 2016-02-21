// yuling.c  ����ɢ  by sinb

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name(CYN "����ɢ" NOR, ({"yuling san", "san"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ������ɢ�������ָ���ľ�����\n");
                set("base_unit", "��");
                set("base_value", 20000);
                set("base_weight", 50);
                set("only_do_effect", 1);
                set("mixture", ([
                        "herb" : ([ "xiongdan"  : 1,
                                    "honghua"  : 1,
                                    "renshen"   : 1,
                                    "tugou"   : 1,
                                    "heshouwu"   : 1,
                                    "duhuo"   : 1,
                                    "fangfeng"    : 1,
                                    "xuelian"  : 1, ]),
                        "neili" : 70,
                        "jing"  : 25,
                        "time"  : 1,
                        "min_level" : 100,
                        "medical" : 150,
                ]));
        }
        setup();
}

int do_effect(object me)
{
        mapping my;

        if (time() - me->query_temp("last_eat/yuling") < 10)
        {
                write("��շ��ù�ҩ����ҩ�Է�����Ч���Ժ���ܼ������á�\n");
                return 1;
        }

        my = me->query_entire_dbase();
        if (my["eff_jing"] == my["max_jing"])
        {
                write("�����ڲ�û�����ˣ����ط���" + name() + "��\n");
                return 1;
        }

        me->set_temp("last_eat/yuling", time());

        message_vision(CYN "$N" CYN "�ſ��죬�͵�������" + name() +
                       CYN "������¶��һ˿΢Ц��\n" NOR, me);

        me->set("eff_jing",my["max_jing"] );
        me->set("jing",my["max_jing"] );

        me->start_busy(1);

        add_amount(-1); 
        if (query_amount() < 1) 
                destruct(this_object()); 

        return 1;
}

