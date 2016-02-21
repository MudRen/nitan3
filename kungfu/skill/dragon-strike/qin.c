#include <ansi.h>

inherit F_SSERVER;

#define QIN "��" HIR "������" NOR "��"
#include <balance.h>

int perform(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp;

        if (userp(me) && ! me->query("can_perform/dragon-strike/qin"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ" QIN "��\n"); 

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(QIN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(QIN "ֻ�ܿ���ʹ�á�\n");

        if (! objectp(weapon = target->query_temp("weapon")))
                return notify_fail("�Է�û��ʹ�ñ���������ʩչ" QIN "��\n");

        if ((int)me->query_skill("force") < 260)
                return notify_fail("���ڹ���Ϊ����������ʩչ" QIN "��\n");

        if ((int)me->query("max_neili") < 3000)
                return notify_fail("��������Ϊ����������ʩչ" QIN "��\n");

        if ((int)me->query_skill("dragon-strike", 1) < 180)
                return notify_fail("�㽵��ʮ���ƻ�򲻹�������ʩչ" QIN "��\n");

        if (me->query_skill_mapped("strike") != "dragon-strike")
                return notify_fail("��û�м�������ʮ���ƣ�����ʩչ" QIN "��\n");

        if (me->query_skill_prepared("strike") != "dragon-strike")
                return notify_fail("��û��׼������ʮ���ƣ�����ʩչ" QIN "��\n");

        if ((int)me->query("neili") < 400)
                return notify_fail("��������������������ʩչ" QIN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIR "$N" HIR "����һ����ȫ���ھ��ŷ��������ұ۷����⳶����ͼ��$n"
              HIR "��" + weapon->name() + HIR "�������С�\n" NOR;

        ap = ap_power(me, "strike") + me->query("str") * 10;
        dp = dp_power(target, "parry") + target->query("int") * 10;

        if (ap / 3 + random(ap) > dp)
        {
                me->add("neili", -300);
                msg += HIR "$n" HIR "ֻ����Χ����ӿ��������" + weapon->name()
                       + HIR "��Ȼ����ס����$N" HIR "�������ַ�ȥ��\n" NOR;
                me->start_busy(2);
                weapon->move(me, 1);
        } else
        {
                me->add("neili", -200);
                msg += CYN "$n" CYN "ֻ����Χ����ӿ������æ����������"
                       + weapon->name() + CYN "������ܲ�͸�磬ʹ��$N"
                       CYN "�޴����֡�\n" NOR;
                me->start_busy(3);
        }
        message_combatd(msg, me, target);
        return 1;
}

