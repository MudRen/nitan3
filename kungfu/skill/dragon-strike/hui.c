// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define HUI "��" HIR "�����л�" NOR "��"

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        int damage;
        string msg;
        int ap, dp;

        if (userp(me) && ! me->query("can_perform/dragon-strike/hui"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ" HUI "��\n"); 

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(HUI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(HUI "ֻ�ܿ���ʹ�á�\n");

        if ((int)me->query_skill("force") < 260)
                return notify_fail("���ڹ���Ϊ����������ʩչ" HUI "��\n");

        if ((int)me->query("max_neili") < 5000)
                return notify_fail("��������Ϊ����������ʩչ" HUI "��\n");

        if ((int)me->query_skill("dragon-strike", 1) < 240)
                return notify_fail("�㽵��ʮ���ƻ�򲻹�������ʩչ" HUI "��\n");

        if (me->query_skill_mapped("strike") != "dragon-strike")
                return notify_fail("��û�м�������ʮ���ƣ�����ʩչ" HUI "��\n");

        if (me->query_skill_prepared("strike") != "dragon-strike")
                return notify_fail("��û��׼������ʮ���ƣ�����ʩչ" HUI "��\n");

        if ((int)me->query("neili") < 1000)
                return notify_fail("��������������������ʩչ" HUI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        // ��һ��
        ap = ap_power(me, "strike") + me->query("str") * 10;
        dp = dp_power(target, "dodge") + target->query("dex") * 10;
        
        message_sort(HIW "\n��Ȼ��$N" HIW "���μ���������һ�������ֺ���һ�ƣ���"
                     "��$n" HIW "��ȥ�����ǽ���ʮ���ơ�" NOR + HIY "�����л�" NOR
                     + HIW "��һ�У���������֮��˵���㵽������ɽ����֮����$n" HIW
                     "��ӿ��ȥ������ʯ���쾪�������ޱȡ�\n" NOR, me, target);
        if (ap * 3 / 5 + random(ap) > dp)
        {
                damage = da_power(me, "strike");
                msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 40,
                                          HIR "$p" HIR "һ�㣬ֻ��$P" HIR "����"
                                          "һ�����ѻ����Լ���ǰ����������������"
                                          "�����С�\n:����@?");

                message_vision(msg, me, target);

        } else
        {
                msg = HIC "$p" HIC "����˫�ۣ�����Ӧ�ԣ��������࣬$P"
                      HIC "��������ţ�뺣������жȥ��\n" NOR;
                message_vision(msg, me, target);
        }

        // �ڶ���
        ap = ap_power(me, "strike") + me->query("str") * 10;
        dp = dp_power(target, "parry") + target->query("int") * 10;

        message_sort(HIW "\n$N" HIW "һ�Ƽȳ���������Ȼ������$n" HIW "������֮��"
                     "��������ǰ�ƣ������������ϲ�������һ�С�" NOR + HIY "������"
                     "��" NOR + HIW "����������������ŭ����ӿ���Ʋ��ɵ�����ʱ$n"
                     HIW "�����Ϣ���ͣ����㲻�ȡ�\n" NOR, me, target);
        if (ap * 3 / 5 + random(ap) > dp)
        {
                damage = da_power(me, "strike");
                msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 50,
                                           HIR "ֻ��$p" HIR "һ���Һ�����$P" HIR
                                           "һ�ƻ�����ǰ�������꿦�ꡱ���˼�����"
                                           "�ǡ�\n:����@?");

                message_vision(msg, me, target);
        } else
        {
                msg = HIC "$p" HIC "����˫�ۣ�����Ӧ�ԣ��������࣬$P"
                      HIC "��������ţ�뺣������жȥ��\n" NOR;
                message_vision(msg, me, target);
        }

        // ������
        ap = ap_power(me, "strike") + me->query("str") * 10;
        dp = dp_power(target, "force") + target->query("con") * 10;

        message_sort(HIW "\n������$N" HIW "һ�����ȣ�����бб�ӳ���ǰ������δ��"
                     "�����������ֵ�����Ȼ�ֹ���һ�С�" NOR + HIY "�����л�" NOR
                     + HIW "�����Ƽз��ƣ��������񣬱���һ��������ǽ����ǰ�����"
                     "ȥ��$n" HIW "ֻ����Ѫ��ӿ����Ϣ���ǡ�\n" NOR, me, target);

        if (ap * 3 / 5 + random(ap) > dp)
        {
                damage = da_power(me, "strike");
                msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 60,
                                           HIR "���$p" HIR "����������$P" HIR
                                           "���ƾ���ʱ���ض��������ۡ������һ��"
                                           "����Ѫ��\n:����@?");

                message_vision(msg, me, target);
                me->start_busy(1 + random(3));
                me->add("neili", -400 - random(600));
                return 1;
        } else
        {
                msg = HIC "$p" HIC "�������������ͣ����μ��ˣ�˲��Ʈ����"
                      "�ɣ��ѳ�$P" HIC "����֮�⡣\n" NOR;
                message_vision(msg, me, target);
                me->start_busy(1 + random(3));
                me->add("neili", -400 - random(600));
                return 1;
        }
        message_combatd(msg, me, target);
        return 1;
}

