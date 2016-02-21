// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define SUO "��" CYN "��צ����" NOR "��"

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        int ap, dp, damage;
        string msg;
        string *limbs, limb;

        if (userp(me) && ! me->query("can_perform/suohou-gong/suo"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ" SUO "��\n");  

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(SUO "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(SUO "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("suohou-gong", 1) < 150)
                return notify_fail("��������򲻹�������ʩչ" SUO "��\n");

        if (me->query_skill_mapped("claw") != "suohou-gong")
                return notify_fail("��û�м�������������ʩչ" SUO "��\n");

        if (me->query_skill_prepared("claw") != "suohou-gong")
                return notify_fail("��û��׼������������ʩչ" SUO "��\n");

        if ((int)me->query("neili", 1) < 200)
                return notify_fail("�����ڵ��������㣬����ʩչ" SUO "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIR "$N" HIR "һ����Ц����ذεض�������һ�С�" NOR +
              CYN "��צ����" HIR "��ֱȡ$n" HIR "������\n" NOR;
        me->add("neili", -20);

        ap = ap_power(me, "claw");
        dp = dp_power(target, "dodge");

        if (ap / 2 + random(ap) > dp)
        {
                damage = 0;

                if (me->query("max_neili") > target->query("max_neili") * 2)
                {
                        msg += HIR "��ʱֻ�������꡹һ�����죬$N" HIR "��"
                               "ָ����$n" HIR "�ĺ��������顣\n" NOR "("
                               " $n" RED "���˹��أ��Ѿ�������в�����ʱ"
                               "�����ܶ�����" NOR ")\n";

                        damage = -1;
                        me->start_busy(1);
                        me->add("neili", -50);

                } else
                {
                        target->start_busy(1 + random(3));
        
                        damage = da_power(me, "claw");
                        
                        if (arrayp(limbs = target->query("limbs")))
                                limb = limbs[random(sizeof(limbs))];
                        else
                                limb = "Ҫ��";

                        msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 75,
                                                   HIR "$n" HIR "��æ������ȴ�������꡹һ"
                                                   "����$N" HIR "��ָ������$n" HIR "��" +
                                                   limb + "��\n" NOR);
                        me->start_busy(3);
                        me->add("neili", -180);
                }
        } else 
        {
                msg += CYN "����$n" CYN "������$P"
                       CYN "����ͼ�����μ������㿪����һץ��\n"NOR;
                me->start_busy(4);
                me->add("neili", -100);
        }
        message_combatd(msg, me, target);

        if (damage < 0)
                target->die(me);

        return 1;
}

