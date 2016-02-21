// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// xiangmo.c �޺���ħ

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        int damage;
        string msg;
        int ap, dp;

        if (userp(me) && ! me->query("can_perform/luohan-quan/xiangmo"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ���޺���ħ����\n");
                
        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }
        if (! target || ! me->is_fighting(target))
                return notify_fail("���޺���ħ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if ((int)me->query_skill("luohan-quan", 1) < 20)
                return notify_fail("����޺�ȭ��������죬���ڻ��޷�ʹ�á��޺���ħ����\n");
                                
        if ((int)me->query("neili") < 50)
                return notify_fail("�����������������޷����á��޺���ħ����\n");
                        
        if (me->query_skill_mapped("cuff") != "luohan-quan") 
                return notify_fail("��û�м����޺�ȭ���޷�ʹ���޺���ħ��\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "�˵�һ����һȭƽƽ��$n"
              HIY "����������а����ۣ��ľ߷緶��\n" NOR;

        ap = ap_power(me, "cuff"); 
        dp = dp_power(target, "parry"); 
        
        if (ap / 2 + random(ap) > dp)
        {
                damage = da_power(me, "cuff");
                me->add("neili", -30);
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 20,
                                           HIR "ֻ��$n" HIR "һ���м�ʧ�󣬵�ʱ"
                                           "����ȭ���˸����ţ��ƺ�һ��������һ����\n" NOR);
//                me->start_busy(2);
        } else 
        {
                msg += CYN "����$p" CYN "����һ�񣬼�ס��$P"
                       CYN "����ȭ��\n" NOR;
                me->add("neili", -10);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);
               me->start_busy(2);

        return 1;
}

