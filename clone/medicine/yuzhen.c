// yuzhen.c  ����ɢ  by sinb

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name(CYN "����ɢ" NOR, ({"yuzhen san", "san"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ������ɢ���ǳ���������ҩƷ��\n");
                set("base_unit", "��");
                set("base_value", 20000);
                set("base_weight", 50);
                set("only_do_effect", 1);
                set("mixture", ([
                        "herb" : ([ "chuanwu"  : 1,
                                    "chaihu"  : 1,
                                    "renshen"   : 1,
                                    "chenpi"   : 1,
                                    "dangui"   : 1,
                                    "duhuo"   : 1,
                                    "moyao"    : 1,
                                    "shengdi"  : 1, ]),
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

        if (time() - me->query_temp("last_eat/yuzhen") < 10)
        {
                write("��շ��ù�ҩ����ҩ�Է�����Ч���Ժ���ܼ������á�\n");
                return 1;
        }

        my = me->query_entire_dbase();
        if (my["eff_qi"] == my["max_qi"])
        {
                write("�����ڲ�û�����ˣ����ط���" + name() + "��\n");
                return 1;
        }

        me->set_temp("last_eat/yuzhen", time());

        message_vision(CYN "$N" CYN "�ſ��죬�͵�������" + name() +
                       CYN "������ĺ���һ����\n" NOR, me);

        me->set("eff_qi",my["max_qi"] );
        me->set("qi",my["max_qi"] );

        me->start_busy(1);

                destruct(this_object());

        return 1;
}

