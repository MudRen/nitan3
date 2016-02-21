// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// sad.c ��Ȼ����

#include <ansi.h>

inherit F_SSERVER;
#include <balance.h>
 
int perform(object me, object target)
{
        string msg;
        int ap, dp;
        int count;
        int i;

        if (userp(me) && ! me->query("can_perform/sad-strike/xiao"))
                return notify_fail("��δ�ø���ָ�㣬��֪�����ʩչ����Ȼ���꡹��\n");
                 
        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail("����Ȼ���꡹ֻ����ս���жԶ���ʹ�á�\n");
 
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("����Ȼ���꡹ֻ�ܿ���ʹ�á�\n");
                
        if ((int)me->query("neili") < 500)
                return notify_fail("�������������\n");

        if ((int)me->query_skill("sad-strike", 1) < 180)
                return notify_fail("�����Ȼ�����ƻ�򲻹����޷�ʩչ����Ȼ���꡹��\n");

        if ((int)me->query_skill("force") < 300)
                return notify_fail("����ڹ���Ϊ�������޷�ʩչ����Ȼ���꡹��\n");

        if (me->query_skill_mapped("unarmed") != "sad-strike")
                return notify_fail("������û��׼��ʹ����Ȼ�����ƣ��޷�ʩչ����Ȼ���꡹��\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIM "$N" HIM "һ����̾������ֹˮ����Ȼ���ˣ��ڲ���������"
              "��ʹ����" HIR "����Ȼ���꡻" HIM "��\n" NOR;

        ap = ap_power(me, "unarmed") +
             me->query_skill("force");

        dp = dp_power(target, "parry") +
             target->query_skill("force");
             
        if (ap * 11 / 20 + random(ap) > dp)
        {
                count = ap / 10;
                msg += HIY "$n" HIY "��$P" HIY "��һ�б仯Ī�⣬�����"
                       "�������ɴ��һ��������������������\n" NOR;
        } else
        {
                msg += HIC "$n" HIC "����С��$P" HIC
                       "�����У���Ų������С���мܡ�\n" NOR;
                count = 0;
        }

        message_combatd(msg, me, target);
        me->add_temp("apply/attack", count);

        me->add("neili", -200);
        for (i = 0; i < 6; i++)
        {
                if (! me->is_fighting(target))
                        break;
                if (random(3) == 0 && ! target->is_busy())
                        target->start_busy(1);

                COMBAT_D->do_attack(me, target, 0, 0);
        }

        me->start_busy(2 + random(4));
        me->add_temp("apply/attack", -count);

        return 1;
}
