// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// poshi.c ��ʯһ��

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include <balance.h>

#define PO "��" HIW "��ʯһ��" NOR "��"

int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;
        int ap, dp;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (userp(me) && ! me->query("can_perform/poyu-quan/po"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ" PO "��\n"); 

        if (! target || ! me->is_fighting(target))
                return notify_fail(PO "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if ((int)me->query_skill("poyu-quan", 1) < 140)
                return notify_fail("�����ʯ����ȭ������죬�޷�ʩչ" PO "��\n");
                                
        if ((int)me->query_skill("force", 1) < 120)
                return notify_fail("����ڹ���Ϊ���������޷�ʩչ" PO "\n");
                        
        if ((int)me->query("neili") < 300)
                return notify_fail("�����������������޷�ʩչ" PO "��\n");

        if (me->query_skill_prepared("cuff") != "poyu-quan")
                return notify_fail("��û��׼��ʹ����ʯ����ȭ���޷�ʩչ" PO "��\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "���һ����ȭͷ������һ�����صĻ���$n" HIY "��\n"NOR;

        ap = ap_power(me, "cuff") + me->query_str() * 5;

        dp = dp_power(target, "parry") + target->query_str() * 5;
             
        if (ap / 2 + random(ap) > dp)
        {
                damage = da_power(me, "cuff");

                me->add("neili", -220);
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 80,
                                           HIR "ֻ��$P" HIR "��һȭ��$p" HIR
                                           "���˳�ȥ�����ص�ˤ�ڵ��ϣ���Ѫ��ֹ��\n" NOR);
                me->start_busy(2);
        } else 
        {
                msg += HIC "����$p" HIC "�����мܣ�Ӳ�����ĵ�����$P"
                       HIC "��һ�С�\n"NOR;
                me->add("neili", -120);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}

