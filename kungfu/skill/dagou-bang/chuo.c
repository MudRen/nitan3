// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define CHUO "��" HIG "���־�" NOR "��"

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp, damage, level;

        if (userp(me) && ! me->query("can_perform/dagou-bang/chuo"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ" CHUO "��\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(CHUO "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "staff")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" CHUO "��\n");

        level = me->query_skill("dagou-bang", 1);

        if (level < 100)
                return notify_fail("��򹷰���������죬����ʩչ" CHUO "��\n");

        if (me->query_skill_mapped("staff") != "dagou-bang")
                return notify_fail("��û�м����򹷰���������ʩչ" CHUO "��\n");

        if ((int)me->query_skill("force") < 160)
                return notify_fail("����ڹ�����㣬����ʩչ" CHUO "��\n");

        if (me->query("neili") < 200)
                return notify_fail("�����ڵ���������������ʩչ" CHUO "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIG "$N" HIG "ʹ���򹷰�����" HIR "��" HIG "���־�����"
              "��һ����ʱ��Ӱ�ܶ�������$n" HIG "��ǰҪѨ��\n" NOR;

        ap = ap_power(me, "staff");

        dp = dp_power(target, "dodge");

        if (ap / 2 + random(ap) > dp)
        {
                damage = da_power(me, "staff");
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 50,
                                           HIR "$n" HIR "ȫȻ�޷�����$N" HIR "��"
                                           "������ʽ���ؿ�һ�飬���һ����Ѫ��\n" NOR);
                me->start_busy(2);
                me->add("neili", -100);
        } else
        {
                msg += CYN "��$n" CYN "ȫ���������¶���������ʹ��$N"
                       CYN "�����޹�������\n" NOR;
                me->start_busy(3);
                me->add("neili", -50);
        }
        message_combatd(msg, me, target);

        return 1;
}

