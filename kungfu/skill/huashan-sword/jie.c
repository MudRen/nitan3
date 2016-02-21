// jie.c ��ɽ����������ʽ��

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
        int level;
	string msg;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("��ɽ����������ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if (target->is_busy())
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");
		
	if ((level = me->query_skill("huashan-sword", 1)) < 60)
		return notify_fail("��Ļ�ɽ����������죬����ʹ�á�����ʽ����\n");

        if (me->query("neili") < 80)
                return notify_fail("�����������������޷�ʹ�á�����ʽ����\n");

        msg = HIW "����$N" HIW "����һ�գ�ʹ����ɽ��������֮"
              "������ʽ����ת��֮�������޷죬\nһ���ȳ�������"
              "ԴԴ��к�������Ծ̲����������ѸȻ����$n"
              HIW "��\n" NOR;

        me->add("neili", -40);
	if (random(level) > (int)target->query_skill("parry", 1) / 2)
        {
		msg += HIR "���$p" HIR "�᲻��������������"
                       "������һʱ���޷����֣�\n" NOR;
		target->start_busy(level / 18 + 1);
	} else
        {
		msg += CYN "����$p" CYN "ʶ����$P" CYN "�����⣬"
                       "�Թ˽����еĽ����һ�Ž�Ȧ��$P"
                       CYN "һ��֮����Ҳ������ȥ��\n" NOR;

		me->start_busy(1);
	}
	message_combatd(msg, me, target);

	return 1;
}
