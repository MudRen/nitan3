// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// jumie.c  ���ֶ���Ҷָ���������
         
#include <ansi.h>
#include <combat.h>
         
inherit F_SSERVER; 
#include <balance.h>
         
int perform(object me, object target) 
{ 
        object weapon; 
        string msg; 
        int ap, dp; 
        int damage; 

        if (userp(me) && ! me->query("can_perform/duoluoye-zhi/jimie"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ��������𡹡�\n");
                                
        if (! target) target = offensive_target(me); 
        
        if (! target || ! me->is_fighting(target)) 
                return notify_fail("���������ֻ����ս���жԶ���ʹ�á�\n"); 
         
        if (me->query_temp("weapon") || 
            me->query_temp("secondary_weapon")) 
                return notify_fail("�������ֲ���ʹ�á�������𡹣�\n"); 
         
        if (me->query_skill("force") < 200) 
                return notify_fail("����ڹ�����Ϊ����������ʹ����һ������\n"); 
        
        if (me->query_skill("duoluoye-zhi", 1) < 180) 
                return notify_fail("��Ķ���Ҷָ��Ϊ������Ŀǰ����ʹ�á�������𡹣�\n");
         
        if (me->query("neili") < 800 || me->query("max_neili") < 2500) 
                return notify_fail("��������������޷�ʹ�á�������𡹣�\n"); 
         
        if (me->query_skill_mapped("finger") != "duoluoye-zhi") 
                return notify_fail("��û�м�������Ҷָ������ʹ�á�������𡹣�\n"); 
         
        msg = HIB "$N" HIB "����ȫ������ֱ����$n" + HIB "��˫��һȦ����һ���ھ�" +
              "��ס$n��" + HIB "�漴ȫ��һָ��������ϧ�ķѴ�����Ԫ������һ���еУ�\n" NOR;
         
        ap = ap_power(me, "finger") + me->query_skill("force", 1);
        dp = dp_power(target, "dodge") + target->query_skill("force", 1);
             
        damage = da_power(me, "finger");
         
        if (ap / 2 + random(ap) > dp)
        {
                me->add("neili", -500);
                
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 70,
                                           HIR "ֻ��$p" HIR "һ���Һţ��ѱ�$P" +
                                           HIR "һָ���У�һ�ɰԵ���������$P" + 
                                           HIR "��ָ�⴫�����˼�������\n" NOR);
                me->start_busy(2); 
        } else 
        { 
                me->add("neili", -200);
                me->start_busy(3);
                msg += CYN "����$p" CYN "������񣬼�ʱ������" 
                       CYN "$P" CYN "������ǣ�����㿪����һ����\n" NOR; 
        }
        
        msg += HIR "��$P" + HIR "���������������ȣ��������ɲ�" +
               "�ˣ����˲�������ˣ�\n" NOR;

        me->receive_damage("qi", damage / 4);

        message_combatd(msg, me, target);
       
        return 1; 
}
