// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// chan.c ���־�

#include <ansi.h>

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
	string msg;
	int ap, dp;

        /*
        if (userp(me) && ! me->query("can_perform/yinsuo-jinling/chan")) 
                return notify_fail("��δ�ø���ָ�㣬��֪�����ʩչ��"RED"���־�"NOR"����\n"); 
        */
                
	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("ǣ�ƹ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if ((int)me->query("neili") < 200)
		return notify_fail("�������������\n");

	if ((int)me->query_skill("yinsuo-jinling", 1) < 80)
		return notify_fail("�������������Ϊ����������ʹ�ò��־���\n");

	if (target->is_busy())
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

	msg = CYN "$N" CYN "ʹ���������塸�����־�������������ͼ��$n"
              CYN "��ȫ���ס��\n" NOR;

        ap = ap_power(me, "whip");
        dp = dp_power(target, "dodge");
             
        if (ap / 2 + random(ap) > dp)
        {
		msg += CYN "���$p" CYN "��$P" CYN "���˸����ֲ�����\n" NOR;
		target->start_busy( me->query_skill("whip", 1) / 100 + 2 );
	} else
        {
		msg += CYN "����$p" CYN "������$P" CYN "����ͼ����û���ϵ���\n" NOR;
		me->start_busy(2);
	}
	message_combatd(msg, me, target);
	me->add("neili", -100);
	return 1;
}
