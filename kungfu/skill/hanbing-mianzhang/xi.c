// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// xi.c ��Ѫ����
 
#include <ansi.h>
 
inherit F_SSERVER;
#include <balance.h>
 
int perform(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp, neili_wound, qi_wound;

        if (userp(me) && ! me->query("can_perform/hanbing-mianzhang/xi"))
                return notify_fail("�㻹û������������о������޷�ʩչ����Ѫ���𡹡�\n");
                
        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("hanbing-mianzhang", 1);

        if (! (me->is_fighting(target)))
                return notify_fail("����Ѫ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
        if (objectp(weapon = me->query_temp("weapon")))
                return notify_fail("��ʹ����������\n");

        if (skill < 60)
                return notify_fail("��ġ��������ơ��ȼ�����, ����ʹ�á���Ѫ���𡹣�\n");

        if (me->query_skill("dodge", 1) < 200)
                return notify_fail("����Ṧ������û�д�ã��޷����á���Ѫ���𡹣�\n");

 
        msg = HIR "$N" HIR "ͻȻ��ͬ����һ����ٿ���۽�$n"
              HIR "����ǰ���������$n" HIR "���ʺ�ҧȥ��\n" NOR;
        message_combatd(msg, me, target);
 
        ap = ap_power(me, "hand");
        dp = dp_power(target, "dodge");
             
        if (ap / 2 + random(ap) > dp)
        {
                me->add("neili", -100);

                msg = HIG "$n" HIG "ֻ�����ʺ�һ���ʹ��ԭ����$P" HIG
                      "Ҫ�˸����У�ֻ��$N" HIG "����ҧס����$n" HIG "����Ѫ��\n"NOR;
                neili_wound = da_power(me, "hand") * 2;
                if (neili_wound > target->query("neili"))
                        neili_wound = target->query("neili");

                qi_wound = da_power(me, "hand");
                if (qi_wound > target->query("qi"))
                        qi_wound = target->query("qi");

                target->add("neili", -neili_wound, me);
                target->receive_wound("qi", qi_wound, me);
                if( !target->is_busy() )
                target->start_busy(2);
                me->start_busy(1 + random(2));
        } else
        {
                msg = CYN "ֻ��$n" CYN "���Ų�æ������һ���������$N"
                      CYN "�����ݣ�\n"NOR;
                me->add("neili",-100);
                me->start_busy(4);
        }
        message_combatd(msg, me, target);

        return 1;
}

