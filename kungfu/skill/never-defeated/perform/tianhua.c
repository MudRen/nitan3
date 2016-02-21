// tianhua.c �컨��׹

#include <ansi.h>

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
	object weapon;
	string msg;
        int ap, dp;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("�컨��׹ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")))
                return notify_fail("������ֱֳ��в���ʩչ�컨��׹��\n");

	if (target->is_busy())
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");

	if ((int)me->query_skill("never-defeated", 1) < 100)
		return notify_fail("��Ĳ����񹦲�����񣬲���ʹ���컨��׹��\n");

        if (me->query_skill_mapped("sword") != "never-defeated") 
                return notify_fail("������û�м���������Ϊ����������ʩչ�컨��׹��\n"); 
                
       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIC "$N" HIC "���е�" + weapon->name() + HIC
              "һ��һ���������˵�ѹ��$n" HIC "��\n" NOR;

        ap = ap_power(me, "sword");
        dp = dp_power(target, "parry");

        if (ap * 11 / 20 + random(ap) > dp)
        {
		msg += HIR "���$p" HIR "��$P" HIR "�Ƶ�ʩչ���������ʽ��\n" NOR;
		target->start_busy(ap / 80 + 2);
	} else
        {
		msg += CYN "����$p" CYN "������$P" CYN "��������"
                       "��������Ӧ�����硣\n" NOR;
		me->start_busy(1);
	}
	message_combatd(msg, me, target);

	return 1;
}
