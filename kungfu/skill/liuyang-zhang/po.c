// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define PO "��" HIR "�����" NOR "��"

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;
        int ap, dp;

        if (userp(me) && ! me->query("can_perform/liuyang-zhang/po"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }
        if (! target || ! me->is_fighting(target))
                return notify_fail(PO "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(PO "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("bahuang-gong", 1) < 220
                && (int)me->query_skill("beiming-shengong", 1) < 220)
                return notify_fail("��ı��Ż�򲻹�������ʩչ" PO "��\n");

        if ((int)me->query_skill("liuyang-zhang", 1) < 220)
                return notify_fail("�����ɽ�����Ʋ�����죬����ʩչ" PO "��\n");

        if (me->query("max_neili") < 3500)
                return notify_fail("���������Ϊ���㣬����ʩչ" PO "��\n");

        if (me->query_skill_mapped("force") != "bahuang-gong"
                && me->query_skill_mapped("force") != "beiming-shengong")
                return notify_fail("��û�м��������ڹ�������ʩչ" PO "��\n");

        if (me->query("neili") < 800)
                return notify_fail("�������������㣬����ʩչ" PO "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIR "$N" HIR "���˻�����Ψ�Ҷ������������ޣ�ȫ�������ŷ�������һ��"
              "��$n" HIR "ͷ����Ȼ���䡣\n" NOR;

        me->add("neili", -500);
        ap = ap_power(me, "strike") + me->query_skill("force"); 
        dp = dp_power(target, "parry") + target->query_skill("force"); 
        
        if (target->is_good()) ap += ap / 10;

        if (ap / 2 + random(ap) > dp)
        {
                damage = 0;
                if (me->query("max_neili") > target->query("max_neili") * 2)
                {
                        msg += HIR "��ʱֻ�����ۡ���һ����$N" HIR "һ�ƽ�$n"
                               HIR "ͷ���ĵ÷��飬�Խ��Ľ�������̱����ȥ��\n"
                               NOR "( $n" RED "���˹��أ��Ѿ�������в���"
                               "��ʱ�����ܶ�����" NOR ")\n";
                        damage = -1;
                } else
                {
                        damage = da_power(me, "strike");

                        msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 90,
                                                   HIR "$n" HIR "��æ�ֵ�������Ȼ������$N"
                                                   HIR "�ƾ����ˮ��ӿ�����ڣ������������"
                                                   "�߹ǡ�\n:����@?");
                }
                me->start_busy(3);
        } else
        {
                msg += CYN "$p" CYN "��$P" CYN "�ƾ����ȣ����Ƶֵ���"
                       "ס����������������������������\n" NOR;
                me->start_busy(4);
        }
        message_combatd(msg, me, target);

        if (damage < 0)
                target->die(me);

        return 1;
}

