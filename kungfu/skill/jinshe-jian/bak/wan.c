// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon, ob;
        int extra,i,time;
        string msg;
        
        extra = me->query_skill("jinshe-jian",1);
        time = extra/40; 
        
        if( !target ) target = offensive_target(me);
        
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�����������ֻ����ս����ʹ�á�\n");
                
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("��ʹ�õ��������ԡ�\n");
                        
        if( (string)weapon->query("id") != "jinshe jian" )
                return notify_fail("û�н��߽�������ʹ�����߽����Ķ�����ʽ�������������\n");
                
        if((int)me->query_skill("sword") <200)
                return notify_fail("��Ľ�����Ϊ������ Ŀǰ����ʹ�á����������! \n");
                
        weapon = me->query_temp("weapon");
        if( (int)me->query("neili") < 1000 )
                return notify_fail("�������������\n");
                
        msg = HIR  "$N����һ����������������ʢ�����е�"+ weapon->name()+  HIR"���ٻ��裬������������$n������" NOR;
        message_combatd(msg,me,target);
        me->add_temp("apply/attack",extra/5);
        me->add_temp("apply/damage",extra/5);
        for(i=1;i<=(int)time;i++)
        {
                // msg =  YEL "$N���к������ģ�������������ӵ���߾��磡\n" NOR;
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);
        }
        me->add_temp("apply/attack",-extra/5);
        me->add_temp("apply/damage",-extra/5);
        me->add("neili",-500);
        me->start_busy(3);
        return 1;
}

