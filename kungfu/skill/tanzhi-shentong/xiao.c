#include <ansi.h>
#include <combat.h>

#define XIAO "��" HIG "Х�׺�" NOR "��"

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        object weapon;
        int ap, dp, damage;
        string msg;

        if (userp(me) && ! me->query("can_perform/tanzhi-shentong/xiao"))
                return notify_fail("����ʱ������ʩչ" XIAO "��\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(XIAO "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(XIAO "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("tanzhi-shentong", 1) < 200)
                return notify_fail("��ĵ�ָ��ͨ������죬����ʩչ" XIAO "��\n");
 
        if (me->query_skill_mapped("finger") != "tanzhi-shentong")
                return notify_fail("��û�м�����ָ��ͨ������ʩչ" XIAO "��\n");

        if (me->query_skill_prepared("finger") != "tanzhi-shentong")
                return notify_fail("��û��׼����ָ��ͨ������ʩչ" XIAO "��\n");

        if (me->query("max_neili") < 3000)
                return notify_fail("���������Ϊ���㣬����ʩչ" XIAO "��\n");

        if (me->query("neili") < 800)
                return notify_fail("�����ڵ���������������ʩչ" XIAO "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIG "ͻȻ��$N" HIG "ָ��һת������ָ�⡰�͡��ĵ���һ����â��ֱϮ$n"
              HIG "������Ѩ��\n" NOR;

        ap = ap_power(me, "finger");
        dp = dp_power(target, "force");

        damage = da_power(me, "finger");

        if (ap * 3 / 2 + random(ap) > dp)
        {
                target->receive_damage("jing", damage * 4 / 3, me);
                target->receive_wound("jing", damage / 3, me);
                target->add("neili", -damage * 3);

                if (target->query("neili") < 0)
                        target->set("neili", 0);

                msg += HIR "$n" HIR "ֻ��$N" HIR "ָ��Ϯ�壬�漴����һ"
                       "��������ٸ�������ɢ�������ʡ�\n" NOR;
                me->start_busy(3);
        } else
        {
                msg += CYN "����$p" CYN "�������ܣ������Ż�����ʱ��$P"
                       CYN "�Ĺ��ƻ�Ϊ���С�\n" NOR;
                me->start_busy(4);
        }
        message_combatd(msg, me, target);

        return 1;
}

