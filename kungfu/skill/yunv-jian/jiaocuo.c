// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// he.c ˫������

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        object weapon;
        int damage, ap, dp;
        string msg;
        
        /*
        if (userp(me) && ! me->query("can_perform/yunv-jian/jiaocuo"))
                return notify_fail("��δ�ø���ָ�㣬��֪�����ʩչ��˫��������\n");
        */
                      
        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("˫������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query_skill("force") < 120)
                return notify_fail("����ڹ�������죬����ʹ��˫������\n");

        if ((int)me->query_skill("yunv-jian", 1) < 80)
                return notify_fail("�����Ů����������죬����ʹ��˫������\n");

        if ((int)me->query_skill("quanzhen-jian", 1) < 50)
                return notify_fail("���ȫ�潣��������죬����ʹ��˫������\n");

        if ((int)me->query("neili", 1) < 400)
                return notify_fail("����������̫��������ʹ��˫������\n");

        if (me->query_skill_mapped("sword") != "yunv-jian")
                return notify_fail("��û�м�����Ů����������ʹ��˫������\n");

        msg = HIY "$N" HIY "������ȫ�潣�����⣬���ֻ���Ů������"
              "�У�˫������ͬʱ�̳���\n" NOR;

        ap = me->query_skill("sword") * 2 / 3 + me->query("level") * 20 +  
             me->query_skill("martial-cognize", 1); 

        dp = target->query_skill("force") + target->query("level") * 20 +
             target->query_skill("martial-cognize", 1); 

        if (ap / 2 + random(ap) > dp) 
        {
                me->start_busy(2);

                damage = (int)me->query_skill("sword", 1) +
                         (int)me->query_skill("quanzhen-jian", 1) +
                         (int)me->query_skill("yunv-jian", 1);

                damage = damage / 4 + random(damage / 4);
                me->add("neili", -350);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 55,
                                           HIR "$n" HIR "����$N" HIR "˫�����裬��ʽ������"
                                           "������Ϊ��һ����ȥ������֪����Ǻã�\n"
                                           HIR"һ��֮�£�$N" HIR "�Ľ����Ѿ���ʽ���룡$n"
                                           HIR "һ���ҽ�֮�£���ʱ�����ش���\n" NOR);
        } else
        {
                me->start_busy(3);
                msg += CYN "����$p" NOR CYN "������$P" NOR CYN "����ͼ����"
                       "�Լ���ȫ�����»����ܲ�͸�磬��$P" NOR CYN "�޼ƿ�ʩ��\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}
