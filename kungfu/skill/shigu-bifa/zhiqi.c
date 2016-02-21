// poqizhen.c ������
 
#include <ansi.h>
 
inherit F_SSERVER;
 
int perform(object me)
{
	string msg;
	object weapon, target;
	int skill, ap, dp, neili_wound, qi_wound;

	me->clean_up_enemy();
	target = me->select_opponent();

	skill = me->query_skill("shigu-bifa",1);

	if( !(me->is_fighting() ))
		return notify_fail("��������ֻ����ս�������ڶ������ϡ�\n");
 
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "dagger")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if( skill < 80)
		return notify_fail("�����ĸ�뷨��������, ����ʹ�á�����\n");

	if( me->query("neili") < 150 )
		return notify_fail("��������������޷����á���������\n");
 
	msg = HIR "$N���һ����$n�����������㣬�����ǡ��ᡱ�ֵ��������ʣ����϶��µĻ���������\n";
	message_vision(msg, me, target);
 
	ap = me->query_skill("dagger") + skill;
	dp = target->query_skill("force") / 3;
	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me))
			me->add("neili",-100);
		msg = HIR"$N�ʼ�˿������ĵ��жԷ�Ҫ��, $n��ʱ���õ�����һ���ʹ��\n";
		msg += HIR"ȫ��������й������\n" NOR;

		neili_wound = 1000 + random(skill);
		if(neili_wound > target->query("neili"))
			neili_wound = target->query("neili");

		qi_wound = neili_wound / 5;
		if(qi_wound > target->query("qi"))
			qi_wound = target->query("qi");
		if(qi_wound < 0) qi_wound = 0;

		target->add("neili", -neili_wound);
		target->add("qi", -qi_wound);
		target->add("eff_qi", -qi_wound);
		target->start_busy(3);me->start_perform( 4+random(3), "��������");
}
	else
	{
		if(userp(me))
			me->add("neili",-80);
		msg = HIW"����$n˲�䷴Ӧ��������Ų��Ծ�����������ش���\n"NOR;
		me->start_busy(2);
	}
	message_vision(msg, me, target);

	return 1;
}
