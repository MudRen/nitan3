// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// jiutian.c ����ʽ

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;
        int ap, dp;

        if (userp(me) && ! me->query("can_perform/liuyang-zhang/jiutian"))
                return notify_fail("��δ�ø���ָ�㣬��֪�����ʩչ����ʽ��\n");
                
        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }
        if (! target || ! me->is_fighting(target))
                return notify_fail("������ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if ((int)me->query_skill("liuyang-zhang", 1) < 120)
                return notify_fail("��������Ʒ�������죬����ʹ�á�����ʽ����\n");
                                
        if ((int)me->query_skill("force") < 300)
                return notify_fail("����ڹ���Ϊ�����ߣ��������á�����ʽ����\n");
                        
        if ((int)me->query("neili") < 300)
                return notify_fail("��������������������ʹ�á�����ʽ����\n");
                        
        msg = HIC "$N" HIC "˫��һ�񣬻���������Ӱ����������ס$n" HIC "��\n" NOR;

        ap = ap_power(me, "strike"); 
        dp = dp_power(target, "parry"); 
             
        if (ap / 2 + random(ap) > dp)
        {
                damage = da_power(me, "strike");

                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 35,
                                           HIR "$p" HIR "���Σ�ֻ��Ӳ��һ�У������$P"
                                           HIR "���������������Ѫ��ֹ��\n" NOR);
                me->start_busy(2);
        } else
        {
                msg += HIC "����$p" HIC "ǿ��������Ӳ�����ĵ�ס$P"
                       HIC "��һ�ƣ�û���ܵ��κ��˺���\n"NOR;
                me->add("neili", -50);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}
