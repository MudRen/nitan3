// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// jingmo.c ��ħһָ

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        int damage;
        string msg;
        int ap, dp;

        if (userp(me) && ! me->query("can_perform/yizhi-chan/jingmo"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ����ħһָ����\n");
                
        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }
        if (! target || ! me->is_fighting(target))
                return notify_fail("����ħһָ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if ((int)me->query_skill("yizhi-chan", 1) < 120)
                return notify_fail("���һָ����������죬���ڻ��޷�ʹ�á���ħһָ����\n");

        if ((int)me->query_skill("force") < 180)
                return notify_fail("����ڹ���򲻹�������ʩչ����ħһָ����\n");
                                
        if ((int)me->query("neili") < 200)
                return notify_fail("�����������������޷����á���ħһָ����\n");
                        
        if (me->query_skill_mapped("finger") != "yizhi-chan") 
                return notify_fail("��û�м���һָ�����޷�ʹ�þ�ħһָ��\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "���һ������ָ������һ��������ɱ������$n"
              HIY "�����ƻֺ�֮����\n" NOR;

        ap = ap_power(me, "finger");
        dp = dp_power(target, "dodge");
        
        if (ap / 2 + random(ap) > dp)
        {
                damage = da_power(me, "finger");
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 50,
                                           HIR "ֻ��$p" HIR "������������$P"
                                           HIR "��һָ��������ǰ�����ɵ�����"
                                           "�ҽУ��ؿ���Ѫֱ����\n" NOR);
                me->start_busy(2);
        } else 
        {
                msg += CYN "����$p" CYN "��æԾ�����㿪��$P"
                       CYN "��һָ��\n" NOR;
                me->add("neili", -60);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}

