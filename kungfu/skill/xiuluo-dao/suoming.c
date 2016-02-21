// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// suoming.c ��������

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;

        if (userp(me) && ! me->query("can_perform/xiuluo-dao/suoming"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ��������������\n");
                         
        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("������������ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if (me->query_skill("force") < 200)
                return notify_fail("����ڹ�����Ϊ����������ʹ����һ������\n");

        if (me->query_skill("xiuluo-dao", 1) < 135)
                return notify_fail("������޵�����Ϊ������Ŀǰ����ʹ������������\n");

        if (me->query("neili") < 250)
                return notify_fail("�����������������ʹ������������\n");

        if (me->query_skill_mapped("blade") != "xiuluo-dao")
                return notify_fail("��û�м������޵���������ʹ������������\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIC "$N" HIC "����ɱ����ʢ��һ�����е�" + weapon->name() +
              HIC "����������$n" + HIC "���Ź�ס��\n" NOR;

        ap = ap_power(me, "blade");
        dp = dp_power(target, "parry");

        if (ap / 2 + random(ap) > dp)
        {
                damage = da_power(me, "blade");
                me->add("neili", -180);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 60,
                                           HIR "������$p" HIR "�ҽ�������һ����Ѫ����" HIR
                                           "���׵ĵ����н�����\n" NOR);
                me->start_busy(2); 
        } else
        {
                me->add("neili", -60);
                me->start_busy(3);
                msg += CYN "����$p" CYN "�����ֿ죬ֻ����������������һ��"
                       CYN "������$p" CYN "��$P" CYN "����ʽȫ��������\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}

