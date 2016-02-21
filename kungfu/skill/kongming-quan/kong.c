// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define KONG "��" HIG "�տ���Ҳ" NOR "��"

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        int damage;
        string msg;
        int ap, dp;

/*
        if (userp(me) && ! me->query("can_perform/kongming-quan/kong"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ" KONG "��\n");
*/

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(KONG "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (objectp(me->query_temp("weapon")))
                return notify_fail(KONG "ֻ�ܿ���ʩչ��\n");
                
        if ((int)me->query_skill("kongming-quan", 1) < 150)
                return notify_fail("��Ŀ���ȭ������죬����ʩչ" KONG "��\n");

        if (me->query_skill_mapped("unarmed") != "kongming-quan")
                return notify_fail("��û�м�������ȭ������ʩչ" KONG "��\n");

        if (me->query_skill_prepared("unarmed") != "kongming-quan")
                return notify_fail("��û��׼������ȭ������ʩչ" KONG "��\n");

        if ((int)me->query("neili", 1) < 150)
                return notify_fail("�����ڵ�����̫��������ʩչ" KONG "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = WHT "$N" WHT "ʹ������ȭ��" HIG "�տ���Ҳ" NOR + WHT "����ȭ��"
              "����ʵʵ���仯Ī�⣬��$n" WHT "һʱ���Բ�׽��\n" NOR;
        me->add("neili", -80);

        ap = ap_power(me, "unarmed");
        dp = dp_power(target, "parry");
             
        if (ap / 2 + random(ap) > dp)
        {
                me->start_busy(3);
                
                damage = da_power(me, "unarmed");
                
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 80,
                                           HIR "$n" HIR "�޷�����$N" HIR "ȭ�а�"
                                           "�أ�����һȭ����Ҫ������ʱŻ��һ���"
                                           "��Ѫ��\n:����@?");
        } else 
        {
                me->start_busy(2);
                msg += CYN "����$p" CYN "ʶ����$P"
                       CYN "��ȭ���еı仯������Ӧ�ԣ���û�гԿ���\n" NOR;
        }
        message_combatd(msg, me, target);
        return 1;
}

