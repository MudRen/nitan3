// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define NING "��" HIM "����һ��" NOR "��"

inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;
 
        if (! target) target = offensive_target(me);

        if (userp(me) && ! me->query("can_perform/yunv-sword/ning"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ" NING "��\n");

        if (! target || ! me->is_fighting(target))
                return notify_fail(NING "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" NING "��\n");

        if (me->query_skill("dodge", 1) < 100)
                return notify_fail("��Ļ����Ṧ����Ϊ����������ʩչ" NING "��\n");

        if (me->query_skill("force", 1) < 100)
                return notify_fail("��Ļ����ڹ�����Ϊ����������ʩչ" NING "��\n");

        if (me->query_skill("yunv-sword", 1) < 100)
                return notify_fail("�����Ů������Ϊ����������ʩչ" NING "��\n");

        if (me->query_skill_mapped("sword") != "yunv-sword")
                return notify_fail("��û�м�����Ů����������ʩչ" NING "��\n");

        if (me->query("neili") < 250)
                return notify_fail("��������������������ʩչ" NING "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "\n$N" HIW "����һ�����������ʹ�����С�" HIM "����һ��" HIW "����������������"
              + weapon->name() + HIW "�ϣ���ʱ�������䣬������磬��$n" HIW "����" HIW "��\n" NOR;

        ap = me->query_skill("sword") + me->query("level") * 20 + 
             me->query_skill("martial-cognize", 1);
        dp = target->query_skill("parry") + target->query("level") * 20 + 
             target->query_skill("martial-cognize", 1);

        if (ap * 11 / 20 + random(ap) > dp)
        {
                damage = ap / 2 + random(ap / 2);
                me->add("neili", - 220);
                me->start_busy(1 + random(3));
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 65,
                                           HIR "$n" HIR "���ϲ���������������ȴ�Ѿ��н���\n" NOR);
        } else
        {
                me->add("neili", -120);
                me->start_busy(2);
                msg += CYN "����$n" CYN "�����мܣ��������л��⡣\n"NOR;
        }

        message_sort(msg, me, target);

        return 1;
}

