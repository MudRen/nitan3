// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// you.c ��Ĺ�ľ�

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        int damage, ap, dp;
        string msg;
        string pmsg;

        if (userp(me) && ! me->query("can_perform/meinv-quan/you"))
                return notify_fail("��δ�ø���ָ�㣬��֪�����ʩչ��Ĺ�ľӡ�\n");
                
        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("��Ĺ�ľ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if ((int)me->query_skill("meinv-quan", 1) < 80)
                return notify_fail("�����Ůȭ���𲻹�������ʹ�ù�Ĺ�ľӡ�\n");

        if ((int)me->query_skill("force") < 120)
                return notify_fail("����ڹ���δ��죬�����������˵С�\n");

        if ((int)me->query("neili") < 150)
                return notify_fail("��������������������ʹ�ù�Ĺ�ľӡ�\n");

        if (me->query_skill_mapped("unarmed") != "meinv-quan")
                return notify_fail("��û�м�����Ůȭ��������ʩչ��Ĺ�ľӡ�\n");

        msg = HIW "$N" HIW "����֧�ã���������ӳ�����̾һ����ʹ"
              "������Ĺ�ľӡ���һ�����ּ���֮�⡣\n" NOR;

        ap = ap_power(me, "unarmed"); 
        dp = dp_power(target, "parry"); 
             
        if (ap / 2 + random(ap) > dp)
        {
                me->start_busy(random(3));

                damage = da_power(me, "unarmed");

                me->add("neili", -100);

                if (damage < 30)
                        pmsg = HIY "���$n" HIY "��$N��"
                               HIY "��һ�����ƺ�һ����\n" NOR;
                else if(damage < 55)
                        pmsg = HIY "���$n" HIY "��$N"
                               HIY "������һ���������ڡ����˳�������\n" NOR;
                else if (damage < 80)
                        pmsg = HIR "���$n" HIR "��$N"
                               HIR "������һ�����ؿ������ܵ�һ����"
                               "������ѪΪ֮һ�ϣ�\n" NOR;
                else
                        pmsg = RED "���$n" RED "��$N" RED
                               "������һ������ǰһ�ڣ�������Ѫ���ڣ�"
                               "���������¯һ�㣡\n" NOR;
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 70, pmsg);
        } else
        {
                me->start_busy(3);
                msg += CYN "����$p" CYN "������$P" CYN
                       "����ͼ������̩ɽ��̧��һ�ܸ���$P"
                       CYN "��һȭ��\n"NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}
