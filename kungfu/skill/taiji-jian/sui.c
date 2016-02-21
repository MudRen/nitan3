// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// sui.c ���־�

#include <ansi.h>

#define PFM_NAME        "���־�"

inherit F_SSERVER;

void remove_effect(object me, int a_amount, int d_amount);

int perform(object me, object target)
{
        object weapon;
        int skill;
        string msg;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (userp(me) && ! me->query("can_perform/taiji-jian/sui"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ��" PFM_NAME "����\n");
                
        if (! target || ! me->is_fighting(target))
                return notify_fail("��" + PFM_NAME + "��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("�����ý�����ʩչ��" + PFM_NAME + "����\n");

        if ((int)me->query_skill("taiji-jian", 1) < 100)
                return notify_fail("���̫������������죬����ʹ�á�" + PFM_NAME + "����\n");

        if ((int)me->query_skill("taiji-shengong", 1) < 80)
                return notify_fail("���̫���񹦻�򲻹�������ʩչ��" + PFM_NAME + "����\n");

        if ((int)me->query("neili") < (int)me->query("max_neili") / 50)
                return notify_fail("�������������\n");

        if ((int)me->query_temp("tjj_sui")) 
                return notify_fail("���Ѿ����˹����ˡ�\n");

        skill = me->query_skill("taiji-jian");
        msg = HIC "$Nʹ��̫���������桹�־�����Ȧ����С������" + weapon->name() +
              HIC "�ó������⻷��������ס��\n" NOR;
        message_combatd(msg, me, target);

        me->add_temp("apply/attack", -skill/6);
        me->add_temp("apply/defense", skill);
        me->set_temp("tjj_sui", 1);

        me->start_call_out((: call_other, __FILE__, "remove_effect", me, skill/6, skill :), skill);

        me->add("neili", -(int)me->query("max_neili") / 50);
        if(me->is_fighting()) me->start_busy(2);

        return 1;
}

void remove_effect(object me, int a_amount, int d_amount)
{
        me->add_temp("apply/attack", a_amount);
        me->add_temp("apply/defense", - d_amount);
        me->delete_temp("tjj_sui");
        tell_object(me, HIG "��ġ�" + PFM_NAME + "��������ϣ��������ջص��\n" NOR);
}

