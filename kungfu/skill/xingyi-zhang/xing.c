// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        int i, ap, dp; 
        
        if (userp(me) && ! me->query("can_perform/xingyi-zhang/xing"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ���ǹ��㡹��\n");
        
        i = me->query_skill("xingyi-zhang", 1)/5;        
        if( !target ) target = offensive_target(me);

        if( !target || !me->is_fighting(target) )
                return notify_fail("���ǹ��㡹ֻ����ս���жԶ���ʹ�á�\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("ʹ�á��ǹ��㡹ʱ˫�ֱ�����ţ�\n");

        if( (int)me->query_skill("xingyi-zhang", 1) < 120 )
                return notify_fail("��������Ʋ�����죬����ʹ�á��ǹ��㡹��\n");

        if( (int)me->query_skill("shenyuan-gong", 1) < 120 )
                return notify_fail("�����Ԫ���ȼ�����������ʹ�á��ǹ��㡹��\n");

        if( (int)me->query_dex() < 25 )
                return notify_fail("���������ǿ������ʹ�á��ǹ��㡹��\n");

        if (me->query_skill_prepared("strike") != "xingyi-zhang"
                || me->query_skill_mapped("strike") != "xingyi-zhang")
                return notify_fail("�������޷�ʹ�á��ǹ��㡹���й�����\n");                                                                                
      

        if( (int)me->query("neili") < 700 )
                return notify_fail("����������̫��������ʹ�á��ǹ��㡹��\n"); me->add("neili", -300);

        message_combatd(HIW "\n$N˫�ƽ����Ӧ,�������Ӱ�������ǰ���$n��Χ��˸������\n" NOR,me, target);

        me->add_temp("apply/str", i);
        me->add_temp("apply/attack", i);
        me->add_temp("apply/damage", i); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);       
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);  
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK); 
        if( (int)me->query_str() >(int)target->query_str()/2) 
        {
                me->add_temp("apply/str", i);
                me->add_temp("apply/attack", i);
                me->add_temp("apply/damage", i); 
                msg =  HIW"$N����Ԫ�񹦷��ӵ����ޣ�һ˫���Ʒ���ҫ�۵Ĺ�â���û���������Ӱ��" NOR; 
                message_combatd(msg, me, target);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK); 
                me->add("neili", -100);    
                me->add_temp("apply/str", -i);
                me->add_temp("apply/attack", -i);
                me->add_temp("apply/damage", -i);       
        } 
        me->add("neili", -400); 
        me->add_temp("apply/damage", -i); 
        me->add_temp("apply/str", -i);
        me->add_temp("apply/attack", -i);  
        me->start_busy(1+random(2));        
        return 1;
}
