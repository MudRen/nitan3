// lu.c ¾�ɾ�
 
#include <ansi.h>
#include <combat.h>
 
inherit F_SSERVER;
#include <balance.h>
 
int perform(object me, object target)
{
	string msg;
	int ap, dp;
        int damage;

        if (! target)
        {
        	me->clean_up_enemy();
        	target = me->select_opponent();
        }

	if (! target || ! me->is_fighting(target))
		return notify_fail("¾�ɾ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
	if (me->query_skill("bluesea-force", 1) < 120)
		return notify_fail("����Ϻ�������������죬����ʹ��¾�ɾ���\n");

        if (me->query("neili") < 200)
                return notify_fail("�����������������ʹ��¾�ɾ���\n");
 
       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIC "$N" HIC "��Ȼ��Ц���ĳ�һ�ƣ��������£��仯Ī�⣬����$n"
              HIC "��\n" NOR;
 
        ap = ap_power(me, "force") + me->query("con") * 20;
        dp = dp_power(target, "parry") + target->query("con") * 20;

        me->start_busy(2);
        me->add("neili", -50);
        if (ap + random(ap) < dp)
        {
		msg += HIG "Ȼ��$n" HIG "������$N" HIG
                       "�����ƣ����Ų�æ�Ķ������һ����\n" NOR;
        } else
	{
		me->add("neili",-75);
                damage = da_power(me, "force");
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 60,
                                           HIR "$n" HIR "�������ԣ��˹��ֵ���ֻ����$P��������"
                                           "��֮����ֱ�������澭��������ʱ�������ˣ�\n" NOR);
	}

	message_combatd(msg, me, target);
	return 1;
}
