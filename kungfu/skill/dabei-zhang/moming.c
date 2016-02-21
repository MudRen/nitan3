// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
#include <ansi.h>

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        string msg;
        int ap, dp;

        if( !target ) target = offensive_target(me);      

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��ʹĪ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "�Ѿ����ܶ��ˣ�\n");
                
        if( (int)me->query_skill("dabei-zhang", 1) < 100 )
                return notify_fail("��Ĵ��Ʋ�����죬����ʹ�á���ʹĪ������\n");

        msg = HIB "$N����¶��һ˿��ʹ�����飬��������һ�������ӷ�,\n"NOR;
        msg += HIB "˫�ֻ������Ƴ�������ƽ����һ�У����ǿ�����һ˿\n"NOR;
        msg += HIW "�������������Ǵ�������������ʹĪ������\n"NOR;
        
        ap = ap_power(me, "strike");

        dp = dp_power(target, "dodge");
             
        if (ap / 2 + random(ap) > dp)
        {
                msg += HIW "$p��ͼͻ��$N�Ĺ�����Χ�����Ǳ�$N���Ʒ�ܵĺ�����·��\n" NOR;
                target->start_busy(2 +random(4));
                me->add("neili", -500);
        } else 
        {
                me->start_busy(2);
                me->add("neili",-300);        
                msg += HIC "$pһ�ۿ�����$N�����������˹�ȥ��\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}


