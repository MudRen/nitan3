// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define XUE "��" HIR "��Ѫ��" NOR "��"

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp, damage;

        if (userp(me) && ! me->query("can_perform/xuedao-daofa/xue"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ" XUE "��\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(XUE "ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" XUE "��\n");

        if ((int)me->query_skill("force") < 220)
                return notify_fail("����ڹ���򲻹�������ʩչ" XUE "��\n");

        if ((int)me->query_skill("xuedao-daofa", 1) < 160)
                return notify_fail("���Ѫ���󷨻������ң�����ʩչ" XUE "��\n");

        if (me->query_skill_mapped("blade") != "xuedao-daofa")
                return notify_fail("��û�м���Ѫ����Ϊ����������ʩչ" XUE "��\n");

        if ((int)me->query("qi") < 100)
                return notify_fail("��Ŀǰ��Ѫ����������ʩչ" XUE "��\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("��Ŀǰ�������㣬����ʩչ" XUE "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        ap = ap_power(me, "blade");
        dp = dp_power(target, "force");
             
        msg = HIR "$N" HIR "�ӵ������һ�գ�Ѫ���ʱ�������棬�������ұ�"
              "�ճ�һƬѪ����$n" HIR "��ͷ���䡣\n" NOR;

        if (ap / 2 + random(ap) > dp)
        {
                damage = da_power(me, "blade");
                me->add("neili", -150);
                me->start_busy(2);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 80,
                                           HIR "$n" HIR "ֻ��Ѫ����������ǰһ��Ѫ"
                                           "�죬����������£���Ѫ�ɽ�����������"
                                           "�󺿣�\n" NOR);
        } else
        {
                me->start_busy(3);
                msg += CYN "����$n" CYN "������ã����Ų�æ�������$N"
                       CYN "�ı�ɱһ����\n"NOR;
                me->add("neili", -100);
        }
        me->receive_wound("qi", 50);
        message_combatd(msg, me, target);
        return 1;
}

