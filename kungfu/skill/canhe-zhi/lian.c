// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// lian.c ����ָ

#include <ansi.h>

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
	object weapon;
	string msg;
        int ap, dp;
        int skill;

        if (userp(me) && ! me->query("can_perform/canhe-zhi/lian"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ��\n");
                
        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! me->is_fighting(target))
                return notify_fail("������ָ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (target->is_busy())
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");

        skill = me->query_skill("canhe-zhi", 1);

        if (skill < 80)
                return notify_fail("��Ĳκ�ָ��Ϊ����, ����ʹ�á�����ָ����\n");

        if (me->query("neili") < 70)
                return notify_fail("��������������޷����á�����ָ����\n");

        if (me->query_skill_mapped("finger") != "canhe-zhi")
                return notify_fail("��û�м����κ�ָ, ����ʹ�á�����ָ����\n");

        msg = HIC "$N" HIC "��ָ���������һ��ʢ������������ƮƮ�ķ���$n"
              HIC "��\n" NOR;

        me->add("neili", -30);
        ap = ap_power(me, "finger");
        dp = dp_power(target, "dodge");
	if (ap / 2 + random(ap) > dp)
        {
		msg += HIR "���$p" HIR "��$P"
                       HIR "�Ƶ��мܲ�������Ͼ�Թˡ�\n" NOR;
                target->start_busy(random(4) + 2);
	} else
        {
		msg += CYN "����$p" CYN "������$P"
                       CYN "����ͼ������һԾ���㿪����һ�С�\n" NOR;
                me->start_busy(2);
	}
	message_combatd(msg, me, target);

	return 1;
}

