// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// tong.c ���ͬ��

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        object weapon;
        int ap, dp;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���ͬ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( me->is_busy() )
                return notify_fail("������æ���أ�ʹ������һ�С�\n");

        if( !me->query("can_perform/taiji-jian/tong") )
                 return notify_fail("��δ������ͤ���ڣ�����ʹ�����ͬ�١�\n");

        weapon = me->query_temp("weapon");
        if( ! weapon || weapon->query("skill_type") != "sword" )
                return notify_fail("�������޽������ʹ�����ͬ�٣�\n");

        if( (int)me->query_skill("sword") < 150 )
                return notify_fail("���̫��������������죬����ʹ�����ͬ�١�\n");
                
        if( (int)me->query_skill("taiji-shengong", 1) < 120 )
                return notify_fail("���̫������Ϊ����������ʹ�����ͬ�١�\n");

        if( me->query_skill_mapped("force") != "taiji-shengong")
                return notify_fail("�����õ��ڹ���̫��������·��㣣�\n");

        ap = me->query_int() + me->query_str() + me->query("level") * 20 +
             me->query_dex() + me->query_con();
             
        if (me->query("shen") > target->query("shen") * 3 / 2)
                ap *= 3;
                ap /= 2;
        dp = target->query_int() + target->query_str() + target->query("level") * 20 +
             target->query_dex() + target->query_con();

        msg = HIW "$N" HIW "һ����Х�����Ŀ��Ŵ󿪣���ײ��$n" HIW "���У���ת�������Լ�С��ֱ����£�����\n" NOR;
        me->want_kill(target); 
        me->start_busy(1 + random(2));
        
        if( ap / 2 + random(ap) > dp )
        {
                msg += HIR "$n" HIR "⧲�����֮�£���$N" HIR "ײ�뻳�У�ֻ��С��һ����" NOR + weapon->name() + 
                       HIR "����$N" HIR "��͸����룡����\n" NOR;
                message_combatd(msg, me, target);               
                target->die(me); 
                me->die(target);
                return 1;
        } else 
        {
                msg += HIC "$n" HIC "����$N" HIC "�ô���������æ���ң��Ǳ���״�Ķ�����ȥ�������ŵ������������һ�󶯵����á�\n" NOR;
                me->die(target);
                target->start_busy(3 + random(3));
        }
        
        message_combatd(msg, me, target);       

        return 1;
}

