// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// chan.c 缠字诀

#include <ansi.h>

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
	string msg;
	int ap, dp;

        /*
        if (userp(me) && ! me->query("can_perform/yinsuo-jinling/chan")) 
                return notify_fail("你未得高人指点，不知该如何施展「"RED"缠字诀"NOR"」。\n"); 
        */
                
	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("牵制攻击只能对战斗中的对手使用。\n");

	if ((int)me->query("neili") < 200)
		return notify_fail("你的真气不够！\n");

	if ((int)me->query_skill("yinsuo-jinling", 1) < 80)
		return notify_fail("你银锁金铃的修为不够，不能使用缠字诀！\n");

	if (target->is_busy())
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧。\n");

	msg = CYN "$N" CYN "使出银锁金铃「缠」字诀，拂鞭连挥企图把$n"
              CYN "的全身缠住。\n" NOR;

        ap = ap_power(me, "whip");
        dp = dp_power(target, "dodge");
             
        if (ap / 2 + random(ap) > dp)
        {
		msg += CYN "结果$p" CYN "被$P" CYN "攻了个措手不及。\n" NOR;
		target->start_busy( me->query_skill("whip", 1) / 100 + 2 );
	} else
        {
		msg += CYN "可是$p" CYN "看破了$P" CYN "的企图，并没有上当。\n" NOR;
		me->start_busy(2);
	}
	message_combatd(msg, me, target);
	me->add("neili", -100);
	return 1;
}
