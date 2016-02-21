// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// shentong.c ���칦 ������ͨ��

// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define FEN "��" HIW "������ͨ��" NOR "��"

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        object weapon;
        int ap, dp, damage;
        string msg;

        if (userp(me) && ! me->query("can_perform/xiantian-gong/shen"))
                return notify_fail("��δ�ø���ָ�㣬��֪�����ʩչ" FEN "��\n"); 

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(FEN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(FEN "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("xiantian-gong", 1) < 240)
                return notify_fail("������칦��Ϊ����������ʩչ" FEN "��\n");

        if (me->query("max_neili") < 4000)
                return notify_fail("���������Ϊ���㣬����ʩչ" FEN "��\n");

        if (me->query_skill_mapped("unarmed") != "xiantian-gong")
                return notify_fail("��û�м������칦Ϊȭ�ţ�����ʩչ" FEN "��\n");

        if (me->query_skill_mapped("force") != "xiantian-gong")
                return notify_fail("��û�м������칦Ϊ�ڹ�������ʩչ" FEN "��\n");

        if (me->query_skill_prepared("unarmed") != "xiantian-gong")
                return notify_fail("��û��׼��ʹ�����칦������ʩչ" FEN "��\n");

        if (me->query("neili") < 1000)
                return notify_fail("�����ڵ��������㣬����ʩչ" FEN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "��������ͨ����Ƭ�̱������������ȫ��˫�۾������䣬��ƽʱ�������ˡ�\n"
              HIW "$N" HIW "����ͻȻ���ƹ���$n��������������Ϣ��ȴѸ�����硣\n" NOR;       

        ap = ap_power(me, "unarmed") + me->query_skill("force") + me->query_skill("martial-cognize", 1);
        dp = dp_power(target, "dodge") + target->query_skill("force") + target->query_skill("martial-cognize", 1);

        if (ap * 2 / 3 + random(ap) > dp)
        {
                damage = 0;
                if (me->query("max_neili") > target->query("max_neili") * 2)
                {
                        me->start_busy(2);
                        msg += HIR "$n" HIR "��������Ӧ������$N������ͨ�������񹦻��С�\n" NOR "( $n"
                               RED "���˹��أ��Ѿ�������в�����ʱ�����ܶ���"
                               "��" NOR ")\n";
                        damage = -1;
                } else
                {
                        me->start_busy(3);
                        damage = da_power(me, "unarmed") * 2;
                        me->add("neili", -500);
                        msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 90,
                                                   HIR "���$N" HIR "������ͨ������$n" HIR "��"
                                                   "�ڣ�������ͨ����ʱ͸�ض��룬$n" HIR "���������"
                                                   "����Ѫ��\n" NOR);
                }
        } else
        {
                me->start_busy(5);
                me->add("neili", -120);
                msg += CYN "����$p" CYN "ʶ����$P"
                       CYN "��һ�У���ȴ���Ǳ��Ķ�ܿ�����\n" NOR;
        }
        message_combatd(msg, me, target);

        if (damage < 0)
                target->die(me);

        return 1;
}
