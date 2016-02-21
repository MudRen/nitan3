// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// bafang.c ����˷�
         
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

        if (userp(me) && ! me->query("can_perform/shenzhang-bada/bafang"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ������˷�����\n");
                        
        if (! target) target = offensive_target(me); 
        
        if (! target || ! me->is_fighting(target)) 
                return notify_fail("������˷���ֻ����ս���жԶ���ʹ�á�\n"); 
         
        if (me->query_temp("weapon") || 
            me->query_temp("secondary_weapon")) 
                return notify_fail("�������ֲ���ʹ�á�����˷�����\n"); 
         
        if (me->query_skill("force") < 300) 
                return notify_fail("����ڹ�����Ϊ����������ʹ����һ������\n"); 
        
        if (me->query_skill("shenzhang-bada", 1) < 200) 
                return notify_fail("������ư˴���Ϊ������Ŀǰ����ʹ�á�����˷�����\n"); 
         
        if (me->query("neili") < 700) 
                return notify_fail("��������������޷�ʹ�á�����˷�����\n"); 
         
        if (me->query_skill_mapped("strike") != "shenzhang-bada") 
                return notify_fail("��û�м������ư˴򣬲���ʹ�á�����˷�����\n"); 
         
        msg = HIY "$N" HIY "���������һ���������һ����ȫ�������޷��Թģ�" 
                   HIY "Ȼ����������һ�ݣ��Ӹ����£�˫�Ʒ������£�ɲ�Ǽ䣬�ھ����������"
                   "����$n" + HIY "��\n" NOR; 
         
        ap = ap_power(me, "strike") + me->query("str") * 20;
        dp = dp_power(target, "parry") + target->query("dex") * 20;
        
        if (ap / 2 + random(ap) > dp)
        { 
                damage = da_power(me, "strike");
                me->add("neili", -350); 
         
                msg += COMBAT_D->do_damage(me, target, REMOTE_ATTACK, damage, 70); 
        } else 
        { 
                me->add("neili", -100); 
                me->start_busy(3); 
                msg += CYN "����$p" CYN "������$N" CYN "����ͼ������" 
                       CYN "���Ʈ�����ɣ��������һ������һ����\n"NOR; 
        } 
        message_combatd(msg, me, target); 
         
        return 1; 
}
