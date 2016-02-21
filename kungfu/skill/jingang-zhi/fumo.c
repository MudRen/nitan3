// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// fumo.c  ��շ�ħ��

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

        if (userp(me) && ! me->query("can_perform/jingang-zhi/fumo"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ����շ�ħ������\n");
                        
        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("����շ�ħ����ֻ����ս���жԶ���ʹ�á�\n");

        if (me->query_temp("weapon") ||
            me->query_temp("secondary_weapon"))
                return notify_fail("�������ֲ���ʹ�á���շ�ħ������\n");

        if (me->query_skill("force") < 200)
                return notify_fail("����ڹ�����Ϊ����������ʹ����һ������\n");

        if (me->query_skill("jingang-zhi", 1) < 150)
                return notify_fail("��Ĵ������ָ��Ϊ������Ŀǰ����ʹ�á���շ�ħ������\n");

        if (me->query("neili") < 400)
                return notify_fail("��������������޷�ʹ�á���շ�ħ������\n");

        if (me->query_skill_mapped("finger") != "jingang-zhi")
                return notify_fail("��û�м����������ָ������ʹ�á���շ�ħ������\n");

        msg = HIY "$N" HIY "��������һ����⣬���ȫ����������ʳָ����һ��"
              HIY "���������ն�������ͬ����һ�����$n" + HIY "��\n" NOR;

        ap = ap_power(me, "finger");
        dp = dp_power(target, "dodge");

        if (ap / 2 + random(ap) > dp)
        {
                damage = da_power(me, "finger");
                me->add("neili", -200);
                COMBAT_D->do_damage(me, target, REMOTE_ATTACK, damage, damage / 2,
                                    HIR "ֻ��$p" HIR "һ���ҽУ��ѱ������ؿ�ҪѨ��"
                                    "$p" HIR "ֻ�����ؿ���Ѫ��ӿ��ȫ����Ѫ"
                                    "�������۵�һ���³�һ����Ѫ���಻���ԣ�\n" NOR);
                    me->start_busy(2); 
        } else
        {
                me->add("neili", -100);
                me->start_busy(3);
                msg += CYN "����$p" CYN "������$N" CYN "����ͼ������"
                       CYN "���Ʈ�����ɣ��������һ������һ����\n"NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}
