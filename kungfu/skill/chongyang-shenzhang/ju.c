// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define JU "��" HIW "�����۶�" NOR "��"

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;
        int ap, dp;

        /*
        if (userp(me) && ! me->query("can_perform/chongyang-shenzhang/ju"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ" JU "��\n");
        */
        
        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(JU "ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
        if (objectp(me->query_temp("weapon")))
                return notify_fail(JU "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("chongyang-shenzhang", 1) < 120)
                return notify_fail("����������Ʋ�����죬����ʩչ" JU "��\n");

        if ((int)me->query_skill("force") < 180)
                return notify_fail("����ڹ���Ϊ����������ʩչ" JU "��\n");

        if (me->query_skill_mapped("strike") != "chongyang-shenzhang")
                return notify_fail("��û�м����������Ʒ�������ʩչ" JU "��\n");

        if (me->query_skill_prepared("strike") != "chongyang-shenzhang")
                return notify_fail("��û��׼���������Ʒ�������ʩչ" JU "��\n");

        if ((int)me->query("neili") < 300)
                return notify_fail("�����ڵ��������㣬����ʩչ" JU "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "���һ����������$n" HIY "���ϣ�˫��ͬʱ"
              "����������һ�С�" HIW "�����۶�" HIY "����\n" NOR;

        ap = ap_power(me, "strike");
        dp = dp_power(target, "force");
             
        if (ap / 2 + random(ap) > dp)
        {
                me->start_busy(2);
                me->add("neili", -200);
                damage = da_power(me, "strike");
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 50,
                                           HIR "���$p" HIR "��$P" HIR "��������"
                                           "�㣬��æ���ˣ�ȴ��$P" HIR "һ�ƻ�����"
                                           "�У���Ѫ��ֹ��\n" NOR);
        } else
        {
                me->start_busy(3);
                me->add("neili", -60);
                msg += CYN "����$p" CYN "ʶ����$P"
                       CYN "��һ�У�ббһԾ�ܿ���\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}
