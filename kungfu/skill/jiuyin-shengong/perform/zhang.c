// zhang.c ��������

#include <ansi.h>

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
	string msg;
        int ap, dp;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (target->is_busy())
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");
		
	if ((int)me->query_skill("jiuyin-shengong", 1) < 100)
		return notify_fail("��ľ����񹦲�����񣬲���ʹ�þ������ơ�\n");

//        if (me->query_skill_prepared("strike") != "jiuyin-shengong")
        if (me->query_skill_mapped("strike") != "jiuyin-shengong")
                return notify_fail("��û��׼��ʹ�þ����񹦣��޷�ʩչ�������ơ�\n");
                
        if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIY "$N" HIY "˫��һ���û���������Ӱ����������$n"
              HIY "��ȥ��\n" NOR;

	ap = ap_power(me, "strike");
	dp = dp_power(target, "parry");

        if (ap / 2 + random(ap) > dp)
        {
		msg += HIR "���$p" HIR "��$P" HIR "�Ƶ�ʩչ���������ʽ��\n" NOR;
		target->start_busy(ap / 80 + 2);
	} else
        {
		msg += CYN "����$p" CYN "������$P" CYN "��������·��"
                       "��������Ӧ�����硣\n" NOR;
		me->start_busy(1);
	}
	message_combatd(msg, me, target);

	return 1;
}
