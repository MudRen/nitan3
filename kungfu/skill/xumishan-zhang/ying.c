// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// ying.c ����ɽ�ơ�Ⱥɽ��Ӱ��

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        string msg;
        int count;
        int lvl;
        int i, ap, dp;

        if (userp(me) && ! me->query("can_perform/xumishan-zhang/ying"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ��Ⱥɽ��Ӱ����\n");
                
        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("��Ⱥɽ��Ӱ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (objectp(me->query_temp("weapon")))
                return notify_fail("�������ֲ���ʹ�á�Ⱥɽ��Ӱ����\n");

        if ((lvl = (int)me->query_skill("xumishan-zhang", 1)) < 150)
                return notify_fail("�������ɽ���Ʋ�����죬����ʹ�á�Ⱥɽ��Ӱ����\n");

        if ((int)me->query("neili", 1) < 500)
                return notify_fail("����������̫��������ʹ�á�Ⱥɽ��Ӱ����\n");

        if (me->query_skill_prepared("strike") != "xumishan-zhang")
                return notify_fail("������û��׼��ʹ������ɽ�ƣ�����ʹ�á�Ⱥɽ��Ӱ����\n");

        msg = HIY "$N" HIY "����ʹ������ɽ���Ƶľ��С�Ⱥɽ��Ӱ����˫��"
              "ƽƽ��$n" HIY "��ȥ��$n" HIY "��ʱ����һ����ɽ������"
              "�������Լ�ӿ����\n" NOR;
        me->add("neili", -150);

        ap = ap_power(me, "strike");
        dp = dp_power(target, "force");
        if (ap / 2 + random(ap) > dp)
        {
                msg += HIR "$n" HIR "��ʱ���ú���������ȫȻ����"
                       "���������ƣ�ֻ��ƴ���˶��ֵ���\n" NOR;
                count = lvl / 5;
                me->add_temp("apply/attack", count);
        } else
        {
                msg += HIC "$n" HIC "����һ����������ֵ�������������"
                       "�ھ��κ���֮�У����ҵ�����ȴ�ǲ�����\n" NOR;
                count = 0;
        }
        message_combatd(msg, me, target);

        for (i = 0; i < 5; i++)
        {
                if (! me->is_fighting(target))
                        break;
                COMBAT_D->do_attack(me, target, 0, 0);
        }

        me->add_temp("apply/attack", -count);
        me->start_busy(3);
        return 1;
}
