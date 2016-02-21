// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// dian.c ָ�㽭ɽ

#include <ansi.h>

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
	object weapon;
	object ob;		// ���ֵ�����
	string msg;
	int ap, dp;

        if (userp(me) && ! me->query("can_perform/yizhi-chan/dian"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչָ�㽭ɽ��\n");
                
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("������ָ�㽭ɽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (objectp(weapon = me->query_temp("weapon")))
			return notify_fail("�㲻��ʹ��������\n");


	if( (int)me->query_skill("yizhi-chan", 1) < 150 )
		return notify_fail("���һָ��̫���裬����ʹ�á�ָ�㽭ɽ����\n");

	if ( me->query("neili") < 500)
		return notify_fail("������������������޷�ʹ�á�ָ�㽭ɽ����\n");
	me->add("neili", -100);

	msg = HIY " $N��������һ�����������ָ��ʹ�����ŷ�ħ���Ͼ���ָ������������$p���˹�ȥ��\n";

	ob = target->query_temp("weapon");
        ap = ap_power(me, "finger");
        dp = dp_power(target, "force");
             
        if (ap / 2 + random(ap) > dp)
	{
		if (! objectp(ob))
		{
			int damage = 0;

			if (target->query_skill("dodge") > 200 && random(2) == 0)
			{
				switch (random(2))
				{
				case 0:
					msg += HIR " $p�������˼����ϳ���������û�ܶ����"
						"$N����һָ������$p�ĵ����ϣ�\n$pֻ����һ��"
						"�������Ե�����ϣ���������˵���������ܡ�\n";
					damage = 3;
					break;
				case 1:
					msg += HIR " $p����Ʈ�������鶯֮����������Ҫ�Ȳʣ�"
              					"�����ۡ���һ��������ܸ$p��ɫɷ�ף�ҡҡ��׹��\n";
					damage = 5;
					break;
				}
			} else
			if (target->query_skill("force") > 200 && random(2) == 0)
			{
				switch(random(2))
				{
				case 0:
					msg += HIR " $p���һ�����Գ�������ǿ�����ֳ��У���࣡�"
						"��һ����ָ�ཻ��$p����΢�Σ������ֽ��\n";
					damage = 3;
					break;
				case 1:
					msg += HIR " $pһ����Х��˫�ֻû���������Ӱ����ס��ǰ��"
						"ֻ�����͡���һ������Ӱ������$p�Ѿ������ɫ�Ұס�\n";
					damage = 4;
					break;
				}
			} else
			{
				switch(random(2))
				{
				case 0:
					msg += HIR " $p�������У���Ȼ��֪��ܣ����͡���һ����$N"
						"��һָ������$p��̴�д�Ѩ��\n";
					target->unconcious();
					damage = 0;
					break;
				case 1:
					msg += HIR " $pһת��Ѿ�����˾�ʮ���ֻ���İ취��"
						"��δ���ü�ʩչ��ֻ�����͡���һ�����ѱ�$N����̴"
						"�д�Ѩ��\n";
					target->unconcious();
					damage = 0;
					break;
				}
			}
			if (damage > 0)
                                target->receive_damage("qi", target->query("max_qi") * damage / 12, me);
			message_vision(msg + NOR, me, target);
			return 1;
		}
		if (ob->query("item_make"))
		{
			msg += HIR " $pæ��" + ob->query("name") + "�мܣ�ֻ���û��ھ������ұ����������\n" NOR;
		} else
		{
			msg += HIW " $p��æ�мܣ�ֻ������ž����һ����$p���е�" + ob->name()
				+ "�����ѣ�ɢ��һ�أ�\n";
			ob->unequip();
			ob->move(environment(target));
			ob->set("name", "�ϵ���" + ob->query("name"));
			ob->set("value", 0);
			ob->set("weapon_prop", 0);
		}
                me->start_busy(3);
		target->start_busy(2);
	} else
	{
		int busy = 0;
		if (target->query_skill("dodge") > 200 && random(2) == 0)
		{
			switch (random(2))
			{
			case 0:
				msg += " $pһ����Ц�������仯�˼����������˶�Ŀ��һʱ��$N�޷�������\n";
				busy = 2;
				break;
			case 1:
				msg += " $pͻȻ���Ʈȥ���������磬��$N��һָ���еĺ�̱仯�޴�ʩչ��\n";
				busy = 1;
				break;
			}
		} else
		if (target->query_skill("force") > 200 && random(2) == 0)
		{
			switch (random(2))
			{
			case 0:
				msg += " $p��ɫ���أ��������ƣ���׾��׾����Ȼ��$N�޴����֣�ֻ����ָ��\n";
				busy = 3;
				break;
			case 1:
				msg += " $p������м����Цһ����˫�����������ޱȣ���$Nֻ�ܻ����Ծȡ�\n";
				busy = 1;
				break;
			}
		} else
		{
			switch (random(3))
			{
			case 0:
				msg += " $p��ҡ�һΣ�����ȥ�����·���ƫƫ�����$N��һ����\n";
				busy = 2;
				break;
			case 1:
				msg += " $pһָ���������ȥ����Ҳ�Ƿ��ž���ָ����$Nһ�������ƶٻ���\n";
				busy = 2;
				break;
			case 2:
                                if (objectp(ob))
                                msg += "$p��ס����������ע" + ob->query("name")
					 + "��������ס��$N�Ľ�����\n";
                                else
                                msg += "$p��ס����������ע˫�ƣ�������ס��$N�Ľ�����\n";
				busy = 2;
				break;
			}
		}
                if (! target->is_busy())
		target->start_busy(busy);
		me->start_busy(4);
	}
	message_combatd(msg + NOR, me, target);

	return 1;
}
