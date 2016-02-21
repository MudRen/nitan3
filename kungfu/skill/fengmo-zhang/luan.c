// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define LUAN "��" HIR "Ⱥħ����" NOR "��"

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        object weapon;
        string msg;
        int count;
        int lvl;
        int i, ap, dp;
 
        if (userp(me) && ! me->query("can_perform/fengmo-zhang/luan"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ" LUAN "��\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(LUAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "staff")
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" LUAN "��\n");

        if ((lvl = (int)me->query_skill("fengmo-zhang", 1)) < 120)
                return notify_fail("���ħ�ȷ���򲻹�������ʩչ" LUAN "��\n");

        if (me->query_skill_mapped("staff") != "fengmo-zhang")
                return notify_fail("��û�м�����ħ�ȷ�������ʩչ" LUAN "��\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("����ڹ���򲻹�������ʩչ" LUAN "��\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("�����ڵ��������㣬����ʩչ" LUAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIR "ֻ��$N" HIR "����ɱ����ʢ������һ����������ǰ��"
                  "���緢��һ�㣬���е�" + weapon->name() +
              HIR "����������Ӱ��һ�����$n" HIR "��\n" NOR;
              
        ap = ap_power(me, "staff");
        dp = dp_power(target, "parry");

        if (ap / 2 + random(ap) > dp)
        {
                              
                msg += HIY "$n" HIY "��$N" HIY "������ƣ�����������"
                       "ս��һʱ��֪Ӧ����εֵ���Ψ���������ˡ�\n" NOR;
                count = lvl / 6;
                me->add_temp("apply/attack", count);
        } else
                count = 0;

        message_combatd(msg, me, target);
        me->add("neili", -100);

        for (i = 0; i < 3; i++)
        {
                if (! me->is_fighting(target))
                        break;
                if (random(2) && ! target->is_busy())
                        target->start_busy(1);
                COMBAT_D->do_attack(me, target, weapon, 0);
        }

        me->add_temp("apply/attack", -count);
        me->start_busy(1 + random(5));
        return 1;
}
