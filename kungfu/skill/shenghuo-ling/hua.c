// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define GUANG "��" HIY "�⻪��" NOR "��"

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        object weapon;
        int damage, skill, ap, dp;
        string msg;

        if (userp(me) && ! me->query("can_perform/shenghuo-ling/hua"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ" GUANG "��\n"); 

        if (! target) target = offensive_target(me);

        skill = me->query_skill("shenghuo-ling",1);

        if (! (me->is_fighting()))
                return notify_fail(GUANG "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õı������ԣ�����ʹ��ʥ���֮" GUANG "��\n");

        if (skill < 140)
                return notify_fail("���ʥ����ȼ�����, ����ʹ��ʥ���֮" GUANG "��\n");

        if (me->query("max_neili") < 1500)
                return notify_fail("���������Ϊ���㣬����ʹ��ʥ���֮" GUANG "��\n");

        if (me->query("neili") < 340)
                return notify_fail("�����������������ʹ��ʥ���֮" GUANG "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "����һ������ʹ��ʥ���֮��" HIW "�⻪��" HIY "��������"
              + weapon->name() + NOR + HIY "������ɣ��ó���������"
              "â����$n" HIY "����������\n" NOR;

        ap = ap_power(me, "sword") + me->query_skill("force");
        dp = dp_power(target, "parry") + target->query_skill("force");

        if (ap / 2 + random(ap) > dp)
        {
                damage = da_power(me, "sword");

                me->add("neili", -300);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 80,
                       HIR "$n" HIR "ֻ�������â����ǵ�ϯ�������"
                       "��ȫ�޷��赲����ʱֻ��ȫ������ʹ����Ѫ��"
                       "��������\n" NOR);

                me->start_busy(2);
        } else
        {
                msg += CYN "����$n" CYN "��׼$N" CYN "���������͵���"
                       "ǰһԾ��������$N" CYN "�Ĺ�����Χ��\n"NOR;
                me->add("neili", -150);
                me->start_busy(4);
        }
        message_combatd(msg, me, target);
        return 1;
}
