// yu.c ����Ԧ��
// by Lonely

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        object weapon;
        int damage, ap, dp;
        string msg, pmsg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("����Ԧ������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
                
        if( (int)me->query_skill("yunlong-jian", 1) < 50 )
                return notify_fail("�����������������죬����ʹ�á�����Ԧ������\n");
                                
        if( (int)me->query_skill("yunlong-shengong", 1) < 50 )
                return notify_fail("��������񹦲����ߣ��������������˵С�\n");
                        
        if( (int)me->query("neili", 1) < 500 )
                return notify_fail("����������̫��������ʹ�á�����Ԧ������\n");
                
        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");
        
        msg = HIC "$N΢΢һЦ������һ����,��ʹ������Ԧ����������$n��\n"NOR;
        
        ap = ap_power(me, "sword");
        dp = dp_power(target, "dodge");
        
        if (ap / 2 + random(ap) > dp)
	{
		damage = da_power(me, "sword");
		
                me->add("neili", 400);
                pmsg = HIR"ֻ��$N���н������һ������,�ڿն���,ٿ������$n,\n$nֻ��һ�ɴ�������ǵذ�ѹ��,��ʱ��ǰһ������������,�۵����һ����Ѫ����\n"NOR;
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 50, pmsg);
                me->start_busy(2);
        } else 
        {
                msg += CYN"����$p�͵���ǰһԾ,������$P�Ĺ�����Χ��\n"NOR;
                me->add("neili", -100);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}

