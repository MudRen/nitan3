// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define CHI "��" HIY "���汩��" NOR "��"

inherit F_SSERVER;

string final(object me, object target, int damage);

int perform(object me, object target)
{
        object weapon, weapon2;
        string msg;
        int ap, dp;
        int damage;

        if (userp(me) && ! me->query("can_perform/jinwu-daofa/chi"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ" CHI "��\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(CHI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԣ��޷�ʩչ" CHI "��\n");

        if ((int)me->query_skill("jinwu-daofa", 1) < 120)
                return notify_fail("��Ľ��ڵ���������죬�޷�ʩչ" CHI "��\n");

        if (me->query("neili") < 200)
                return notify_fail("�����������������޷�ʩչ" CHI "��\n");

        if (me->query_skill_mapped("blade") != "jinwu-daofa") 
                return notify_fail("��û�м������ڵ������޷�ʩչ" CHI "��\n");

        if (! living(target))
               return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "�����������ȫ��֮��ע��" + weapon->name() +
              HIY "����˳�����£���ʱһ�������ĵ�âֱ��$n" HIY "��ȥ��\n"
              NOR;

        me->add("neili", -150);
        ap = me->query_skill("blade") + me->query("level") * 20 + 
             me->query_skill("martial-cognize", 1);
        dp = target->query_skill("parry") + target->query("level") * 20 + 
             target->query_skill("martial-cognize", 1);

        if (objectp(weapon2 = target->query_temp("weapon"))
           && (string)weapon2->query("skill_type") == "sword"
           && target->query_skill_mapped("sword") == "xueshan-jian")
        {
                msg += HIY "$n" HIY "��æ��æ��ѩɽ���������ֵ�����֪$N"
                       HIY "��������ѩɽ�������ǰ㣬" + weapon->name() +
                       HIY "��â��ʱ\n�ֱ�����������ȫ����$n" HIY "����"
                       "�н��У�\n" NOR;
                ap += ap / 2;
        }

        me->start_busy(3);
        if (ap / 2 + random(ap) > dp)
        {
                damage = ap / 2 + random(ap / 2);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 40,
                                           (: final, me, target, damage :));
        } else
        {
                msg += HIC "��$n" HIC "ȴ������㣬һ˿���ң�"
                       "ȫ�񽫴��л��⿪����\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}

string final(object me, object target, int damage)
{
        return  HIR "ֻ��$n" HIR "һ���ҽУ�����һ���������У��˿�"
                "��ɼ��ǣ���Ѫ�Ĵ��ɽ���\n" NOR;
}
