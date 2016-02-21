// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        string msg;
        int i, ap, dp; 
        
        if (userp(me) && ! me->query("can_perform/xingyi-zhang/riyue"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ������ͬ�ԡ���\n");
        
        i = me->query_skill("xingyi-zhang", 1) / 10;        
        
        if( !target ) target = offensive_target(me);

        if( !target || !me->is_fighting(target) )
                return notify_fail("������ͬ�ԡ�ֻ����ս���жԶ���ʹ�á�\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("ʹ�á�����ͬ�ԡ�ʱ˫�ֱ�����ţ�\n");

        if( (int)me->query_skill("xingyi-zhang", 1) < 180 )
                return notify_fail("��������Ʋ�����죬����ʹ�á�����ͬ�ԡ���\n");

        if( (int)me->query_skill("shenyuan-gong", 1) < 180 )
                return notify_fail("�����Ԫ���ȼ�����������ʹ�á��ǹ��㡹��\n");

        if( (int)me->query_dex() < 25 )
                return notify_fail("���������ǿ������ʹ�á�����ͬ�ԡ���\n");

        if (me->query_skill_prepared("strike") != "xingyi-zhang"
        || me->query_skill_mapped("strike") != "xingyi-zhang")
                return notify_fail("�������޷�ʹ�á�����ͬ�ԡ����й�����\n");                                                                                
      

        if( (int)me->query("neili") < 700 )
                return notify_fail("����������̫��������ʹ�á�����ͬ�ԡ���\n"); me->add("neili", -300);

        message_combatd(CYN "\n$N˫��һ�꣬��˫��֮���γ�һ��ҫ�۵ġ�"HIW"����"CYN"����\n" NOR,me, target);

        ap = ap_power(me, "strike");
        dp = dp_power(target, "force");

        me->add_temp("apply/str", i);
        me->add_temp("apply/dex", i);
        me->add_temp("apply/attack", i);
        me->add_temp("apply/damage", i);
        
        if (ap / 2 + random(ap) > dp)
        { 
                msg = HIR"$N˫��������ǰ�����λ�������㽫��"HIW"����"HIR"������$n��̴��Ѩ��"NOR;
                message_combatd(msg, me, target);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);
        
                msg = HIG"������$N������ƣ�����һ�������¶�����Ϯ��$n��С����"NOR;
                message_combatd(msg, me, target);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);
 
                msg = HIR"ֻ��$N���������������һԾ�����������������$n��ͷ����"NOR;
                message_combatd(msg, me, target);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);

                msg = HIY"$N�ڿ���һ����ת��Я��"HIR"����֮��"HIY"��, ˫�ư���$n�ĵ��"NOR;
                message_combatd(msg, me, target);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);

        } else 
        {
                msg = HIR"$N˫��������ǰ�����λ�������㽫��"HIW"����"HIR"������$n��̴��Ѩ��"NOR;
                message_combatd(msg, me, target);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);
        
                msg = HIG"������$N������ƣ�����һ�������¶�����Ϯ��$n��С����"NOR;
                message_combatd(msg, me, target);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);
 
                msg = HIR"ֻ��$N���������������һԾ�����������������$n��ͷ����"NOR;
                message_combatd(msg, me, target);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);
                
                call_out("perform2", 3, me, target);  
        } 
        message_combatd(YEL "\n$Nһʽ������ͬ�ԡ����ӵ����쾡�£�˫��һ�֣��������У����ı�����\n" NOR,me, target);     
        me->add("neili", -400);
        me->add_temp("apply/dex", -i);
        me->add_temp("apply/damage", -i); 
        me->add_temp("apply/str", -i);
        me->add_temp("apply/attack", -i);   
        me->start_busy(2+random(2));

        return 1;
}
int perform2(object me, object target)
{ 
        string msg;
        int i; 
        i = me->query_skill("xingyi-zhang", 1)/10; 
        if (!me || !target) return 0;
        if(!living(target)) 
                return notify_fail("�����Ѿ�������ս���ˡ�\n");  

        if( (int)me->query("neili", 1) < 300 )
               return notify_fail("���Ҫ�ٳ��ڶ�����ȴ�����Լ������������ˣ�\n");
               
        me->add_temp("apply/str", i);
        me->add_temp("apply/dex", i);
        me->add_temp("apply/attack", i);
        me->add_temp("apply/damage", i);
        msg = HIY"$N�ڿ���һ����ת��Я��"HIR"����֮��"HIY"��, ˫�ư���$n�ĵ��"NOR;
        message_combatd(msg, me, target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);
 
        msg = HIC"ֻ��$Nб���ת�������ĳ����ƣ�����������ֱָ$n��в��"NOR;
        message_combatd(msg, me, target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);

        msg = HIW"$N����Ԫ�񹦷��ӵ����ޣ��û���������Ӱ����$nȫ�����ֹ�ȥ��"NOR;
        message_combatd(msg, me, target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);

        me->add("neili", -400);
        me->add_temp("apply/dex", -i);
        me->add_temp("apply/damage", -i); 
        me->add_temp("apply/str", -i);
        me->add_temp("apply/attack", -i);    
        me->start_busy(2+random(2));

        return 1;
}


