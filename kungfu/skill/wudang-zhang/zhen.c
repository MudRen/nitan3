// Updated by Lonely

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        int damage, ap, dp;
        string msg;
    
        if (! target) target = offensive_target(me);

/*
        if (userp(me) && ! me->query("can_perform/wudang-zhang/zhen")) 
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ�����־���\n"); 
*/
        
        if (! target || ! target->is_character() || 
            ! me->is_fighting(target))
                return notify_fail("���־�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
                
        if ((int)me->query_skill("wudang-zhang", 1) < 100)
                return notify_fail("����䵱���Ʋ�����죬����ʹ�á����־���\n");
        
        if (me->query("neili") < 500)
                return notify_fail("�������������\n");
                
        msg = HIB "$N���˵��ʹ���������־���˫�Ʒ��������Ʒ磬����$n��\n" NOR;
        
        ap = ap_power(me, "strike");
        dp = dp_power(target, "force");

        if (ap / 2 + random(ap) > dp) 
        {
                damage = da_power(me, "strike");
                me->add("neili", - 400);
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 50,
                        HIR "$n ãȻ��֪���룬�����$Nһ�ƻ���ǰ�أ�$n��ǰһ�ڣ������ɳ�����������\n" NOR);
                me->start_busy(2);
        } else
        {
                me->add("neili", 200);
                me->start_busy(3);
                msg += HIG "����$p������$P����ͼ�����������һ�ߡ�\n" NOR;
        }
        
        message_combatd(msg, me, target);
        return 1;
}


