// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// suo.c ������

#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object weapon, weapon2, target;
        int skill, ap, dp, damage;

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("id") != "jinshe jian")
                return notify_fail("��û�ý��߽�������ʹ�þ��У�\n");

        if( me->query("dex") < 20 || me->query("str") < 20 )
                return notify_fail("�����������������, ����ʹ�á�����������\n");

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("jinshe-jian", 1);

        if( !(me->is_fighting() ))
                return notify_fail("����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (!objectp(weapon2 = target->query_temp("weapon")))
                return notify_fail("�Է�û��ʹ�ñ��������ò��ˡ�����������\n");

        if( skill < 150)
                return notify_fail("��Ľ��߽����ȼ�����, ����ʹ�á�����������\n");

        if( me->query("neili") < 300 )
                return notify_fail("��������������޷����á�����������\n");

        msg = HIC "$N����"YEL"���߽�"HIC"����һ����⣬б��һ����������������\n"
              YEL "���߽�"HIC"���⵹�����ù���$n��"+weapon2->name()+"�ϡ�\n";
              
        message_combatd(msg, me, target);

        damage = 100 + random(skill / 2);
        
        ap = me->query_skill("sword") * 3 / 2 + me->query("level") * 20 + 
             me->query_skill("martial-cognize", 1);
        dp = target->query_skill("parry") + target->query("level") * 20 + 
             target->query_skill("martial-cognize", 1);

        if (ap / 2 + random(ap) > dp)
        {
                me->add("neili",-50);
                msg = "$n��ʱ������ǰ���һ��������һ������";
                msg += weapon2->name();
                msg += "���ַɳ���\n" NOR;
                me->start_busy(random(2));
                target->receive_damage("qi", damage);
                target->start_busy(2);
                weapon2->move(environment(me));
        }
        else
        {
                me->add("neili",-30);
                msg = "$n����������������" + weapon2->name()+ "бб˳��һ��һ����˻�����\n"NOR;
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}
