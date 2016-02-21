// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define ZHAN "��" HIW "ճ�־�" NOR "��"

inherit F_SSERVER;
#include <balance.h>
 
int perform(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp, damage;

        if (userp(me) && ! me->query("can_perform/taiji-quan/zhan"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ" ZHAN "��\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(ZHAN "ֻ�ܿ���ʩչ��\n");

        skill = me->query_skill("taiji-quan", 1);

        if (skill < 150)
                return notify_fail("���̫��ȭ�ȼ�����������ʩչ" ZHAN "��\n");

        if (me->query("neili") < 300)
                return notify_fail("�����������������ʩչ" ZHAN "��\n");
 
        if (me->query_skill_mapped("cuff") != "taiji-quan")
                return notify_fail("��û�м���̫��ȭ������ʩչ" ZHAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "��������˫�ֳ�Բ�λ�������"
              "����̫��ȭ��Բת���ϡ����ֵľ��⡣ֻ\n��$N"
              HIW "�漴ƽȦ����Ȧ����Ȧ��бȦ��һ������һ"
              "����һ����̫��ԲȦ��ʱ��\n��$n" HIW "����"
              "�˷���\n" NOR;

        ap = ap_power(me,"cuff");
        dp = dp_power(target,"parry");
        if (ap / 2 + random(ap * 4 / 3) > dp)
        {
                me->add("neili", -100);
                damage = da_power(me, "cuff");
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 20,
                                           HIR "$n" HIR "��ʱ�㱻�׵õ���ײײ����"
                                           "�����������㲻�ȣ������оƻ��ԡ�\n"
                                           NOR);
                me->start_busy(2);
                if (ap / 2 + random(ap) > dp && ! target->is_busy())
                        target->start_busy(2 + ap / 100);
        } else
        {
                msg += CYN "����$p" CYN "�Ŀ�����$P" CYN
                       "����ͼ������Ĳ��У�û¶�������"
                       "��\n" NOR;
                me->add("neili", -50);
                me->start_busy(2);
        }
        message_combatd(msg, me, target);

        return 1;
}

