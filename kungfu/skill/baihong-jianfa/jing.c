// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// jingtian.c  �׺羪�� 

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon, ob;
        string msg;

        if (! me->is_fighting())
                return notify_fail("���׺羪�졹ֻ����ս����ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query_skill("shenghuo-xuanming", 1) < 100)
                return notify_fail("���ʥ����ڤ����򻹲�����, ����ʹ����һ���� !\n");

        if ((int)me->query_skill("sword", 1) < 100)
                return notify_fail("��Ļ���������򻹲�����, ����ʹ����һ���� !\n");

        if ((int)me->query_skill("baihong-jianfa", 1) < 100)
                return notify_fail("�����ң������򻹲�����, ����ʹ����һ���� !\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("�������������\n");

        if ((int)me->query("max_neili") < 1000)
                return notify_fail("���������Ϊ������\n");

        msg = HIC "\n$N��Хһ�����ֵ�����������Ʈ��������ʹ�����ǰ׺羪�����ľ������׺羪�졹��\n" NOR;
        message_combatd(msg, me);

        me->clean_up_enemy();
        ob = me->select_opponent();
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

        me->add("neili", -random(150) - 50);
        me->start_busy(1 + random(4));      
        return 1;
}

