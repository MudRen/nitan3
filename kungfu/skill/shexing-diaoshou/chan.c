// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define CHAN "��" HIY "�����" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int lvl;
            
        
        if (userp(me) && ! me->query("can_perform/shexing-diaoshou/chan"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ" CHAN "��\n"); 

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(CHAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(CHAN "ֻ�ܿ���ʹ�á�\n");
                
        if ((int)target->query_temp("gb_chanshen"))
                return notify_fail("�Է��Ѿ�����ʹ" CHAN "��ס�ˣ�\n");
         
        if (target->is_busy())
                return notify_fail("�Է�����æ���У����Ĵ󵨹����ɣ�\n");
                
        if ((int)me->query_skill("xiaoyaoyou", 1) < 150)
                return notify_fail("�����ң�β�����죬����ʹ��" CHAN "��\n");
                
        if ((int)me->query_skill("shexing-diaoshou", 1) < 150)
                return notify_fail("������е��ֲ�����죬����ʹ��" CHAN "��\n");
                
        if ((int)me->query_skill("huntian-qigong", 1) < 150)
                return notify_fail("��Ļ��������ȼ�����������ʹ��" CHAN "��\n");
                
        if ((int)me->query("max_neili") < 1000)
                return notify_fail("�������̫��������ʹ��" CHAN "��\n");
                
        if ((int)me->query("neili") < 200)
                return notify_fail("�������̫���ˣ�����ʹ��" CHAN "��\n");   

        /*                
        if (! me->query_temp("gb_huixuan"))
                return notify_fail("��û��ʹ����ң���������޷�ʹ���������\n");
        */

        lvl = ((int)me->query_skill("xiaoyaoyou", 1) +
               (int)me->query_skill("shexing-diaoshou", 1)) / 2;
        
        message_combatd(HIB "\nͻȻ��$N���з�����˻˻����������˫�ְ�������ָ��������״��\n"
                        "�������ң������ͻȻ�۽�$n����ߣ���$n���һ����\n" NOR, me, target);
                        
        me->add("neili", -100+random(50)); 

        target->add_temp("apply/defense",  -lvl / 3);
        target->add_temp("apply/aromr",  -lvl / 3);
        
        if (target->query("dodge") < random(lvl) * 2)
        {
                message_combatd(HIB "����$N������������Ы����һ�㣬����$n����ߣ���$n��֪���룬\n"
                                "ֻ���ķ·������ε�����������������$n��\n" NOR, me, target);
			
                target->start_busy(3 + random(lvl / 40));
        }

        target->set_temp("gb_chanshen", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", target, lvl / 3 :), lvl / 25);
		
        return 1;
}

void remove_effect(object target,int lvl)
{
        if (! target) return;
        
        target->add_temp("apply/defense",  lvl);
        target->add_temp("apply/aromr",  lvl);
        target->delete_temp("gb_chanshen");
        if (target->is_fighting())
        {
                // target->start_busy(1 + random(1));
                message_combatd(HIG "$Nʹ������������������������ε��ֵĹ�����С�\n" NOR, target);
        }
}

