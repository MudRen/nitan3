// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// shenfeng.c ���������

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        int lvl;
        object weapon;
      
        weapon = me->query_temp("weapon");
        lvl = ((int)me->query_skill("fanliangyi-dao", 1) + 
            (int)me->query_skill("poyu-quan", 1)) / 8;
            
        if (! target ) target = offensive_target(me);
     
        if (! target || ! me->is_fighting(target) )
                return notify_fail("����������塹ֻ����ս���жԶ���ʹ�á�\n");

        if (userp(me) && ! me->query("can_perform/fanliangyi-dao/sanshen"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ����������塹��\n"); 
                
        if (! weapon || weapon->query("skill_type") != "blade"
        ||  me->query_skill_mapped("blade") != "fanliangyi-dao")
                return notify_fail("������û�е����޷�ʹ�á���������塹��\n");             

        if ((int)me->query_skill("fanliangyi-dao", 1) < 100)
                return notify_fail("��ķ����ǵ�������죬����ʹ�á���������塹��\n");
      
        if ((int)me->query_skill("blade", 1) < 100)
                return notify_fail("��Ļ��������ȼ�����������ʹ�á���������塹��\n");  

        if ((int)me->query_skill("poyu-quan", 1) < 100)
                return notify_fail("�������ȭ���ȼ�����������ʹ�á���������塹��\n");
      
        if ((int)me->query_skill("zixia-shengong", 1) < 80)
                return notify_fail("�����ϼ�񹦵ȼ�����������ʹ�á���������塹��\n");

        if ((int)me->query("max_neili") < 200)
                return notify_fail("�������̫��������ʹ�á���������塹��\n");
      
        if ((int)me->query("neili") < 100)
                return notify_fail("�������̫���ˣ��޷�ʹ�ó�����������塹��\n");   
                                                                                 
        if (me->query_skill_prepared("cuff") != "poyu-quan"
        ||  me->query_skill_mapped("cuff") != "poyu-quan")
                return notify_fail("�������޷�ʹ�á���������塹���й�����\n");             

        message_combatd(HIC "\n$N" HIC "����һ����Х����������ʹ������������塹����$n" HIC "������ػ�����ȭһ����\n" NOR, 
                        me,target);
        me->add("neili", -350);      
        me->add_temp("apply/str", lvl / 10);
        me->add_temp("apply/dex", lvl / 10);
        
        weapon->unequip(); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);  
        if (! target->is_busy())
                target->start_busy(2);
        weapon->wield();
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);  
        if (! target->is_busy())
                target->start_busy(2);
        weapon->unequip();
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);  
        me->start_busy(2);
        if (! target->is_busy())
                target->start_busy(2);

        me->add_temp("apply/str", -lvl / 10);
        me->add_temp("apply/dex", -lvl / 10);
        weapon->wield();
        return 1;
}

