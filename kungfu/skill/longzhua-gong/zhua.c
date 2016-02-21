// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// zhua.c ����ץ
 
#include <ansi.h>
#include <combat.h>
 
inherit F_SSERVER;
#include <balance.h>
 
int perform(object me)
{
        string msg;
        object target;
        int skill, ap, dp, damage;

        if (userp(me) && ! me->query("can_perform/longzhua-gong/zhua"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ������ץ����\n");
                
        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail("������ץ��ֻ����ս���жԶ���ʹ�á�\n");

        skill = me->query_skill("longzhua-gong", 1);

        if (skill < 135)
                return notify_fail("�����צ���ȼ�����������ʹ�á�����ץ����\n");

        if (me->query("neili") < 200)
                return notify_fail("��������������޷����á�����ץ����\n");
 
        if (me->query_skill_mapped("claw") != "longzhua-gong") 
                return notify_fail("��û�м�����צ�����޷�ʹ�á�����ץ����\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "���һ������������$n" HIY "��ǰ���漴����ץ��"
              "$p" HIY "��Ҫ����\n" NOR;
 
        ap = ap_power(me, "claw") + me->query_skill("force"); 
        dp = dp_power(target, "parry") + target->query_skill("dodge"); 
        
        if (ap / 2 + random(ap) > dp)
        {
                me->add("neili", -180);
                damage = da_power(me, "claw");
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 45,
                                           HIR "$p" HIR "���������ͣ����Զ�ܣ�ֻ��"
                                           "��ǿ���⣬˭֪$P" HIR "���ֺ������۾�"
                                           "һ�㣬����һ����ץ��$p" HIR "��Ҫ������"
                                           "ʱ��Ѫ�ɽ���\n" NOR);
                me->start_busy(2);
        } else
        {
                msg += CYN "����$p" CYN "�Ŀ�����$P" CYN
                       "����ʽ����������ȫȻ������$P"
                       CYN "�Ĺ��ơ�\n" NOR;
                me->add("neili",-60);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}

