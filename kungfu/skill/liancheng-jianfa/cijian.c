// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h> 
#include <combat.h>

inherit F_SSERVER;
#include <balance.h>

#include "/kungfu/skill/eff_msg.h"; 

string *limbs = ({ 
        "ͷ��", "����", "�ؿ�", "����", "���", "�Ҽ�", "���", 
        "�ұ�", "����", "����", "����", "С��", "����", "����", 
        "���", "�ҽ�", "���", "�Ҷ�", "����", "����", 
}); 

void remove_effect(object target);
string *songs = ({"HIC", "HIR", "HIW", "HIY"});
        
int perform(object me, object target) 
{ 

        int damage, p, ap, dp; 
        object weapon; 
        string msg, song, dodge_skill; 

        if (userp(me) && ! me->query("can_perform/liancheng-jianfa/cijian"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ��"HIM"�̼�ʽ"NOR"����\n");
                
        song = songs[random(sizeof(songs))];

        if( !target ) target = offensive_target(me); 

        weapon = me->query_temp("weapon"); 
        if( !target ) 
                target = offensive_target(me); 

        if( !target || !me->is_fighting(target) ) 
                return notify_fail("��"HIM"�̼�ʽ"NOR"��ֻ����ս���жԶ���ʹ�á�\n"); 

        if (!weapon 
                || weapon->query("skill_type") != "sword" 
                || me->query_skill_mapped("sword") != "liancheng-jianfa") 
                return notify_fail("������û�н����޷�ʹ�á�"HIM"�̼�ʽ"NOR"����\n"); 
                
        if( (int)me->query_skill("liancheng-jianfa",1) < 150 ) 
                return notify_fail("������ǽ���������죬����ʹ�á�"HIM"�̼�ʽ"NOR"����\n"); 

        if( (int)me->query_skill("sword",1) < 150 ) 
                return notify_fail("��Ļ��������ȼ�����������ʹ�á�"HIM"�̼�ʽ"NOR"����\n"); 

        if( (int)me->query_skill("force", 1) < 150 ) 
                return notify_fail("����ڹ��ȼ�����������ʹ�á�"HIM"�̼�ʽ"NOR"����\n"); 

        if( (int)me->query("max_neili") < 1500 ) 
                return notify_fail("�������̫��������ʹ�á�"HIM"�̼�ʽ"NOR"����\n"); 

        if( (int)me->query("neili") < 700 ) 
                return notify_fail("�������̫���ˣ��޷�ʹ�ó���\n"); 
                
        msg = WHT "\n$N����һ�Σ�����"+weapon->name()+WHT"�����缲�������һ���͹���$n���ü��У������ع���\n"
              "$NͻȻ��"+weapon->name()+WHT"������߲��һ�����죬�Ӳ���˼��ĽǶȴ�����$n�ļ�ͷ\n"NOR;
              
        msg = replace_string( msg, "song", songs[random(sizeof(songs))] ); 
        
        ap = ap_power(me, "sword");
        dp = dp_power(target, "dodge");
                
        if (ap / 2 + random(ap) > dp) 
        { 
                me->start_busy(1); 
                me->add("neili", -140); 
 
                damage = da_power(me, "sword");
                
                if (target->is_busy()) damage = damage * 2;
                         
                if (target->query("shen") < 0)  damage = damage*3/2; 
                
                if (me->query("neili") > target->query("neili")*2 ) 
                        damage += random(damage); 
                        
                target->receive_damage("qi", damage/2); 
                target->receive_wound("qi", damage/4); 
                p = (int)target->query("qi")*100/(int)target->query("max_qi"); 
                msg += COMBAT_D->damage_msg(damage, "����"); 
                msg += "( $n"+eff_status_msg(p)+" )\n"; 
                msg = replace_string( msg, "$w", weapon->query("name") ); 
                msg = replace_string( msg, "$l", limbs[random(sizeof(limbs))] ); 
        } 

        message_combatd(msg, me, target); 
 
        msg = HIB "\n$n�ὣ��·����$N"+weapon->name()+HIB"ͣ�Ͳ�ǰ�������񽣷��̡���֪$n����ֻһ���䣬"
              "$N��"+weapon->name()+HIB"�綾�߱�����ǰһ̽���ѵ�����$n��ͷ����\n"NOR; 

        ap = ap_power(me, "sword");
        dp = dp_power(target, "parry");
                
        if (ap / 2 + random(ap) > dp
                || target->is_busy()) 
        { 
                me->start_busy(1); 
                me->add("neili", -150); 
                damage = da_power(me, "sword");
                if(target->is_busy())damage=damage*2; 
                if(target->query("shen")<0)damage=damage*3/2; 
                if(me->query("neili") > target->query("neili")*2 ) 
                        damage += random(damage); 
                target->receive_damage("qi", damage/2); 
                target->receive_wound("qi", damage/4); 
                p = (int)target->query("qi")*100/(int)target->query("max_qi"); 
                msg += COMBAT_D->damage_msg(damage, "����"); 
                msg += "( $n"+eff_status_msg(p)+" )\n"; 
                msg = replace_string( msg, "$w", weapon->query("name") ); 
                msg = replace_string( msg, "$l", limbs[random(sizeof(limbs))] ); 
        } 
        message_combatd(msg, me, target); 
        
        msg = YEL "\n$N"+weapon->name()+YEL"��һ�̣���һ����ÿһ�������ޱȹ���ķ�λ�̳���"
              "����$n�ļ粿��$nֻҪһ�����๥����ʱ��ɺ�����������$n�ļ�ͷ��\n"NOR; 
              
        ap = ap_power(me, "sword");
        dp = dp_power(target, "force");
                
        if (ap / 2 + random(ap) > dp
                ||target->is_busy()) 
        { 
                me->add("neili", -160); 
        
                damage = da_power(me, "sword");
                
                if(target->is_busy())damage=damage*2; 
                if(target->query("shen")<0)damage=damage*3/2; 

                if(me->query("neili") > target->query("neili")*2 ) 
                        damage += random(damage); 
                target->receive_damage("qi", damage/3); 
                target->receive_wound("qi", damage/6); 
                p = (int)target->query("qi")*100/(int)target->query("max_qi"); 
                msg += COMBAT_D->damage_msg(damage, "����"); 
                msg += "( $n"+eff_status_msg(p)+" )\n"; 
                msg = replace_string( msg, "$w", weapon->query("name") ); 
                msg = replace_string( msg, "$l", limbs[random(sizeof(limbs))] ); 
        } 
        message_combatd(msg, me, target); 

        return 1; 
} 
