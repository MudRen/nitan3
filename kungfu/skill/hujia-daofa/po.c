// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// po.c ���־�

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

        if (userp(me) && ! me->query("can_perform/hujia-daofa/po"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ�����־�����\n");
                
        if (! target)
        {
	        me->clean_up_enemy();
	        target = me->select_opponent();
        }
	if (! target || ! me->is_fighting(target))
		return notify_fail("�����־���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "blade")
		return notify_fail("���á����־������б����е���\n");

	if ((int)me->query_skill("hujia-daofa", 1) < 90)
		return notify_fail("��ĺ��ҵ���������죬����ʹ�á����־�����\n");
	                        
	if ((int)me->query_skill("force") < 150)
		return notify_fail("����ڹ���Ϊ�����ߡ�\n");
			
	if( (int)me->query("neili") < 300 )
		return notify_fail("����������̫��������ʹ�á����־�����\n");
			
	msg = HIM "$N" HIM "���е�" + weapon->name() +
              HIM "����һת��һ�����ε�����Ȼ��Ϣ��Ϯ��$n" HIM "��\n"NOR;

        ap = ap_power(me, "blade");
        dp = dp_power(target, "force");
             
        if (ap / 2 + random(ap) > dp)
	{
		damage = da_power(me, "blade");
                me->add("neili", -150);
		msg += COMBAT_D->do_damage(me, target, REMOTE_ATTACK, damage, 50,
                                           HIR "ֻ��$n" HIR "һ���ҽУ�����������"
                                           "�����������Ѫ���������\n" NOR);
		me->start_busy(2);
	} else 
	{
		msg += HIC "����$p" HIC "Ĭ��������Ӳ�ǵֵ���$P"
                       HIC "��������ε�����\n"NOR;
                me->add("neili", -50);
		me->start_busy(3);
	}
	message_combatd(msg, me, target);

	return 1;
}
