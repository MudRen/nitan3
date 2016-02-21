// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define ZHAI "��" HIC "ժ��ʽ" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        int ap, dp;

        if (userp(me) && ! me->query("can_perform/qixing-quan/zhai"))
                return notify_fail("����ʱ������ʩչ" ZHAI "��\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHAI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(ZHAI "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("qixing-quan", 1) < 60)
                return notify_fail("������ȭ��������죬����ʩչ" ZHAI "��\n");

        if (me->query_skill_prepared("cuff") != "qixing-quan")
                return notify_fail("��û��׼������ȭ��������ʩչ" ZHAI "��\n");

        if (me->query_skill("force") < 80)
                return notify_fail("����ڹ���Ϊ����������ʩչ" ZHAI "��\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("�����ڵ���������������ʩչ" ZHAI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        ap = me->query_skill("cuff") * 3 / 2 + me->query("level") * 20 + 
             me->query_skill("martial-cognize", 1);
        dp = target->query_skill("parry") + target->query("level") * 20 + 
             target->query_skill("martial-cognize", 1);

        msg = HIW "$N" HIW "˫ȭ�ӳ���ʩ�����С�" HIC "ժ��ʽ"
              HIW "�����վ���������λ��׼����Ϯ$n" HIW "��"
              "�ź��ؿڡ�\n" NOR;

        if (ap / 2 + random(ap) > dp)
        {
                damage = (int)me->query_skill("qixing-quan", 1);
                damage += random(damage / 2);

                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 40,
                                           HIR "$N" HIR "���ּȿ죬��λ���棬$n"
                                           HIR "���ܲ������ƺ�һ������Ȼ��ȭ��\n" NOR);

                me->add("neili", -100);
                me->start_busy(2 + random(2));                                         
        } else
        {
                msg += CYN "$n" CYN "���Ų�æ���Կ��죬��$N"
                       CYN "���л�ȥ��\n" NOR;

                me->add("neili", -30);
                me->start_busy(2 + random(3));
        }
        message_combatd(msg, me, target);

        return 1;
}

