// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// mang.c ��â


#include <ansi.h>
#include <combat.h>     
#include <weapon.h>
inherit F_SSERVER;

string *name1 = ({
        "����Ѩ",
        "���Ѩ",
        "����Ѩ",
        "����Ѩ",
        "����Ѩ",
        "�Ϲ�Ѩ",
        "���Ѩ",
        "�ٻ�Ѩ",
        "̫��Ѩ",
        "��ǿѨ",
        "��̨Ѩ"
});

void check_fight(object me, object target, int amount);

int perform(object me, object target)
{       
        string msg, name, name2;
        int ap, dp;
        object weapon = me->query_temp("weapon");
        
        if (! target) target = offensive_target(me);
 
        if (! target || ! target->is_fighting(me))
                return notify_fail("����â��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (userp(me) && ! me->query("can_perform/huashan-jianfa/mang"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ����â����\n");
                
        if (target->query("qi") <= 50)
                return notify_fail("������û�б�Ҫ�á���â�����������ˡ�\n");

        if (! weapon || weapon->query("skill_type") != "sword"
        ||  me->query_skill_mapped("sword") != "huashan-jianfa")
                return notify_fail("�������޷�ʹ�á���â���������ˡ�\n");

        if (me->query_temp("perform") == 1  ||
            me->query_temp("perform2") == 1 ||
            me->query_temp("perform3") == 1)
                return notify_fail("�����������š���â���ء�\n");

        if ((int)me->query_skill("huashan-jianfa", 1) < 100 ||
            (int)me->query_skill("sword", 1) < 100 ||
            (int)me->query_str() < 25   ||
            (int)me->query_dex() < 25)  
                return notify_fail("���еĹ��򻹲�����죬����ʹ�á���â����\n");

        if ((int)me->query_skill("zixia-shengong", 1) < 80)
                return notify_fail("�����ϼ����Ϊ�������޷����򡸽�â���ľ��衣\n");


        if ((int)me->query("max_neili") < 800)
                return notify_fail("�������̫�����޷�ʹ�ó�����â����\n");
        
        if ((int)me->query("neili") < 200)
                return notify_fail("�������������\n");
                
        name = name1[random(sizeof(name1))];    
        name2 = weapon->query("name");
        
        msg = HIC "\n$N���ֽ���һת������" + name2 + HIC "ֱ������ʱʹ$N" +
              HIC "��һƬ���������֣�����һ֧��â����$n " HIC "��" + name + "��\n" NOR;
        
        ap = me->query_skill("sword") + me->query("level") * 20 + 
             me->query_skill("martial-cognize", 1);
        dp = target->query_skill("dodge") + target->query("level") * 20 + 
             target->query_skill("martial-cognize", 1);
                   
        if (ap / 2 + random(ap) > dp)
        {                
                msg += HIR "���һ�����У�$nֻ����ȫ������ͨ���������������ܸ��ӣ�\n"NOR;   
                if (! target->is_busy())
                target->start_busy(2 + random(4));
                me->add("neili", -200);
                me->set_temp("perform", 1);
                
                if ((int)me->query_skill("huashan-jianfa", 1) > 120
                &&  (int)me->query("neili", 1) > 300) 
                {
                        call_out("perform2", 0, me , target);    
                } else 
                {
                        me->delete_temp("perform");
                }
        } else 
        {
                me->start_busy(2);
                me->add("neili", -100);
                target->add("neili", -100);
                msg += HIY"\n$p���һ�����ã�ȫ������һ�ݣ�˳�����˿�ȥ��\n" NOR;
        }
        message_combatd(msg, me, target);
        me->start_call_out((: call_other, __FILE__, "check_fight", 
                           me ,target :), 1);
        return 1;
}

int perform2(object me, object target)
{
        string msg, name, name2;
        int damage, ap, dp;  
        object weapon = me->query_temp("weapon");
       
        if (! weapon)
        {
                me->start_call_out((: call_other, __FILE__, "check_fight", 
                                   me ,target :), 1);
                return 1;
        }
        name2 = weapon->query("name");
        
        if (! target) target = offensive_target(me);
        if (! target) 
        {
                call_out("back", 3, me);
                return 1;
        }
        
        name = name1[random(sizeof(name1))];
        msg = MAG "\n����$N̤ǰһ����" + name2 + "�����ĵڶ�֧��â���յ���$n��" + name + "����Ѩ�������֮�\n" NOR;  
              
        ap = me->query_skill("sword") + me->query("level") * 20 + 
             me->query_skill("martial-cognize", 1);
        dp = target->query_skill("parry", 1) + target->query("level") * 20 + 
             target->query_skill("martial-cognize", 1);
                   
        if (ap / 2 + random(ap) > dp)
        {
                me->delete_temp("perform");
                damage = 200 + random(me->query_skill("huashan-jianfa", 1) / 2);

                me->add("neili", -300);
                
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 40,
                                           HIR "���ֻ����$n" HIR "һ���Һ���" + name2 + HIR "����$p��" + name + 
                                           HIR "�Դ���������Ѫ�������أ���\n" NOR);
                                
                target->start_busy(2);
                                                           
                if ((int)me->query_skill("huashan-jianfa", 1) > 140
                &&  (int)me->query("neili", 1) > 300) 
                {
                        call_out("perform3", 0, me ,target);    
                } else 
                {
                        me->delete_temp("perform2"); 
                }
        } else 
        {       me->start_busy(3);
                me->add("neili", -100);                
                me->delete_temp("perform");
                msg += HIY"����$pһ�����Ʒ���ԶԶ�Ķ��˿�ȥ��\n"NOR;
        }
        message_combatd(msg, me, target);
        me->start_call_out( (: call_other, __FILE__, "check_fight", me ,target :), 1);
        return 1;
}

