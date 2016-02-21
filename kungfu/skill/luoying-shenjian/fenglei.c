// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// fenglei.c

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg, msg1;
        int i, z;
        object weapon;
        z = me->query_skill("luoying-shenjian", 1) / 2;
        
        if (! target) target = offensive_target(me);
        if (! target || ! me->is_fighting(target))
                return notify_fail("���������񽣡�ֻ����ս���жԶ���ʹ�á�\n");
                
        if (userp(me) && ! me->query("can_perform/luoying-shenjian/fenglei"))
                return notify_fail("�㻹û���ܵ�����ָ�㣬��ʱ������ʩչ���������񽣡���\n");
                
        weapon = me->query_temp("weapon");
        if (! weapon || weapon->query("skill_type") != "sword"
        ||  me->query_skill_mapped("sword") != "luoying-shenjian")
                return notify_fail("�����ʹ���ڽ�ʱ����ʹ�����������񽣡���\n");

        if ((int)me->query_skill("luoying-shenjian", 1) < 80)
                return notify_fail("�����Ӣ�񽣲�����죬����ʹ�á��������񽣡���\n");

        if ((int)me->query_skill("bibo-shengong", 1) < 60)
                return notify_fail("��ı̲�����Ϊ����������ʹ�á��������񽣡���\n");

        if ((int)me->query_dex() < 30)
                return notify_fail("�����̫�ͣ�����ʹ�á��������񽣡���\n");

        if (me->query_skill_mapped("force") != "bibo-shengong")
                return notify_fail("��ʹ�õ��ڹ����ԣ�����ʹ�á��������񽣡���\n");

        if ((int)me->query("neili", 1) < 400)
                return notify_fail("����������̫��������ʹ�á��������񽣡���\n");

        i = (me->query_skill("luoying-shenjian", 1) / 4);
        
        msg = HIG "$N�������������һ�Ӱ����񽣡���������װ�ķ�������! \n" NOR;
        msg1 = HIY"$Nʹ����׾������е��������Ĳ��١�\n" NOR;
       
        me->add_temp("apply/damage", z); 
        me->add_temp("apply/str", z/10);
        me->add_temp("apply/attack", z); 
        message_combatd(msg, me, target);
        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);
        message_combatd(WHT"                                                                           ���־�\n"NOR,me);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);
        message_combatd(HIC"                                                                           ���־�\n"NOR,me); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);
        message_combatd(MAG"                                                                           ���־�\n"NOR,me); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);
        message_combatd(HIR"                                                                           ���־�\n"NOR,me);
        me->add("neili", -200);
       
        me->start_busy(2);
        me->add_temp("apply/damage", -z);
        me->add_temp("apply/str", -z/10);
        me->add_temp("apply/attack", -z); 
        message_combatd(msg1, me,target);

        return 1;
}

