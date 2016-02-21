// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// duo.c ���������
 
#include <ansi.h>
 
inherit F_SSERVER;
#include <balance.h>
 
int perform(object me, object target)
{
        string msg;
        object weapon, weapon2;
        int ap, dp, skill;


//        if (userp(me) && ! me->query("can_perform/zhemei-shou/duo"))
//                return notify_fail("�㻹û������������о������޷�ʩչ��������С�\n");
                
        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }
                
        skill = me->query_skill("zhemei-shou", 1);

        if (! me->is_fighting())
                return notify_fail("���������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
        if (objectp(weapon = me->query_temp("weapon")))
                return notify_fail("�������֡�\n");

        if (! objectp(weapon2 = target->query_temp("weapon")))
                return notify_fail("�Է�û�б��У��㲻�õ��ġ�\n");

        if (skill < 50)
                return notify_fail("�����ɽ��÷�ֵȼ�����, ���ܿ�������У�\n");

        if ((int)me->query_skill("bahuang-gong", 1) < 50 &&
            (int)me->query_skill("xiaowuxiang", 1) < 80 &&
            (int)me->query_skill("beiming-shengong", 1) < 50)
                return notify_fail(RED"�㱾���ڹ���򲻹���ʹ���������ֶ���С���\n"NOR);

        if (me->query("neili") < 100)
                return notify_fail("��������������޷���������У�\n");
 
        msg = CYN "$N�����Ϣ������ʩչ��������еľ���. \n";
        message_combatd(msg, me, target);
 
        ap = ap_power(me, "hand");
        dp = dp_power(target, "parry");
        
        if (ap / 2 + random(ap) > dp)
        {
                me->add("neili", -50);
                msg = "$Nʹ����������еľ���, $n��ʱ������ǰһ��������һ�飬���б������ֶ�����\n" NOR;
                weapon2->move(me);
                if (weapon2->is_item_make() && random(2))
		{
			weapon2->move(target);
			msg += "�ǿ���$n������һ$n��һ�콫���������\n" NOR;
		}
                me->start_busy(2);
        }
        else
        {
                msg = "����$p�Ŀ�����$P����ͼ�����̲�ȡ���ƣ�ʹ$Pû�ܶ��±��С�\n"NOR;
                me->start_busy(2);
        }
        message_combatd(msg, me, target);
        return 1;
}

