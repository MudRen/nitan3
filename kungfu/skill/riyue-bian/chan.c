// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// chan.c ���±޷������ơ���

#include <ansi.h>

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;

        if (userp(me) && ! me->query("can_perform/riyue-bian/chan"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ�����ƾ�����\n");
                
        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("ǣ�ƹ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            weapon->query("skill_type") != "whip")
                return notify_fail("��û�����ű��ӡ�\n");
                
        if (me->query("neili") < 80)
                return notify_fail("�����������������޷�ʩչ�����ơ�����\n");

        if (me->query_skill_mapped("whip") != "riyue-bian")
                return notify_fail("��û�м������±޷����޷�ʩչ�����ơ�����\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIC "$N" HIC "ʹ�����±޷������ơ���������������ͼ��$n"
              HIC "��ȫ�����������\n";

        me->start_busy(2);
        ap = ap_power(me, "whip");
        dp = dp_power(target, "dodge");

        if (ap * 11 / 20 + random(ap) > dp)
        {
                msg += HIR "���$p" HIR "��$P" HIR "���˸����ֲ�����\n" NOR;
                target->start_busy((int)me->query_skill("riyue-bian") / 80 + 3);
        } else 
        {
                msg += CYN "����$p" CYN "������$P"
                       CYN "����ͼ��С��Ӧ�ԣ���û���ϵ���\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}

