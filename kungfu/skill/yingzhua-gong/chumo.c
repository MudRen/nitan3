// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// chumo.c ������ħ
 
#include <ansi.h>
#include <combat.h>
 
inherit F_SSERVER;
#include <balance.h>
 
int perform(object me)
{
        string msg;
        object target;
        int skill, ap, dp, damage;

        if (userp(me) && ! me->query("can_perform/yingzhua-gong/chumo"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ��������ħ����\n");
                
        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail("��������ħ��ֻ����ս���жԶ���ʹ�á�\n");

        skill = me->query_skill("yingzhua-gong", 1);

        if (skill < 135)
                return notify_fail("���ӥצ���ȼ�����������ʹ�á�������ħ����\n");

        if (me->query("neili") < 250)
                return notify_fail("��������������޷����á�������ħ����\n");
 
        if (me->query_skill_mapped("claw") != "yingzhua-gong") 
                return notify_fail("��û�м���ӥצ�����޷�ʹ�á�������ħ����\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "΢΢һЦ��˫�ƻ�������$n" HIY "ץ��������"
              "����ȥҲƽƽ���棬���޶��پ���仯��\n" NOR;
 
        ap = ap_power(me, "claw") + me->query_skill("force");
        dp = dp_power(target, "dodge") + me->query_skill("parry");
        
        if (ap / 2 + random(ap) > dp)
        {
                me->add("neili", -200);
                damage = da_power(me, "claw");
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 45,
                                           HIR "��֪��ô�ģ�$p" HIR "ȴƫƫ�㲻��$P"
                                           HIR "��һץ�������ץ�˸����У����ɵ���"
                                           "��һ�������˼�����\n" NOR);
                me->start_busy(2);
        } else
        {
                msg += CYN "����$p" CYN "û������$P" CYN
                       "��һץ����æ�мܣ�˳��Ծ����û�б�$P"
                       CYN "���֡�\n" NOR;
                me->add("neili",-40);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}

