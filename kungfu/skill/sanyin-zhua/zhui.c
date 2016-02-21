// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

#define ZHUI "��" HIG "׷��צ" NOR "��"

int perform(object me, object target)
{
        object weapon;
        int level;
        int i;
        
        if (userp(me) && ! me->query("can_perform/sanyin-zhua/zhui"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ" ZHUI "��\n"); 
                
        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHUI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (objectp(me->query_temp("weapon")))
                return notify_fail("ֻ�п��ֲ���ʩչ" ZHUI "����\n");

        if (me->query_skill_mapped("claw") != "sanyin-zhua")
                return notify_fail("�����õĲ����������צ������ʩչ" ZHUI "��\n");

        if (me->query_skill_prepared("claw") != "sanyin-zhua")
                return notify_fail("�������Ĳ����������צ������ʩչ" ZHUI "��\n");

        if (me->query_skill_mapped("force") != "huagong-dafa")
                return notify_fail("�����õĲ��ǻ����󷨣�ʩչ����" ZHUI "��\n");

        if ((int)me->query_skill("huagong-dafa", 1) < 120)
                return notify_fail("�㻯������Ϊ̫���������" ZHUI "��\n");

        if (me->query_skill("sanyin-zhua", 1) < 120)
                return notify_fail("���������צ��Ϊ̫���������" ZHUI "��\n");

        if (me->query("neili") <= 400)
                return notify_fail("�����������ʹ��׷��צ��\n");

        message_combatd(HIB "$N��Ȼ�ٺٸ�Ц������˫����������ϻ�ɳ�������˿�����Ҫ�Ӻδ����У�\n"
                        "ͻȻ$N���һ������δͣӰ��������$n������˫צ��ץ��צ������֮����$n�޴Ӷ�����\n" 
                        NOR, me, target);
                        
        level = me->query_skill("sanyin-zhua", 1); 
        
        me->add_temp( "apply/attack", level);
        me->add_temp( "apply/damage", level);

        for (i = 0; i < 3 + random(4); i++)
        {
                if (! me->is_fighting(target)) 
                        break;
                        
                COMBAT_D->do_attack(me, target, weapon, 0);
        }
        me->add_temp( "apply/attack", -level);
        me->add_temp( "apply/damage", -level);

        me->start_busy(2 + random(2));
        return 1;
}

