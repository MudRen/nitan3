// Updated by Lonely

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        string msg, pmsg;
        int damage, ap, dp;
        
        if (! target) target = offensive_target(me);

        if (! target
        ||      ! target->is_character()
        ||      ! me->is_fighting(target))
                return notify_fail("ǣ�ƹ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if ((int)me->query_str() < 30)
                return notify_fail("���������,����ʹ����һ����!\n");

        if ((int)me->query_skill("yinyun-ziqi", 1) < 100)
                return notify_fail("���������Ĺ�����������ʹ��������������!\n");

        if ((int)me->query("neili") < 800)
                return notify_fail("���������ڲ���, ����ʹ����������! \n");

        msg = HIY "$N��Хһ����" + YEL "�������𡢱����������������£�Ī�Ҳ��ӡ����첻����˭�����棿\n" + 
              HIY "������������������������������������ڣ����������������������ʮ����һ��д�ϡ�\n"NOR;

        ap = me->query_skill("yitian-tulong", 1) * 3 / 2 + me->query("level") * 20 +  
             me->query_skill("martial-cognize", 1); 

        dp = target->query_skill("force") + target->query("level") * 20 +
             target->query_skill("martial-cognize", 1); 

        if (ap / 2 + random(ap) > dp) 
        {
                damage = (int)me->query_skill("yitian-tulong", 1);
                
                damage = damage/2 + random(damage/2);
        
                me->add("neili", -500);
                
                if (damage < 20)
                        pmsg = HIY"���$n�ܵ�$N�����������ƺ�һ����\n"NOR;
                else if (damage < 40)
                        pmsg = HIY"���$n��$N���������𣬡��١���һ������������\n"NOR;
                else if (damage < 80)
                        pmsg = RED"���$n��$N������һ���ؿ������ܵ�һ���ش�����������������\n"NOR;
                else
                        pmsg = HIR"���$n��$N������һ����ǰһ�ڣ���һ������һ���ɳ�ȥ�ü���Զ��\n"NOR;
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 35, pmsg);
                        
                me->start_busy(1);
                target->start_busy(random(3));          
                
        }
        else 
        {
                me->start_busy(2);
                me->add("neili", -200);
                msg += CYN"����$p������$P����ͼ����û���ϵ�������һ����㿪�ˡ�\n"NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}

