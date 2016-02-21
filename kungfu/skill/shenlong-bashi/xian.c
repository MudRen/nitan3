// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// xian.c ��������

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        object weapon;
        int damage, ap, dp;
        string msg;

        if (userp(me) && ! me->query("can_perform/shenlong-bashi/xian"))
                return notify_fail("�㻹����ʹ����һ�У�\n");
                
        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if ((int)me->query_skill("shenlong-bashi", 1) < 100)
                return notify_fail("���������ʽ�ַ���������죬����ʹ���������֡�\n");

        if ((int)me->query_skill("force") < 80)
                return notify_fail("����ڹ���򲻹�������ʹ���������֡�\n");

        if ((int)me->query("neili") < 150)
                return notify_fail("��������������������ʹ���������֡�\n");

        if (me->query_skill_mapped("hand") != "shenlong-bashi")
                return notify_fail("��û�м���������ʽ�ַ�������ʹ���������֡�\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIG "$N" HIG "�����ḡ���������ģ��Ƶ��ǵ�������ײײ�ĳ���$n"
              HIG "��ͬʱ���־���һ�У�����֮����\n" NOR;

        me->start_busy(2);
        ap = ap_power(me, "hand");
        dp = dp_power(target, "parry");
        if (ap / 2 + random(ap) > dp)
        {
                damage = da_power(me, "hand");

                target->start_busy(1);
                me->add("neili", -125);
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 35,
                                           HIR "$p" HIR "�����ҵ���ȴû�ܵ�ס$P" HIR "�⿴������"
                                           "�������������$P" HIR "���صĻ��У��۵�����һ����Ѫ��\n" NOR);
        } else
        {
                msg += CYN "����$p" CYN "������$P" CYN "����ͼ������ĵ�ס��$P"
                       CYN "�Ľ�����\n" NOR;
                me->add("neili", -30);
        }
        message_combatd(msg, me, target);

        return 1;
}


