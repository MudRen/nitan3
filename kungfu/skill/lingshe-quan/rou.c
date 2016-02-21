// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// rou.c ���־�

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
	int damage;
	string msg;
        int ap, dp;

        if (userp(me) && ! me->query("can_perform/lingshe-quan/rou")) 
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ�����־�����\n");  
        
        if (! target)
        {
	        me->clean_up_enemy();
	        target = me->select_opponent();
        }
	if (! target || ! me->is_fighting(target))
		return notify_fail("�����־���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (objectp(me->query_temp("weapon")))
		return notify_fail("��Ҫʩչȭ������ʹ��������\n");
		
	if ((int)me->query_skill("lingshe-quan", 1) < 120)
		return notify_fail("�������ȭ��������죬���ڻ��޷�ʹ�á����־�����\n");
	                        
	if ((int)me->query("neili") < 200)
		return notify_fail("�����������������޷����á����־�����\n");
			
	msg = HIG "$N" HIG "һȭ�������;���ֱۺ�Ȼ����˼���ת�˸�Ȧ�ӣ�����$n"
              HIG "����$p" HIG "����ʤ����\n"NOR;

        ap = ap_power(me, "cuff"); 
        dp = dp_power(target, "dodge"); 

	if (ap / 2 + random(ap) > dp)
	{
		target->start_busy(1);
		damage = da_power(me, "cuff");

		me->add("neili", -100);
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 50,
                                           HIR "ֻ��$n" HIR "���һ�����ֻ�֮�²������㣬��$N"
                                           HIR "һȭ���˸����У��ƺ�һ��������������\n" NOR);
		me->start_busy(2);
	} else 
	{
		msg += HIC "����$p" HIC "�����Ŀ죬��æʩչ�����ܿ���ȭ��\n" NOR;
		me->add("neili", -50);
		me->start_busy(3);
	}
	message_combatd(msg, me, target);

	return 1;
}
