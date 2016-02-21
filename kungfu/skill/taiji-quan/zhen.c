// zhen.c ̫��ȭ�����־�

#include <ansi.h>
#include <combat.h>

#define PFM_NAME        "���־�"

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
	int damage;
	string msg;
        int ap, dp;
        string force;

        if (userp(me) && ! me->query("can_perform/taiji-quan/zhen"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ��" PFM_NAME "����\n");
                        
        if(! target) target = offensive_target(me);

        if(! target || ! target->is_character() || ! me->is_fighting()) 
		return notify_fail("��" + PFM_NAME + "��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if(objectp(me->query_temp("weapon")))
		return notify_fail("�������ֲ���ʹ�á�" + PFM_NAME + "����\n");		
		
        if((int)me->query_skill("taiji-quan", 1) < 180)
		return notify_fail("���̫��ȭ������죬����ʹ�á�" + PFM_NAME + "����\n");
	                        
        if((int)me->query_skill("force", 1) < 200)
		return notify_fail("����ڹ������ߣ��������������˵С�\n");
			
        if((int)me->query("neili") < 1000)
		return notify_fail("����������̫������Ҳ���˵��ˡ�\n");
			
        msg = HIY "$N" HIY "Ĭ���񹦣�������ת��˫������������һ��ԲȦ�ѽ�$n"
              HIY "��ס��\n̫��ȭ�еġ�" HIW + PFM_NAME + HIY "������ʹ����һ��"
              HIY "����������$n" HIY "��ȥ��\n" NOR;

        ap = ap_power(me, "cuff") + me->query_skill("force");
        dp = dp_power(target, "parry") + target->query_skill("force");
             
        if (ap * 2 / 3 + random(ap) > dp)
        {
                if (me->query("neili") < target->query("neili"))
                {
                        damage = da_power(me, "cuff");

                        msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 20,
                                                   HIC "\n�ۼ�$P" HIC "��Ҫ��$p�𵹣�ͻȻ��$n"
                                                   HIC "����ȫ��������ǿ����ʹӲ����$Pһ�С�\n" NOR);
                        if (! target->is_busy())
                        target->start_busy(3);
                        me->start_busy(3);
                        target->add("neili", -(target->query("neili") / 2));
                        me->add("neili", -(me->query("neili") / (2 + random (2))));
                }
                else
                {
                        damage = (ap - (dp / 3 + random(3))) * 2;
                        damage = damage / 2 + random(damage / 2);
                        if (damage < 0) damage = 5 + random(30);

                        msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 50,
                                                   HIC "\n�ۼ�$n" HIC "��$P������ѹ��͸����������ֻ����$N"
                                                   HIC "���顱��һ������$n" HIC "��$pȫ���������ɢ��"
                                                   HIC "��һ�㵹����ȥ��\n" NOR);
                        me->start_busy(3);
                        target->start_busy(1);
                        me->add("neili", -(me->query("neili") / (2 + random (3))));
                }
        }
        else
        {
                msg += HIG "\n��$p�����ֱ��$P���ȫ�����������ܿ����ŵ�$P�����޴룡\n" NOR;
                me->add("neili", -100);
                me->start_busy(3);
        }
        message_combatd(msg, me, target, 0, 1);
	return 1;
}
