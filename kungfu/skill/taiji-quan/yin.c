// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define YIN "��" HIW "���־�" NOR "��"

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        int skill, ap, dp, damage;
        string msg;

        if (userp(me) && ! me->query("can_perform/taiji-quan/yin"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ" YIN "��\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(YIN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(YIN "ֻ�ܿ���ʩչ��\n");

        skill = me->query_skill("taiji-quan", 1);

        if (skill < 150)
                return notify_fail("���̫��ȭ�ȼ�����������ʩչ" YIN "��\n");

        if (me->query("neili") < 300)
                return notify_fail("�����������������ʩչ" YIN "��\n");
        
        /*
        if (me->query_skill_mapped("cuff") != "taiji-quan")
                return notify_fail("��û�м���̫��ȭ������ʩչ" YIN "��\n");

        if (me->query_skill_prepared("cuff") != "taiji-quan")
                return notify_fail("������û��׼��ʹ��̫��ȭ���޷�ʹ��" YIN "��\n");
        */
        
        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "˫��һȦ��ʩ���������־����籧̫����һ��"
              "�ۻ��ޱȵ����������һ�����У�Ȧ��$n" HIW "��\n" NOR;
        me->add("neili", -100);

        ap = ap_power(me,"cuff");
        dp = dp_power(target,"parry");
        
        if (ap / 2 + random(ap * 4 / 3) > dp)
        {
                me->add("neili", -10);
                damage = da_power(me, "cuff");
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 0,
                                           HIR "$n" HIR "΢΢һ�㣬��ʱ����������"
                                           "����ԭ�ؼ�ת�߰��£���ת���ݣ�������"
                                           "����\n" NOR);
                me->start_busy(1);
                if (ap / 2 + random(ap) > dp && ! target->is_busy())
                        target->start_busy(ap / 80 + 2);
        } else
        {
                msg += CYN "$n" CYN "��״��æʹ����ǧ��׹��֮����"
                       "ס���Σ�������$N" CYN "��������\n" NOR;
                me->add("neili", -50);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}

