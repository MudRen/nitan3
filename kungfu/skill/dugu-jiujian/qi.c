// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define QI "��" HIW "����ʽ" NOR "��"

inherit F_SSERVER;
#include <balance.h>

string final(object me, object target, int damage);

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp, skill;
        int damage;

        if (userp(me) && me->query("can_perform/dugu/qi") < 100)
                return notify_fail("��Ŀǰ������ʩչ" QI "��\n");

        me->clean_up_enemy();
        if (! target) target = me->select_opponent();

        skill = me->query_skill("dugu-jiujian", 1);

        if (! me->is_fighting(target))
                return notify_fail(QI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (skill < 120)
                return notify_fail("����¾Ž��ȼ��������޷�ʩչ" QI "��\n");

        if (! objectp(weapon = me->query_temp("weapon"))
           || weapon->query("skill_type") != "sword")
                return notify_fail("����ʹ�õ��������ԣ��޷�ʩչ" QI "��\n");

        if (me->query_skill_mapped("sword") != "dugu-jiujian") 
                return notify_fail("��û�м������¾Ž����޷�ʩչ" QI "��\n");

        if (target->query_condition("no_exert"))
                return notify_fail("�Է������Ѿ��޷������������ŵ������ɡ�\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "ʩ�����¾Ž�������ʽ��������" + weapon->name() +
              HIW "�й�ֱ����ңָ$n" HIW "������ҪѨ��\n" NOR;

        ap = ap_power(me, "sword") + me->query_skill("parry");
        dp = dp_power(target, "force") + target->query_skill("parry");

        if (ap * 2 / 3 + random(ap * 2 / 3) > dp)
        {
                damage = da_power(me, "sword");
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 85,
                                           (: final, me, target, damage :));
                me->start_busy(3);
        } else 
        {
                msg += CYN "��$n" CYN "��֪$N" CYN "���е���"
                       "�����������������ߣ�����������\n" NOR;
                me->start_busy(4);
        }
        message_combatd(msg, me, target);

        return 1;
}

string final(object me, object target, int ap)
{
        target->apply_condition("no_exert", 10);
        call_out("poqi_end", 10 + random(ap / 30), me, target);
        return  HIR "$n" HIR "��$N" HIR "һ���������ţ��Ǹ�һ��"
                "׶�ĵĴ�ʹ��ȫ������ԴԴ��к��\n" NOR;
}

void poqi_end(object me, object target)
{
        if (target && target->query_condition("no_exert"))
        {
                if (living(target))
                {
                        message_combatd(HIC "$N" HIC "��������һ��������ɫ��"
                                        "��ת�죬�������ö��ˡ�\n" NOR, target);

                        tell_object(target, HIY "��е������ҵ���������ƽ��"
                                            "��������\n" NOR);
                }
                target->apply_condition("no_exert", 0);
        }
        return;
}

