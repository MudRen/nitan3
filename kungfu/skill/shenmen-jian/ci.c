// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
inherit F_SSERVER;
#include <balance.h>

int perform(object me)
{
        string msg;
        object weapon, weapon2, target;
        int skill, ap, dp;

        if (userp(me) && ! me->query("can_perform/shenmen-jian/ci"))
                return notify_fail("�㻹����ʹ�á����Ŵ̡���һ�С�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        skill = me->query_skill("shenmen-jian", 1);

        if( !(me->is_fighting() ))
                return notify_fail("���Ŵ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (!objectp(weapon2 = target->query_temp("weapon")))
                return notify_fail("�Է�û��ʹ�ñ��������������Ŵ�Ҳû�á�\n");

        if( skill < 160)
                return notify_fail("�������ʮ�����ȼ�����, �޷�ʩչ���Ŵ̡�\n");

        if( me->query("neili") < 200 )
                return notify_fail("��������������޷�ʩչ���Ẉ̂�\n");

        msg = HIY "ͻȻ$N" HIY "һ����ߣ�����" +weapon->name()+ NOR + HIY
                  "�й�ֱ����ֱ��$n���ŵ�" +weapon2->name()+ NOR + HIY"��"
                  "����\n" NOR;
        message_combatd(msg, me, target);

        ap = ap_power(me, "sword");
        dp = dp_power(target, "parry");

        if( ap / 2 + random(ap) > dp )
        {
                if (userp(me))
                me->add("neili", -120);
                msg = HIR "$nֻ������һ���ʹ������" +weapon2->name()+ NOR + HIR
                      "��Ҳ׽�ò�ס�����ֶ��ɣ�\n" NOR;
                me->start_busy(1 + random(2));
                if (! target->is_busy())
                target->start_busy(2);
                weapon2->move(environment(target));
        }
        else
        {
                if(userp(me))
                me->add("neili", -40);
                msg = CYN "����$n������$N����ͼ�������б��л�����ܲ�͸�磬������$N" CYN 
                      "�ı�����\n"NOR;
                me->start_busy(4);
        }
        message_combatd(msg, me, target);
        return 1;
}
