// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>

#define HEAL "��" HIR "��������" NOR "��"

int exert(object me, object target)
{
        string force;

        if (userp(me) && ! me->query("can_exert/yijin-duangu/heal"))
                return notify_fail("����ѧ���ڹ���û�����ֹ��ܡ�\n");

        if (! target)
                return notify_fail("��Ҫ������Ϊ˭���ˣ�\n");

        if (target == me)
                return notify_fail(HEAL "ֻ�ܶԱ���ʩչ��\n");

        if (me->is_fighting() || target->is_fighting())
                return notify_fail("ս�����޷��˹����ˡ�\n");

        if (target->query("not_living"))
                return notify_fail("���޷���" + target->name() + "���ˡ�\n");

        if ((int)me->query_skill("yijin-duangu", 1) < 100)
                return notify_fail("����׽�͹ǲ�����죬����ʩչ" HEAL "��\n");

        if (me->query_skill_mapped("force") != "yijin-duangu")
                return notify_fail("��û�м����׽�͹ǣ�����ʩչ" HEAL "��\n");
                
        if ((int)me->query("max_neili") < 1500)
                return notify_fail("���������Ϊ̫ǳ������ʩչ" HEAL "��\n");

        if ((int)me->query("neili") < 1000)
                return notify_fail("�����ڵ��������㣬����ʩչ" HEAL "��\n");

        if ((int)me->query("jing") < 100)
                return notify_fail("�����ڵ�״̬���ѣ�����ʩչ" HEAL "��\n");

        if (target->query("eff_qi") >= target->query("max_qi") &&
            target->query("eff_jing") >= target->query("max_jing"))
                return notify_fail("�Է�û�����ˣ�����Ҫ�������ơ�\n");

        message_sort(HIY "\nֻ��$N" HIY "ĬĬ��ת" + to_chinese(force) +
                     HIY "����������һ������ͷ������ð��������Ȼʩչ��"
                     "�׽�͹ǣ��Դ�������˲ʱ�����$n" HIY "ȫ����ʮ��"
                     "����Ѩ������һ�ᣬ�����$n" HIY "���ۡ���һ���³�"
                     "������Ѫ����ɫ��ʱ������������ˡ�\n" NOR, me, target);

        me->add("neili", -800);
        me->receive_damage("qi", 100);
        me->receive_damage("jing", 50);

        target->receive_curing("qi", 100 + (int)me->query_skill("force") +
                                     (int)me->query_skill("yijin-duangu", 1) * 3);

        if (target->query("qi") <= 0)
                target->set("qi", 1);

        target->receive_curing("jing", 100 + (int)me->query_skill("force") / 3 +
                                       (int)me->query_skill("yijin-duangu", 1));

        if (target->query("jing") <= 0)
                target->set("jing", 1);

        if ((int)target->query_condition("hamagong_poison"))
        {
                target->clear_condition("hamagong_poison");
                tell_object(target, HIC "\n��ֻ�����ڲд�ĸ�󡹦������"
                                    "���ˣ��о��ö��ˡ�\n" NOR);
        }

        if (! living(target))
                target->revive();

        if (! target->is_busy())
                target->stary_busy(2);

        message_vision("\n$N��Ŀڤ������ʼ�˹���Ϣ��\n", me);
        me->start_busy(10);
        return 1;
}

