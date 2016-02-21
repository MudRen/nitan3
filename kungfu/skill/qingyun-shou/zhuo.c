// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define ZHUO "��" WHT "����׽Ӱ" NOR "��"

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        object weapon;
        int damage, ap, dp;
        string msg;

        if (userp(me) && ! me->query("can_perform/qingyun-shou/zhuo"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ" ZHUO "��\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHUO "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if ((int)me->query_skill("qingyun-shou", 1) < 50)
                return notify_fail("��������ֲ�����죬����ʩչ" ZHUO "��\n");

        if ((int)me->query_skill("force") < 100)
                return notify_fail("����ڹ���Ϊ����������ʩչ" ZHUO "��\n");

        if ((int)me->query("neili") < 300)
                return notify_fail("��������������������ʩչ" ZHUO "��\n");

        if (me->query_skill_mapped("hand") != "qingyun-shou")
                return notify_fail("��û�м��������֣�����ʩչ" ZHUO "��\n");

        if (me->query_skill_prepared("hand") != "qingyun-shou")
                return notify_fail("������û��׼��ʹ�������֣�����ʩչ" ZHUO "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = WHT "$N" WHT "����������ַ�������Ӱ����ʵʵ���ѱ���α����"
              "ȫ����$n" WHT "��\n" NOR;

        ap = ap_power(me, "hand");
        dp = dp_power(target, "dodge");
             
        if (ap / 2 + random(ap) > dp)
        {
                me->start_busy(2);
                damage = da_power(me, "hand");
                me->add("neili", -150);
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 35,
                                           HIR "$p" HIR "һʱ�������ʵ����$P"
                                           HIR "��Ӱ�������ţ���Ѫ������������Ϣ��\n" NOR);
        } else
        {
                me->start_busy(3);
                me->add("neili", -100);
                msg += CYN "����$p" CYN "ʶ����$P"
                       CYN "��һ�У�ббһԾ�ܿ���\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}

