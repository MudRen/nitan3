// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define SHI "��" HIR "��Ѫ��" NOR "��"

inherit F_SSERVER;
#include <balance.h>
 
int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp, damage;
        int i, count;

        if (userp(me) && ! me->query("can_perform/xuedao-daofa/shi"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ" SHI "��\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(SHI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" SHI "��\n");

        if ((int)me->query_skill("force") < 250)
                return notify_fail("����ڹ���򲻹�������ʩչ" SHI "��\n");

        if ((int)me->query_skill("xuedao-daofa", 1) < 180)
                return notify_fail("���Ѫ���󷨻������ң�����ʩչ" SHI "��\n");

        if (me->query_skill_mapped("blade") != "xuedao-daofa")
                return notify_fail("��û�м���Ѫ����Ϊ����������ʩչ" SHI "��\n");

        if ((int)me->query("qi") < 100)
                return notify_fail("��Ŀǰ��Ѫ����������ʩչ" SHI "��\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("��Ŀǰ�������㣬����ʩչ" SHI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        ap = ap_power(me, "blade") + me->query("str") * 20;
        dp = dp_power(target, "dodge") + target->query("dex") * 20;
             
        msg = HIY "$N" HIY "��Ȼʩ����" HIR "��Ѫ��" HIY "��������" +
              weapon->name() + HIY "�����ޱ�ɱ�⣬Я�ŷ���֮����$n" HIY
              "��ն��ȥ��\n"NOR;

        if (ap * 11 / 20 + random(ap) > dp)
        {
                damage = da_power(me, "blade") * 2;
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 75,
                                           HIR "$n" HIR "ֻ����ǰһ��Ѫ����������"
                                           "���ѱ�$N" HIR "��һ�����˸����С�\n" NOR);
        } else
        {
                msg += CYN "$p" CYN "ֻ��$P" CYN "������ӿ�����Եֵ�����"
                       "��������Ծ�����ߡ�\n" NOR;
        }

        msg += HIY "\n������$N" HIY "��Ŀ��ȣ�����" + weapon->name() +
               HIY "һ�񣬱ų�����Ѫ�⣬����ǵ�����$n" HIY "��\n"NOR;

        ap = ap_power(me, "blade");
        dp = dp_power(target, "parry");
        if (ap * 11 / 20 + random(ap) > dp)             
        {
                msg += HIR "��ʱ��$n" HIR "ֻ����Χɱ��������ȫ����Ѫ��"
                       "���������мܡ�\n" NOR;
                count = me->query_skill("xuedao-daofa", 1) / 4;
        } else
        {
                msg += HIY "��ʱ��$n" HIY "ֻ����Χɱ���������ĵ�΢΢һ"
                       "������æ�����мܡ�\n" NOR;
                count = 0;
        }
        message_combatd(msg, me, target);

        me->add_temp("apply/attack", count);
        me->add_temp("apply/damage", count);

        for (i = 0; i < 6; i++)
        {
                if (! me->is_fighting(target))
                        break;

                if (random(3) == 1 && ! target->is_busy())
                        target->start_busy(1);

                COMBAT_D->do_attack(me, target, weapon, 0);
        }
        me->receive_wound("qi", 80);
        me->add_temp("apply/attack", -count);
        me->add_temp("apply/damage", -count);
        me->start_busy(3 + random(5));
        me->add("neili", -200 - random(300));
        return 1;
}

