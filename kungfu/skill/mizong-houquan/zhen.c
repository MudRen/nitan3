// zhen.c ��ȭ�����־�
// by Lonely

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage;
        string msg, pmsg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("�����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("�������ֲ���ʹ�á����־���\n");         
                
        if( (int)me->query_skill("mizong-houquan", 1) < 40 )
                return notify_fail("��ĺ�ȭ������죬����ʹ�á����־���\n");
                                
        if( (int)me->query("neili", 1) < 200 )
                return notify_fail("����������̫��������ʹ�á����־���\n");
                        
        msg = CYN "$NĬ���񹦣�ʹ����ȭ�����־�����ͼ����������$n��\n"NOR;

        if (random(me->query_skill("force")) > target->query_skill("force") / 2 )
        {       
                damage = (int)me->query_skill("force", 1);
                
                damage = 100 + random(damage/2);
                me->add("neili", -200);
                
                if( damage < 20 ) pmsg = HIY"���$n�ܵ�$N�����������ƺ�һ����\n"NOR;
                else if( damage < 40 ) pmsg = HIY"���$n��$N���������𣬡��١���һ������������\n"NOR;
                else if( damage < 80 ) pmsg = RED"���$n��$N������һ���ؿ������ܵ�һ���ش�����������������\n"NOR;
                else pmsg += HIR"���$n��$N������һ����ǰһ�ڣ��������ɳ�������\n"NOR;
                
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 30, pmsg);
                
                me->start_busy(3);
                if (! target->is_busy())
                        target->start_busy(random(3));
                
        } else 
        {
                me->add("neili", -50);
                me->start_busy(3);
                msg += CYN"����$p������$P����ͼ����û���ϵ���\n"NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}

