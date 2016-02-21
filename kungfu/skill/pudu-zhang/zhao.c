// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// zhao.c �������

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;

        if (userp(me) && ! me->query("can_perform/pudu-zhang/zhao"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ��������ա���\n");
                 
        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("��������ա�ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "staff")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if (me->query_skill("force") < 200)
                return notify_fail("����ڹ�����Ϊ����������ʹ����һ������\n");

        if (me->query_skill("pudu-zhang", 1) < 135)
                return notify_fail("����ն��ȷ���Ϊ������Ŀǰ����ʹ�÷�����գ�\n");

        if (me->query("neili") < 1000)
                return notify_fail("�����������������ʹ�÷�����գ�\n");

        if (me->query_skill_mapped("staff") != "pudu-zhang")
                return notify_fail("��û�м����ն��ȷ�������ʹ�÷�����գ�\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "������Ц���Ӷ����е�" + weapon->name() +
              HIY "����̩ɽһ��ѹ��$n" + HIY "������̾Ϊ��ֹ��\n" NOR;

        ap = ap_power(me, "staff") + me->query("max_neili") / 10;
        dp = dp_power(target, "force") + target->query("max_neili") / 10;

        if (ap / 2 + random(ap) > dp)
        {
                damage = da_power(me, "staff");
                me->add("neili", -250);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 50,
                                           HIR "ֻ��$p" HIR "�ƺ�һ�������ж���"
                                           "�����������ӷɵ���ȥ�����ص�ˤ���ڵ��ϣ�\n" NOR);
               me->start_busy(2);
        } else
        {
                me->add("neili", -60);
                me->start_busy(3);
                msg += CYN "����$p" CYN "����������������ס��"
                       CYN "$P" CYN "�⾪�춯�ص�һ����\n"NOR;
               me->start_busy(2+random(1));
        }
        message_combatd(msg, me, target);

        return 1;
}

