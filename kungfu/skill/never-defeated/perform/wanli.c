// wanli.c �������

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        object  weapon;
	int     damage;
	string  msg;
        string  pmsg;
        string *limbs;
        string  limb;
        int ap, dp;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if ((int)me->query_skill("never-defeated", 1) < 120)
		return notify_fail("��Ĳ����񹦻�������죬����ʹ��������\n");
	                        
        if ((int)me->query("neili", 1) < 200)
		return notify_fail("����������̫��������ʹ��������\n");
			
        if (! objectp(weapon = me->query_temp("weapon")))
                return notify_fail("������ֱֳ��в���ʩչ������\n");
                
        if (me->query_skill_mapped("sword") != "never-defeated") 
                return notify_fail("������û�м���������Ϊ����������ʩչ������\n"); 
                
        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIC "$N" HIC "����" + weapon->name() + HIC "��һ"
              "ȦȦ�Ļ���$n" HIC "����$p" HIC "���ڵ��У�\n" NOR;
	me->add("neili", -20);

        ap = ap_power(me, "sword");
        dp = dp_power(target, "parry");

        if (ap * 11 / 20 + random(ap * 2) > dp)
        {
		me->start_busy(2);
                me->add("neili", -180);

		damage = da_power(me, "sword");

                if (arrayp(limbs = target->query("limbs")))
                        limb = limbs[random(sizeof(limbs))];
                else
                        limb = "Ҫ��";
                pmsg = HIR "$n��æ��Ų������Ȼ�������ꡱһ����" + weapon->name() +
		       HIR "���û���$p" HIR "��" + limb + "��$p"
		       HIR "һ���ҽУ�����������\n" NOR;
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 50, pmsg);
	} else 
	{
		me->start_busy(2);
		msg += CYN "����$p" CYN "������$P"
                       CYN "�ı仯�����в��У�û���ܵ��κ��˺���\n"NOR;
	}

	message_combatd(msg, me, target);

	return 1;
}
