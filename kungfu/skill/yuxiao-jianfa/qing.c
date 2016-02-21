// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define QING "��" HIG "����鳤" NOR "��"

inherit F_SSERVER;
#include <balance.h>

int perform(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp;
        int cost;

        if (userp(me) && ! me->query("can_perform/yuxiao-jianfa/qing"))
                return notify_fail("�㻹����ʹ��" QING "��һ������\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(QING "ֻ�ܶ�ս���еĶ���ʹ�á�\n");
                
        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" QING "��\n");

        if (me->query_skill_mapped("sword") != "yuxiao-jianfa")
                return notify_fail("��û�м������｣��������ʩչ" QING "��\n");

        skill = me->query_skill("yuxiao-jianfa", 1);

        if (skill < 150)
                return notify_fail("�����｣���ȼ�����������ʩչ" QING "��\n");

        if (target->query("neili") < 300)
                return notify_fail("�����ӶԷ������������棬��������" QING "��\n");

        if (me->query("neili") < 1000)
                return notify_fail("�����ڵ��������㣬����ʩչ" QING "��\n");

        if (! living(target))
               return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIG "$N" HIG "���е�" + weapon->name() + HIG "ٿ�Ĵ̳�������һ��"
              "����������ס������������\n" NOR;

        ap = ap_power(me, "sword") + 
             me->query_skill("chuixiao-jiafa", 1);
        dp = dp_power(target, "force") +
             target->query_skill("chuixiao-jiafa", 1);
             
        if (ap > dp && ap / 2 + random(ap) > dp)
        {
                me->add("neili", -500);
                msg += HIM "$p" HIM "�پ�$P" HIM "������������һ���������У���"
                       "��׽��ȥ����ֻ��ǿ������������\n" NOR;
                cost = 500 + (ap - dp) * 3 / 2;
                if (cost > target->query("neili"))
                        cost = target->query("neili");
                target->add("neili", -cost);
                me->start_busy(1 + random(3));
        } else
        {
                me->add("neili", -120);
                msg += HIC "����$p" HIC "���񰲶���˿��û���ܵ�����\n"NOR;
                me->start_busy(2);
        }
        message_combatd(msg, me, target);
        return 1;
}

