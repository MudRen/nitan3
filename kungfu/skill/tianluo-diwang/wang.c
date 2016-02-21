// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// wang.c ���޵��� �����޵�����

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        string msg;
        object weapon;
        int skill, ap, dp;
        
        skill = me->query_skill("tianluo-diwang", 1);
        
        /*
        if( userp(me) && ! me->query("can_perform/tianluo-diwang/wang") )
                return notify_fail("��δ�ø���ָ�㣬��֪�����ʩչ�����޵�������\n");
        */
              
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�����޵�����ֻ����ս����ʹ�á�\n");

        if((int)me->query_str() < 25)
                return notify_fail("���������,����ʹ����һ����!\n");

        if((int)me->query_skill("yunv-xinfa",1) < 100)
                return notify_fail("����Ů�ľ��Ĺ�����������ʹ�����޵���!\n");

        if((int)me->query_skill("strike") < 120)
                return notify_fail("����Ʒ���Ϊ����,Ŀǰ������ʹ�����޵�������!\n");

        if((int)me->query("neili") < 300)
                return notify_fail("���������ڲ���, ����ʹ�����޵���! \n");

        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");

        if( target->query_temp("luowang") )
                return notify_fail("��������������޵�����֮�У�\n");

        msg = HIM "\n����$N˫�۷��裬���ֵ����ر۷��˷�����죬��һ��һʽ��������Գ�" +
              "���䣬��ֻ�������ƻ�����ǧ��ǧ�ƣ�\n" NOR;

        ap = ap_power(me, "strike");
        dp = dp_power(target, "dodge");
             
        if (ap / 2 + random(ap) > dp)
        {
                msg += CYN "\n$n���´󺧣��ɹ����ˣ�ʼ���Ӳ���$Nֻ����Χ����Ȧ��! \n" NOR;

                target->start_busy( 3 + skill / 100 );
                target->add_temp("apply/defense", -skill/8);
                target->set_temp("luowang",1);
                me->add("neili", -150);
                remove_call_out("checking");
                call_out("checking", 1, me, target,skill);
                if( userp(target)) call_out("remove_effect", skill/20, me, target, skill); 
                        else call_out("remove_effect", skill/30, me, target, skill);
        }
        else
        {
                msg += HIY "\n����$p�������ң�������$P���ջ�����һԾ�����˿�ȥ��\n" NOR;
                me->start_busy(1+random(3));
                me->add("neili", -100);
                return 1;
        }
        message_combatd(msg, me, target);
        return 1;
}

void checking(object me, object target, int skill)
{
        if ( ! objectp(target) || ! objectp(me) ) return;
        if ( target->query_temp("luowang_finished"))
                target->delete_temp("luowang_finished");
        else {
        if( !living(me) || me->is_ghost() )
        {
                target->delete_temp("luowang");
                target->add_temp("apply/defense", skill/8);
                remove_call_out("remove_effect");
                message_combatd(HIG"�����ģ�$n�Ѳ��Ƴ���ʱ��ô������֡�\n\n"NOR,me,target);
                return ;
        }
        if( !me->is_fighting() )
        {
                target->delete_temp("luowang");
                target->add_temp("apply/defense", skill/8);
                remove_call_out("remove_effect");
                message_combatd(HIG"�����ģ�$n�Ѳ��Ƴ���ʱ��ô������֡�\n\n"NOR,me,target);
                return ;
        }

        if( me->query_skill_mapped("strike") != "tianluo-diwang"
         || me->query_skill_prepared("strike") != "tianluo-diwang" )
        {
                message_combatd(HIM"\n$N��Ȼ�任�����������ټ��������޵���ǣ�ƶ��ֵĹ�����\n"NOR, me);
                target->delete_temp("luowang");
                target->add_temp("apply/defense", skill/8);
                remove_call_out("remove_effect");
                message_combatd(HIG"�����ģ�$n�Ѳ��Ƴ���ʱ��ô������֡�\n\n"NOR,me,target);
                return ;
        }

        else call_out("checking", 1, me, target,skill);
                return;
        }
        return;
}

private int remove_effect(object me, object target, int skill)
{
        if (! objectp(target)) return 0;
        target->delete_temp("luowang");
        target->add_temp("apply/defense", skill/8);
        target->set_temp("luowang_finished",1);
        message_vision(HIG"�����ģ�$N�Ѳ��Ƴ���ʱ��ô������֡�\n\n"NOR, target);
        return 1;
}
