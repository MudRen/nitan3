// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// zhui.c  ׷��

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int damage, ap, dp;
        string msg, pmsg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("��׷����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
                
        if( (int)me->query_skill("jinshe-jian", 1) < 150 )
                return notify_fail("��Ľ��߽���������죬����ʹ�á�\n");
                                
        if( (int)me->query("neili", 1) < 800 )
                return notify_fail("����������̫��������ʹ�á�׷������\n");
                        
        msg = HIY "$N΢΢һЦ�������������ޣ�$nȴ�е�Ī���ѹ����\n"NOR;

        me->want_kill(target);
        if( !target->is_killing(me) ) 
                target->kill_ob(me);
        
        ap = me->query_skill("sword") * 3 / 2 + me->query("level") * 20 + 
             me->query_skill("martial-cognize", 1);
        dp = target->query_skill("force") + target->query("level") * 20 + 
             target->query_skill("martial-cognize", 1);

        if (ap / 2 + random(ap) > dp)
        {
                if (! target->is_busy())
                target->start_busy( random(2) + 2);
                
                damage = (int)me->query_skill("jinshe-jian", 1) / 2;
                
                me->add("neili", -400);
                pmsg = HIR "ֻ��$N�����˸�����Ļ��ߣ��Ӳ���˼��ĽǶ���$nɱȥ,\n$nֻ���ñ���һ������������ؿ���ǰ�صĽ��⣡\n" NOR;
                
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 70, pmsg);
                me->start_busy(2);
        } else 
        {
                msg += CYN"����$p�͵���ǰһԾ,������$P�Ĺ�����Χ��\n"NOR;
                me->add("neili", -200);
                me->start_busy(4);
        }
        message_combatd(msg, me, target);

        return 1;
}

