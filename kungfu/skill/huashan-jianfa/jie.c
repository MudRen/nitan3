// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// jie.c ��ɽ����������ʽ��

#include <ansi.h>

inherit F_SSERVER;
#include <balance.h>

#define JIE "��" HIG "����ʽ" NOR "��"

int perform(object me, object target)
{
        object weapon;
        int level, ap, dp;
        string msg;

        if (! target) target = offensive_target(me);

        if (userp(me) && ! me->query("can_perform/huashan-jianfa/jie"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ" JIE "��\n");

        if (! target || ! me->is_fighting(target))
                return notify_fail(JIE "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");
                
        if ((level = me->query_skill("huashan-jianfa", 1)) < 30)
                return notify_fail("��Ļ�ɽ����������죬�޷�ʩչ" JIE " ��\n");

        if (me->query_skill_mapped("sword") != "huashan-jianfa")
                return notify_fail("��û�м�����ɽ�������޷�ʩչ" JIE "��\n");

        if (me->query("neili") < 60)
                return notify_fail("�����������������޷�ʹ�á�����ʽ����\n");

        if (! living(target))
               return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "\n����$N" HIW "����һ�գ�ʹ����ɽ��������֮"
              "��" HIG "����ʽ" HIW "����ת��֮�������޷죬һ"
              "���ȳ�������ԴԴ��к�������Ծ̲����������Ѹ"
              "Ȼ����$n" HIW "��\n" NOR;

        me->add("neili", -50);
        ap = ap_power(me, "sword");
        dp = dp_power(target, "parry");

        if (ap / 2 + random(ap) > dp) 
        {
                msg += HIR "���$p" HIR "�᲻��������������"
                       "������һʱ���޷����֣�\n" NOR;
                target->start_busy(level / 80 + 3);
//                target->start_busy(level / 30 + 2);^M
        } else
        {
                if (objectp(weapon = target->query_temp("weapon")))
                        msg += CYN "����$p" CYN "ʶ����$P" CYN "�����⣬"
                               "�Թ˽����е�" + weapon->name() +
                               CYN "���һ�Ź⻨��$P"
                               CYN "һ��֮����Ҳ������ȥ��\n" NOR;
                else
                        msg += CYN "����$p" CYN "˫�ִ�����ģ���$P"
                               CYN "������һһ�ܿ���\n" NOR;

                me->start_busy(1);
        }
        message_sort(msg, me, target);

        return 1;
}

