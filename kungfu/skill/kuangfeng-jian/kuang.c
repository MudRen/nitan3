// Updated by Lonely

#include <ansi.h>
#include <combat.h> 
inherit F_SSERVER; 
#include <balance.h>


int perform(object me, object target) 
{ 
        string msg; 
        int extra, damage, ap, dp; 
        object weapon; 

        if (userp(me) && ! me->query("can_perform/kuangfeng-jian/kuang"))
                return notify_fail("�㻹û������������о������޷�ʩչ��\n");
                        
        if (! target) target = offensive_target(me); 
        if (! target 
        ||  ! target->is_character() 
        ||  ! me->is_fighting(target)) 
                return notify_fail("�����������ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 

        if (! weapon = me->query_temp("weapon")) 
                return notify_fail("��ûװ������ô��\n"); 
                
        if ((string)weapon->query("skill_type") != "sword") 
                return notify_fail("��ʹ�õı������ԣ�\n"); 
                
        if ((int)me->query_skill("kuangfeng-jian", 1) < 100) 
                return notify_fail("��Ŀ��콣����������ʹ���� [ ������� ] ��\n"); 

        if ((int)me->query("neili") < 300)
                return notify_fail("�������������\n");

        if ((int)me->query_skill("sword", 1) < 100) 
                return notify_fail("��Ľ���������죬ʹ���� [ ������� ] �ľ��У�\n"); 

        extra = me->query_skill("kuangfeng-jian", 1); 

        msg = HIY "$N" HIY "��бб�̳�������ɹɽ������ν����ս�������һ˲�䣬��ر�ã���Ӱ��������С��\n"
              "�����������ŷ磬���ﺬ�Ž�Ӱ���ǽ����������������ɫ��������ǵ�Ϯ��$n��\n" NOR;

        ap = ap_power(me, "sword");
        dp = dp_power(target, "dodge");

        if (ap / 2 + random(ap) > dp) 
        {        
                damage = da_power(me, "sword");
                me->add("neili", -200); 
                
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 60,
                                           HIR "$n" HIR "ֻ�������к��һ�£�"
                                           "�������󵹷ɳ�ȥ�������ڵأ��������ۡ�������һ����Ѫ���\n" NOR); 
                me->start_busy(2);
        } else
        {
                me->add("neili", -100);
                msg += CYN "����$p" CYN "������$P" CYN "�ĺݶ���ͼ�����������������㿪��$P" CYN "����һ�����µĹ�����\n" NOR;
                me->start_busy(3);  
        }          
        message_combatd(msg, me, target);
        return 1;
}
