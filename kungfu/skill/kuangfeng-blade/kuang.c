// kuang.c -������ʮһʽ��
// by Lonely

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        int ap, dp, damage;
        string msg;
        
        if( !target ) target = offensive_target(me);
        if( !target||!target->is_character()||!me->is_fighting(target) )
                return notify_fail("��ֻ�ܶ�ս���еĶ���ʹ�á�����ʮһʽ����\n");
        if( (int)me->query_skill("kuangfeng-blade",1) < 70)
                return notify_fail("��Ŀǰ������ʹ����������ʮһʽ����\n");
        if( (int)me->query("neili") < 200 )
                return notify_fail("�������������\n");

        msg = HIC "$N��ȻһЦ�����Ϳ�ݾ��׵ĵ�����Ȼ��ø���������������һ˲֮�䣬\n"+
              "$N��������ʮһ�����������ŷ磬���ﺬ�ŵ�Ӱ��$nֻ����������ֹͣ�ˣ�\n"NOR;
              
        ap = ap_power(me, "blade");
        dp = dp_power(target, "parry");

        if (ap / 2 + random(ap) > dp) 
        {
                damage = da_power(me, "blade");
                me->add("neili", -100);

                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 50,
                                           RED "ֻ��$n" RED "�ѱ�$N" RED "�е����������Ѫ�������ȫ�����������\n" NOR);
                me->start_busy(random(2));
        }
        else
        {
                msg += HIG "ֻ��$n" HIG "��æ���������$N" HIG "�ı�ɱһ����\n" NOR;
                me->add("neili", -100);
                me->start_busy(2 + random(2));
        }
        message_combatd(msg, me, target);

        return 1;
}


