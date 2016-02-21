// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// qingxin.c �����Ľ���

#include <ansi.h>

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
	object weapon;
	string msg;
        int ap, dp;
        int ainc, dinc;

        if (userp(me) && ! me->query("can_perform/damo-jian/qingxin"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ�����Ľ�����\n");

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("�����Ľ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if ((int)me->query_skill("damo-jian", 1) < 200)
		return notify_fail("��Ĵ�Ħ����������죬����ʹ�á����Ľ�����\n");

        if (me->query("neili") < 300)
                return notify_fail("�����������������޷�ʹ�á����Ľ�����\n");

        if (me->query_skill_mapped("sword") != "damo-jian")
                return notify_fail("��û�м�����Ħ�������޷�ʹ�á����Ľ�����\n");

        if (target->query_temp("damo_qingxin"))
                return notify_fail("�Է��ող��й���Ħ���Ľ����㲻������һ���ˡ�\n");

	msg = HIM "$N" HIM "��" + weapon->name() + "����һ����һ��"
              "������Ȼ������������·����$n" HIM "��\n" NOR;

        me->add("neili", -200);
        
        ap = ap_power(me, "sword");
        dp = dp_power(target, "force");
        
        if (! target->query_temp("powerup"))
        {
 		msg += CYN "����$p" CYN "�����ƺ���û��������������" CYN
                       "ս����$P" CYN "��һ��û�����κ����á�\n" NOR;
                me->start_busy(2);
        } else
	if (ap / 2 + random(ap) > dp)
        {
		msg += HIR "���$p" HIR "���û���һ�飬������"
                       "��ľ�Ȼʹ����һ��������\n" NOR;
                ainc = target->query_temp("apply/attack");
                dinc = target->query_temp("apply/defense");
		target->add_temp("apply/attack", -ainc);
		target->add_temp("apply/defense", -dinc);
                target->set_temp("damo_qingxin", 1);
                me->start_call_out((: call_other, __FILE__, "remove_effect",  
                target, ainc, dinc:), ap / 5); 
	} else
        {
		msg += CYN "����$p" CYN "�������ʹ��$P" CYN
                       "��һ��û�����κ����á�\n" NOR;
                me->start_busy(2);
	}
	message_combatd(msg, me, target);

	return 1;
}

void remove_effect(object me, int ainc, int dinc)
{
        if (! objectp(me))
                return;

        if (me->query_temp("damo_qingxin"))
        {
                me->delete_temp("damo_qingxin");
        	me->add_temp("apply/attack", ainc);
        	me->add_temp("apply/defense", dinc);
        	tell_object(me, "����������ָ���һЩ��\n");
        }
}
