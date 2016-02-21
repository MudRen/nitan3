// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// tanzhi.c

#include <ansi.h>

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        int skill, i;
        int n;
        int ap, dp;
        string pmsg;
        string msg;
        object weapon;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("��ָֻ����ս���жԶ���ʹ�á�\n");

        if (userp(me) && ! me->query("can_perform/tanzhi-shentong/tanzhi"))
                return notify_fail("��Ŀǰ������ʩչ��ָ��\n");
                
        if (! objectp(weapon = me->query_temp("handing")) ||
            (string)weapon->query("skill_type") != "throwing" ||
            weapon->query_amount() < 1)
                return notify_fail("���������в�û�����Ű�������ôʩչ��ָ��\n");

        if ((skill = me->query_skill("tanzhi-shentong", 1)) < 100)
                return notify_fail("��ĵ�ָ��ͨ������죬����ʹ�õ�ָ��\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("�����������ˡ�\n");

        me->add("neili", -90);
        weapon->add_amount(-1);

        msg = HIC "$N" HIC "��ָ�ᵯ��ֻ���ƿ���������һ" +
             weapon->query("base_unit") + weapon->name() + HIC "���ٷɳ�" +
             "������$n" HIC "��\n" NOR;

        me->start_busy(2);
        ap = ap_power(me, "finger") + me->query_skill("throwing");
        dp = dp_power(target, "dodge") + target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                msg += HIR + weapon->name() + HIR "���úÿ죬$n"
                       HIR + "һ�����ܲ����������˸����У�����һ"
                       "���ʹ�������˼�����Ҫɢ���ˡ�\n" NOR;
                target->receive_wound("qi", skill / 2 + random(skill / 2), me);
                COMBAT_D->clear_ahinfo();
                weapon->hit_ob(me, target,
                               me->query("jiali") + 150);
                if (stringp(pmsg = COMBAT_D->query_ahinfo()))
                        msg += pmsg;
                message_combatd(msg, me, target);
        } else
        {
                msg += CYN "����$p" CYN "����һ���������$P" HIG "������" +
                       weapon->name() + CYN "��\n" NOR;
                message_combatd(msg, me, target);
        }

        me->reset_action();
        return 1;
}
