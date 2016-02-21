// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define HUA "��" HIW "һ��������" NOR "��"

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp, damage;
        int i, count;
        int is_yunv = 0;

        if (userp(me) && ! me->query("can_perform/quanzhen-jian/hua"))
                return notify_fail("��δ�ø���ָ�㣬��֪�����ʩչ" HUA "��\n"); 
                
        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(HUA "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" HUA "��\n");

        if ((int)me->query_skill("quanzhen-jian", 1) < 200)
                return notify_fail("��ȫ�潣��������죬����ʩչ" HUA "��\n");

        if ((int)me->query_skill("xiantian-gong", 1) < 100)
                return notify_fail("������칦������죬����ʩչ" HUA "��\n");

        if (me->query_skill_mapped("sword") != "quanzhen-jian")
                return notify_fail("��û�м���ȫ�潣��������ʩչ" HUA "��\n");

        if (me->query_skill_mapped("force") != "xiantian-gong")
                return notify_fail("��û�м������칦������ʩչ" HUA "��\n");

        if ((int)me->query("max_neili") < 4500)
                return notify_fail("���������Ϊ����������ʩչ" HUA "��\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("�����ڵ��������㣬����ʩչ" HUA "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "һ��������������ȫȻ�˵����ϣ�" + weapon->name() +
              HIW "������ʱ" HIM "��â" HIW "��ҫ������������������$n"
              HIW "��\n" NOR;

        ap = ap_power(me, "sword") +
             me->query_skill("force");

        dp = dp_power(target, "parry") +
             target->query_skill("force");

	if (stringp(target->query_skill_mapped("sword")) &&
	    target->query_skill_mapped("sword") == "yunv-jian" &&
            target->query_temp("weapon") &&
            target->query_temp("weapon")->query("skill_type") == "sword")
	{
		dp += target->query_skill("yunv-jian", 1);
		is_yunv = 1;
	}
	
        me->start_busy(3);
        me->add("neili", -200);

        if (ap / 2 + random(ap) > dp)
        {
                damage = da_power(me, "sword");
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 100,
                                           HIR "��ʱֻ��$n" HIR "һ���ҽУ�������"
                                           "�����Ͻ����������Ѫ����\n" NOR);
                message_combatd(msg, me, target);

                if (ap / 2 + random(ap) > dp)
                {
                        count = me->query_skill("xiantian-gong", 1) / 2;
                        me->add_temp("apply/attack", count);
                        message_combatd(HIY "$N" HIY "��$n" HIY "����һ��֮����"
                                        "����������ʱ����ǰԾ���������������"
                                        "\n" NOR, me, target);

                        for (i = 0; i < 3; i++)
                        {
                                if (! me->is_fighting(target))
                                        break;
                                COMBAT_D->do_attack(me, target, weapon, 0);
                        }
                        me->add_temp("apply/attack", -count);
                }
        } else
        {
                me->start_busy(2);
                if (is_yunv)
			msg += CYN "ȴ��$n" CYN "΢΢һЦ������һ�С���Ů�����������ɵص�ס��$N�Ľ��С�\n" NOR;
		else
                        msg += CYN "����$n" CYN "������$N" CYN "����ͼ��бԾ�ܿ���\n" NOR;
                message_combatd(msg, me, target);
        }

        return 1;
}
