// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>

inherit F_SSERVER;
#include <balance.h>

#define SUO "��" HIR "������" NOR "��"

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        /*
        if (userp(me) && ! me->query("can_perform/chanhun-suo/suo"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ" SUO "��\n");
        */
        if (! target) target = offensive_target(me);

        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "whip")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if (! target || ! me->is_fighting(target))
                return notify_fail(SUO "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if ((int)me->query_skill("chanhun-suo",1) < 70)
                return notify_fail("��Ĳ���������̫ǳ��ʹ����" SUO "��\n");

        if ((int)me->query_skill("force", 1) < 100)
                return notify_fail("����ڹ���򲻹���ʹ����" SUO "��\n");

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");

        if (me->query_skill_mapped("whip") != "chanhun-suo")
                return notify_fail("��û�м�������������ʹ����" SUO "��\n");

        if (me->query("neili") < 150)
                return notify_fail("���������㣬�޷�ʩչ" SUO "��\n");

        if (! living(target))
               return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIR "$N" HIR "һ����Ц��ʹ���������������������������Ӱ����$n"
              HIR "ȫȫ���֣�\n\n" NOR;

        ap = ap_power(me, "whip");
        dp = dp_power(target, "dodge");

        if (ap / 2 + random(ap) > dp)
        {
                msg += HIY "���$n" HIY "������ɽ������Ĺ������˸����ֲ�����������������ȫ�޷�����\n" NOR;
                target->start_busy(random(4) + 3);
                me->start_busy(1 + random(2));
        } else
        {
                msg += CYN "����$p" CYN "������$P" CYN "����ͼ������һ�ݣ��ӿ��˹��ơ���\n" NOR;
                me->start_busy(3);
        }
        message_combatd(msg, me, target);
        return 1;
}

