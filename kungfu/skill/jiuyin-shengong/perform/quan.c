// quan ������ȭ
 
#include <ansi.h>
#include <combat.h>
 
inherit F_SSERVER;
#include <balance.h>

#define QUAN "��" HIW "������ȭ" NOR "��"
 
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
		return notify_fail(QUAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (me->query_skill("jiuyin-shengong", 1) < 230)
		return notify_fail("��ľ����񹦻�������죬����ʹ��" QUAN "��\n");

	if (me->query_skill("cuff", 1) < 220)
		return notify_fail("��Ļ���ȭ����������죬����ʹ��" QUAN "��\n");

        if (me->query("neili") < 240)
                return notify_fail("�����������������ʹ��" QUAN "��\n");

        if (me->query_temp("weapon"))
                return notify_fail("����ֻ�ܿ���ʩչ��\n");

        if (me->query_skill_prepared("unarmed") != "jiuyin-shengong")
                return notify_fail("��û��׼��ʹ�þ����񹦣��޷�ʩչ" QUAN "��\n");
 
       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIC "$N" HIC "һ����ߣ���ȭ��������ʽ�ۻ룬��ߪ������\n" NOR;
 
	ap = ap_power(me, "unarmed") + me->query("str") * 20;
	dp = dp_power(target, "dodge") + target->query("dex") * 20;

        me->start_busy(2);
        me->add("neili", -50);
        if (ap / 2 + random(ap) < dp)
        {
		msg += HIG "ֻ��$n" HIG "���Ų�æ������һ���������$N" HIG "��һ����\n"NOR;
        } else
	{
		me->add("neili",-90);
                damage = da_power(me, "unarmed");
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 85 + random(5),
                                           HIR "$n" HIR "��æ�񵲣�������һȭ�����ε�֮�أ������"
                                           "����ס��ֻ�������Ѫ���ߣ�����������\n" NOR);
	}

	message_combatd(msg, me, target);
	return 1;
}