int perform3(object me, object target)
{
        int skill, j, ap, dp;
        string msg, name, name2;
        object weapon;
        
        if (! me || ! weapon = me->query_temp("weapon"))
        {
                me->start_call_out( (: call_other, __FILE__, "check_fight", me ,target :), 1);
                return 1;
        }
        name2 = weapon->query("name");
        skill = (int)me->query_skill("huashan-jianfa", 1);                
        skill = skill / 15;

        if (! target) target = offensive_target(me);
        if (! target) 
        {
                call_out("back", 3, me);
                return 1;
        }
        
        name = name1[random(sizeof(name1))];
        msg = HIW "\n������$N����" + name2 + "��������֧��â��ֻ��һ����âֱ��$n������ɨ��$n��" + name + "��\n" NOR;     
           
        ap = me->query_skill("sword") + me->query("level") * 20 + 
             me->query_skill("martial-cognize", 1);
        dp = target->query_skill("force", 1) + target->query("level") * 20 + 
             target->query_skill("martial-cognize", 1);
                   
        if (ap / 2 + random(ap) > dp)
        {                
                me->add("neili", -200);
                me->delete_temp("perform2");
                
                msg += HIR "$nֻ�������澭��������ϢΪ֮һ����ȫ��������Ȼ�᲻�����ˣ�\n" NOR;
                msg += HIW "$N��$n����һ���ĵ��������������������������ǽ��ھ���" + HIR "���������ɽ�����\n" NOR;
                message_combatd(msg, me, target);
                me->add("apply/str", skill);
                me->add("apply/con", skill);
                
                for (j = 0; j < (3 + (int)me->query("str") / 10); j++)
                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);

                me->add("apply/str", -skill);
                me->add("apply/con", -skill);
                                        
                target->start_busy(4);
                me->start_busy(3);
                target->add("neili", -500);                 
                call_out("back", 3 + skill, me);
                                
        } else 
        {
                me->start_busy(3);
                me->add("neili", -100);
                me->delete_temp("perform2");
                target->start_busy(1);
                msg += HIY"\n$p��Ϣδ������$P���з����Ľ�â������������æ��Ծ�����ߣ��Ǳ��رܿ���\n" NOR;
                message_combatd(msg, me, target);
        }
        me->start_call_out( (: call_other, __FILE__, "check_fight", me ,target :), 1);
        return 1;
}

void back(object me)
{
        string msg;
        if (! me) return;
        msg = HIW "\n������һ�գ����н�â������ʧ��\n" NOR;
        tell_object(me, msg);
        me->delete_temp("perform");
        me->delete_temp("perform2");
        me->delete_temp("perform3");
}

void check_fight(object me, object target, int amount)
{
        object weapon, where;
        if ( target )
        {
                where = environment(target);
                if ( !present(target,where) ) 
                {
                        if( target->query("qi") <= 50 && me->is_fighting(target)) 
                        {
                                me->delete_temp("perform");
                                me->delete_temp("perform2");
                                remove_call_out("perform2");
                                remove_call_out("perform3");
                        }
                        else 
                        if( !objectp(weapon = me->query_temp("weapon"))
                        || (string)weapon->query("skill_type") != "sword" 
                        || me->query_skill_mapped("sword") != "huashan-jianfa") 
                        {
                                remove_call_out("perform2");
                                remove_call_out("perform3");
                                me->delete_temp("perform");
                                me->delete_temp("perform2");
                        }
                        else 
                        if( !present(target->query("id"), environment(me)) 
                        || !target->is_fighting() || !me->is_fighting() || !living(target)
                        || !living(me) || target->is_ghost() || me->is_ghost() ) 
                        {
                                me->delete_temp("perform");
                                me->delete_temp("perform2");
                                remove_call_out("perform2");
                                remove_call_out("perform3");
                        }
                        else call_out("check_fight", 1, me, target, amount); 
                } else 
                {
                        me->delete_temp("perform");
                        me->delete_temp("perform2");
                        me->delete_temp("perform3");
                } 
        }

}


