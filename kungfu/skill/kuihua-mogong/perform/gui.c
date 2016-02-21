// gui.c ������

#include <ansi.h>

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
	string msg;
        int ap, dp;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (target->is_busy())
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");
		
	if ((int)me->query_skill("kuihua-mogong", 1) < 100)
		return notify_fail("��Ŀ���ħ��������񣬲���ʹ�ù�������\n");
		
        if (me->query_skill_mapped("dodge") != "kuihua-mogong")
                return notify_fail("��û�м�������ħ��Ϊ�����Ṧ������ʩչ��������\n");
                
        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIR "$N" HIR "���Ӻ������ˣ����ι����쳣����$n"
              HIR "���Ʈ��������\n" NOR;

        ap = ap_power(me, "dodge") + me->query("int") * 20;
        dp = dp_power(target, "parry") + target->query("int") * 20;

	if (ap / 2 + random(ap) > dp)
        {
		msg += HIR "���$p" HIR "ֻ�ܽ����Ż����������Գ�����\n" NOR;
                target->start_busy(ap / 100 + 2);
	} else
        {
		msg += CYN "����$p" CYN "������$P" CYN "��������û"
                       "���ܵ��κ�Ӱ�졣\n" NOR;
		me->start_busy(1);
	}
	message_combatd(msg, me, target);

	return 1;
}
