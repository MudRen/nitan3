// riyue.c ���Ʊ޷�[�����޹�]

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("ǣ�ƹ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( (int)me->query_skill("shigu-bifa",1) < 100)
		return notify_fail("��ġ�ʯ�Ĵ�Ѩ�ʷ�����ûѧ���ң��ò��ˡ���Ѩ�����С�\n");

	if( (int)me->query_skill("wuzheng-xinfa",1) < 100)
		return notify_fail("��ġ������ķ����������죬�ò��ˡ���Ѩ�����С�\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

	msg = HIC "$N�����㣬�����Ͻ������½��������£��������棬$n�ϰ���Ѩ�����������С�\n"NOR;

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 ) {
		msg += HIW"$p�е�˫�֡��ؿڡ�����������Ѩ��΢΢һʹ����ʱȫ����ľ���ܶ�����\n" NOR;
		target->start_busy( (int)me->query_skill("shigu-bifa") / 30 +4);
		me->start_busy(random(2));
		me->add("neili", -200);
	} else {
		msg += HIR"����$p������$P����ͼ����û���ϵ���\n" NOR;
		me->start_busy(2);
	}
	message_vision(msg, me, target);

	return 1;
}
