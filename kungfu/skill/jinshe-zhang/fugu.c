// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// fugu.c ����������-���ǲ���

#include <ansi.h>

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        object weapon;
        int damage, ap, dp;
        string msg;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("���ǲ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon"))
                return notify_fail("�㲻�ǿ��֣�����ʹ�ø��ǲ���\n");

        if ((int)me->query_skill("jinshe-zhang", 1) < 100)
                return notify_fail("��Ľ����Ʋ�����죬����ʹ�ø��ǲ���\n");

        if ((int)me->query("neili", 1) < 300)
                return notify_fail("����������̫��������ʹ�ø��ǲ���\n");

        if (me->query_skill_prepared("strike") != "jinshe-zhang")
                return notify_fail("������û��׼�������Ʒ����޷�ʹ�ø��ǲ���\n");

        msg = HIC "$N" HIC "���һ���������������һ̽��ס$n"
              HIC "������������ɱ�֣�\n"NOR;
        message_combatd(msg, me, target);

        ap = ap_power(me, "strike");
        dp = dp_power(target, "parry");
             
        if (target->is_busy() ||
            (ap / 2 + random(ap)) > dp)
        {
                if (! target->is_busy())
                        target->start_busy(1);

                COMBAT_D->do_attack(me, target, 0, 0);
                COMBAT_D->do_attack(me, target, 0, 0);
                COMBAT_D->do_attack(me, target, 0, 0);

                me->add("neili", -150);
                me->start_busy(2);
                msg = HIR "���$n" HIR "��$N" HIR "���������ƣ�"
                      "�ڡ����ǲ����£�һʱ��Ȼ�޷����֣�\n" NOR;
        }
        else
        {
                me->start_busy(2);
                msg = CYN "����$p" CYN "ʶ����$P"
                      CYN "��һ�У�����һ�ͣ������˶Է����ơ�\n"NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}
