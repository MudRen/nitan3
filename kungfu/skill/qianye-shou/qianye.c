// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// qianye.c ǧҶ����
 
#include <ansi.h>
#include <combat.h>
 
inherit F_SSERVER;
#include <balance.h>
 
int perform(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp, damage;

        if (userp(me) && ! me->query("can_perform/qianye-shou/qianye"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ��ǧҶ���֡���\n");
                
        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail("��ǧҶ���֡�ֻ����ս���жԶ���ʹ�á�\n");

        skill = me->query_skill("qianye-shou", 1);

        if (skill < 120)
                return notify_fail("���ǧҶ�ֵȼ�����������ʹ�á�ǧҶ���֡���\n");

        if (me->query("neili") < 100)
                return notify_fail("��������������޷����á�ǧҶ���֡���\n");
 
        if (me->query_skill_mapped("hand") != "qianye-shou") 
                return notify_fail("��û�м���ǧҶ�֣��޷�ʹ�á�ǧҶ���֡���\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIC "$N" HIC "ٿ�Ŀ���$n" HIC "������һ�Σ�"
              "����������Ӱ����ͬ����ǧ��ֻ��һ�빥��" HIC
              "$n��\n" NOR;
 
        ap = ap_power(me, "hand") +
             me->query_skill("force");

        dp = dp_power(target, "parry") +
             target->query_skill("dodge");
             
        if (ap / 2 + random(ap) > dp)
        {
                me->add("neili", -100);
                damage = da_power(me, "hand");
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 35,
                                           HIR "$p" HIR "�������мܣ����޷���ܣ������$P"
                                           HIR "��������Ū����ͷת������Ҳ���˺����ۡ�\n" NOR);
                me->start_busy(2);
                if (ap / 3 + random(ap) > dp && ! target->is_busy())
                        target->start_busy(ap / 100 + 2);
        } else
        {
                msg += CYN "����$p" CYN "�Ŀ�����$P" CYN
                       "����ʽ����������ȫȻ������$P"
                       CYN "�Ĺ��ơ�\n" NOR;
                me->add("neili",-30);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}

