// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        object weapon;
        string msg;
        int damage, ap, dp;

        if (userp(me) && ! me->query("can_perform/meiren-sanzhao/wuqing")) 
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ����Ů���项��\n"); 

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("��Ů����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ��Ů���顣\n");

        if( (int)me->query_skill("sword", 1) < 120 )
                return notify_fail("��Ļ����������𲻹�������ʹ����Ů���顣\n");

        if( (int)me->query_skill("force", 1) < 120 )
                return notify_fail("����ڹ���δ��죬��������Ů���顣\n");

        if( (int)me->query("neili", 1) < 400 )
                return notify_fail("����������̫��������ʹ����Ů���顣\n");

        msg = HIB "\n\n$N�����߶������ý����ݺ����飡\n" NOR;
        msg += HIY "\n$N����֧�ã���������ӳ�����̾һ�������ּ���֮�⣬������ʹ��ɱ�С�\n\n" NOR;
        
        ap = ap_power(me, "sword"); 
        dp = dp_power(target, "dodge"); 
             
        if (ap / 2 + random(ap) > dp)
        {
                damage = da_power(me, "sword");         
                me->add("neili", -300);

                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 65,
                                           HIR "ֻ���顢�顢�������죬$n���ϱ��˼�����������Ѫ���硣\n" NOR);
                me->start_busy(2+random(2));
        }
        else 
        {
                msg += HIG"$p���һ�֣�����Ծ�𣬱��ܵķ�Ӧ��$p�ӹ��˽١�\n\n"NOR;
                me->add("neili", -100);
                me->start_busy(2);       
        }

        message_combatd(msg, me, target);
        return 1;
}

