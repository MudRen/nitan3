// jinglei ��ָ����
// by Lonely

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        int level, ap, dp, damage;
        string msg, pmsg;
        object weapon, weapon2;

        level   = (int) me->query_skill("tanzhi-shentong",1);

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��ָ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
                
        if ( objectp(weapon = me->query_temp("weapon")))
                return notify_fail("��ʹ����������\n");

/*
        if( me->query_skill_mapped("force") != "bibo-shengong")
                return notify_fail("�����õ��ڹ��롸��ָ���ס��ķ���㣣�\n");
*/

        if( me->query_skill("bibo-shengong", 1) < 120 )
                return notify_fail("����ڹ���Ϊ���δ������δ���򡸵�ָ���ס���\n");

        if( me->query_skill("finger", 1) < 120 )
                return notify_fail("�����ָ����Ϊ����������δ���򡸵�ָ���ס���\n");

        if( me->query_skill("tanzhi-shentong", 1) < 120 )
                return notify_fail("�㵯ָ��ͨ��Ϊ����������δ���򡸵�ָ���ס���\n");
        
        if( me->query("neili") <= 600 )
                return notify_fail("�����������������������ʩչ��ָ���ף�\n");
        
        msg = HIC "$Nʹ����ָ��֮ͨ����ָ���ס�, ��ʱ���ھ��Ⱪ�䣬\n" NOR;

        ap = ap_power(me,"finger");
        dp = dp_power(target,"dodge");
        
        if (ap / 2 + random(ap) > dp) 
        {
                damage = da_power(me, "finger");
                me->add("neili", -200);
                
                pmsg = HIR "$nֻ������ǰһ��������Ѩ��΢΢һʹ��ȫ��������й������\n" NOR;
                if( objectp(weapon2 = target->query_temp("weapon")) && 
                    me->query("level") > target->query("level") )
                {
                        pmsg += HIR "ͬʱ����һ�飬����";
                        pmsg += weapon2->name();
                        pmsg += HIR "���ֶ�����\n" NOR;
                        weapon2->move(environment(me));
                }

                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 50, pmsg);

                if ((int)target->query("neili") < damage)
                        damage = target->query("neili");
                target->add("neili", -damage);
                
                if (! target->is_busy()) 
                        target->start_busy(2);
                me->start_busy(2);
        } else 
        {
                me->add("neili", -100); 
                msg += "����$n�Ŀ�����$N����ͼ�����̲�ȡ���ƣ�ʹ$P�ġ���ָ���ס�û�������á�\n"NOR;
                me->start_busy(3);      
        }

        message_combatd(msg, me, target);
        
        return 1;
}

