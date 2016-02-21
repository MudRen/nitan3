// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define YONG "��" HIW "������ӿ" NOR "��"

inherit F_SSERVER;
#include <balance.h>
 
int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;
 
        if (! target) target = offensive_target(me);

        if (userp(me) && ! me->query("can_perform/kuangfeng-jian/yong"))
                return notify_fail("�㻹û������������о������޷�ʩչ��\n");

        if (! target || ! me->is_fighting(target))
                return notify_fail(YONG "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" YONG "��\n");

        if (me->query_skill("dodge", 1) < 140)
                return notify_fail("��Ļ����Ṧ����Ϊ����������ʩչ" YONG "��\n");

        if (me->query_skill("kuangfeng-jian", 1) < 140)
                return notify_fail("��Ŀ��콣��Ϊ����������ʩչ" YONG "��\n");

        if (me->query_skill_mapped("sword") != "kuangfeng-jian")
                return notify_fail("��û�м������콣������ʩչ" YONG "��\n");

        if (me->query("neili") < 250)
                return notify_fail("��������������������ʩչ" YONG "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "�����������ת����" + weapon->name() + HIW "��ɲ�Ǽ�����"
              "������𣬷���������" + weapon->name() + HIW "�͵ؾ���$n" HIW "��\n" NOR;

        ap = ap_power(me, "sword") + me->query_skill("dodge");
        dp = dp_power(target, "parry") + target->query_skill("dodge");

        if (ap / 2 + random(ap) > dp)
        {
                damage = da_power(me, "sword");
                me->add("neili", - 230);
                me->start_busy(2);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 65 + random(6),
                                           HIR "$n" HIR "����Ŀ�ɿڴ���ֻ��һ���紵����" + weapon->name() + HIR 
                                           "ȴ��͸�ض�����\n" NOR);
        } else
        {
                me->add("neili", -120);
                me->start_busy(2);
                msg += CYN "����$n" CYN "΢΢һЦ�������㿪��$N"
                       CYN "�Ľ��С�\n"NOR;
        }

        message_combatd(msg, me, target);

        return 1;
}

