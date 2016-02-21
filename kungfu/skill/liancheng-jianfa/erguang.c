// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;
	int ap, dp;

        if (userp(me) && ! me->query("can_perform/liancheng-jianfa/erguang"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ������ʽ����\n");

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("������ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
		
	if( (int)me->query_skill("liancheng-jianfa", 1) < 70 )
		return notify_fail("������ǽ���������죬����ʹ�á�\n");
	                        
	if( (int)me->query_skill("force", 1) < 70 )
		return notify_fail("��Ļ����ڹ������ߡ�\n");
			
	if( (int)me->query("neili", 1) < 300 )
		return notify_fail("����������̫��������ʹ�á�����ʽ����\n");
			
	msg = HBYEL "ֻ��$N���б��������ֿ��ٽ��������֣����������벻���ķ�λ����$n�����ա�\n"NOR;

        ap = ap_power(me, "sword");
        dp = dp_power(target, "force");

        if (ap / 2 + random(ap) > dp)
	{	
		damage = da_power(me, "sword");

                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 80,
                                           CYN "$nֻ��ֻ��������һ������������ʹ��"
                                           "�ѱ�$N�����Ĵ���һ���⣡\n" NOR);	

		me->add("neili", -200);
		me->start_busy(2);
	} else 
	{
		msg += CYN "����$p����һ��,�����$P���Ʒ硣\n" NOR;
		me->add("neili", -100);
		me->start_busy(3);
	}
	message_combatd(msg, me, target);

	return 1;
}
