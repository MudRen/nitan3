// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// wuchang.c �޳��廯

#include <ansi.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon;
        string msg;
        int i;

        if (userp(me) && ! me->query("can_perform/wuchang-zhang/wuchang"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ���޳��廯����\n");
 
        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail("���޳��廯��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "staff")
                return notify_fail("ʩչ���޳��廯��ʱ��������һ�ѽ���\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("��������������޷�ʩչ���޳��廯����\n");

        if ((int)me->query_skill("force") < 200)
                return notify_fail("����ڹ���򲻹�������ʩչ���޳��廯����\n");

        if ((int)me->query_skill("wuchang-zhang", 1) < 150)
                return notify_fail("����޳��ȷ��������ң��޷�ʹ�á��޳��廯����\n");

        if (me->query_skill_mapped("staff") != "wuchang-zhang")
                return notify_fail("��û�м����޳��ȷ�������ʹ�á��޳��廯����\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "�����е�" + weapon->name() +
             HIY "һ��������������Ӱɨ��$n" HIY "��\n" NOR;
        message_combatd(msg, me, target);

        me->add("neili", -100);

        for (i = 0; i < 5; i++)
        {
                if (! me->is_fighting(target))
                        break;
                if (random(3) == 1 && ! target->is_busy())
                        target->start_busy(1);
                COMBAT_D->do_attack(me, target, weapon, 0);
        }

        me->start_busy(1 + random(5));
        return 1;
}

