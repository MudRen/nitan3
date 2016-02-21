// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define LIAN "��" HIM "����������" NOR "��"

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        string msg;
        int ap, dp;
        int attack_time, i;
        int v;

        if (! me->query("can_perform/chilian-shenzhang/lian"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ" LIAN "��\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(LIAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(LIAN "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("chilian-shenzhang", 1) < 100)
                return notify_fail("��������Ʋ�����죬����ʩչ" LIAN "��\n");

        if (me->query_skill_prepared("strike") != "chilian-shenzhang")
                return notify_fail("��û��׼���������ƣ�����ʩչ" LIAN "��\n");

        if (me->query_skill("force") < 100)
                return notify_fail("����ڹ���Ϊ����������ʩչ" LIAN "��\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("�����ڵ���������������ʩչ" LIAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        ap = ap_power(me, "strike");
        dp = dp_power(target, "parry");

        msg = HIC "$N" HIC "�����ڹ�������$N" HIC "˫��΢΢����"
              "��ɫ����Ȼ������ת��ʹ��һ�С�" HIM "����������" HIC
              "�����Ʒ���������$n" HIC "������˫��֮�С�\n" NOR;

        message_sort(msg, me, target);

        if (ap / 2 + random(ap) > dp)
        {
                msg = HIR "$n" HIR "����һ����ȴ��$N" HIR "��"
                      "����������ʱ��Ŵ��ҡ�\n" NOR;
                v = 1;
                me->add_temp("apply/attack", 200);
        } else
        {
                msg = HIY "$n" HIY "����$N" HIY "�⼸�е���·����"
                      "�ھ��������Ʒ�Ϭ����Ҳֻ��С�ĵֵ���\n" NOR;          
        }
        message_vision(msg, me, target);

        attack_time += 4 + random(ap / 100);

        if (attack_time > 8)
                attack_time = 8;

        me->add("neili", -attack_time * 20);

        for (i = 0; i < attack_time; i++)
        {
                if (! me->is_fighting(target))
                        break;
                COMBAT_D->do_attack(me, target, 0, 0);
        }
        if (v)
        me->add_temp("apply/attack", -200);
        me->start_busy(1 + random(attack_time));

        return 1;
}
