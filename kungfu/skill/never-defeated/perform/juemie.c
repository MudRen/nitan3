// juemi.c ��ؾ���
 
#include <ansi.h>
#include <combat.h>
 
inherit F_SSERVER;
#include <balance.h>
 
int perform(object me, object target)
{
        object weapon;
	string msg;
	int ap, dp;
        int damage;

        if (! target)
        {
        	me->clean_up_enemy();
        	target = me->select_opponent();
        }

	if (! target || ! me->is_fighting(target))
		return notify_fail("��ؾ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
	if (me->query_skill("never-defeated", 1) < 120)
		return notify_fail("��Ĳ����񹦻�������죬����ʹ����ؾ���\n");

        if (! objectp(weapon = me->query_temp("weapon")))
                return notify_fail("������ֱֳ��в���ʩչ��ؾ���\n");
        
        if (me->query_skill_mapped("sword") != "never-defeated") 
                return notify_fail("������û�м���������Ϊ����������ʩչ��ؾ���\n"); 

        if (me->query("neili") < 200)
                return notify_fail("�����������������ʹ����ؾ���\n");
 
       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIC "$N" HIC "������˼�������Ȼһ�����е�" + weapon->name() +
              HIC "��Ѹ���ޱȵ�ɨ��$n" HIC "���仯����֮��������˼�飡\n" NOR;
 
	ap = ap_power(me, "sword") + me->query("int") * 20;
	dp = dp_power(target, "dodge") + target->query("dex") * 20;

        me->start_busy(2);
        me->add("neili", -50);
        if (ap * 11 / 20 + random(ap) < dp)
        {
		msg += HIG "ֻ��$n" HIG "�������ţ�ֻ������һ�����Ͷ����$N"
	               HIG "��һ����\n"NOR;
        } else
	{
		me->add("neili",-70);
                damage = da_power(me, "sword");
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 40,
                                           HIR "$n" HIR "��æ�񵲣�������һ��ʵ���ǹ���Ī"
                                           "�⣬������ĥ��͸����ʱ����$P" HIR "���ش���\n" NOR);
	}

	message_combatd(msg, me, target);
	return 1;
}
