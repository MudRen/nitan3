// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define HUAN "��" HIR "���ʽ" NOR "��"

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;
        int ap, dp;

        if (userp(me) && ! me->query("can_perform/liuyang-zhang/huan"))
                return notify_fail("��δ�ø���ָ�㣬��֪�����ʩչ" HUAN "��\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(HUAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(HUAN "ֻ�ܿ���ʩչ��\n");

        if (me->query_skill("force") < 200)
                return notify_fail("����ڹ���򲻹�������ʩչ" HUAN "��\n");

        if ((int)me->query_skill("liuyang-zhang", 1) < 130)
                return notify_fail("�����ɽ�����Ʋ�����죬����ʩչ" HUAN "��\n");

        if (me->query("neili") < 300)
                return notify_fail("�����������������ʩչ" HUAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIR "$N" HIR "˫��һ��ʩ����ɽ�����ơ����ʽ�����ó�"
              "������Ӱ��������ס$n" HIR "��\n" NOR;

        me->add("neili", -50);
        
        ap = ap_power(me, "strike"); 
        dp = dp_power(target, "force"); 
             
        if (ap / 2 + random(ap) > dp)
        {
                damage = da_power(me, "strike");
                me->add("neili", -200);

                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 40,
                                           HIR "$n" HIR "���������ã�ֻ��Ӳ����һ"
                                           "�У���ʱ��$P" HIR "���������������Ѫ"
                                           "��ֹ��\n" NOR);
                me->start_busy(3);
        } else
        {
                me->add("neili", -100);
                msg += HIC "����$p" HIC "ǿ��������Ӳ�����ĵ�ס$P"
                       HIC "��һ�ƣ�û���ܵ��κ��˺���\n"NOR;
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}

