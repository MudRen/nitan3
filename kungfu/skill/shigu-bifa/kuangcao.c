// ding.c ȫ�潣-������

#include <ansi.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
int perform(object me, object target)
{
        object weapon;
        int damage,time;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "dagger")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if( (int)me->query_skill("shigu-bifa", 1) < 140 )
                return notify_fail("���ʯ�Ĵ�Ѩ�ʷ�������죬����ʹ�ÿ�ݡ�\n");

        if( (int)me->query_skill("wuzheng-xinfa", 1) < 140 )
                     return notify_fail("��ı����ڹ�������죬����ʹ�ÿ�ݡ�\n");

        if( (int)me->query("neili", 1) < 950 )
                return notify_fail("����������̫��������ʹ�ÿ�ݡ�\n");
        
       
        msg = HIM "$Nʹ�����Ὣ��ʫ���ʷ�����������������Ὣ������������ϣ��ͽ������ս���������������׳�գ�����\n"NOR;

        //if( !target->is_killing(me) ) target->kill_ob(me);

        if (random(me->query_skill("dagger")) > target->query_skill("dodge")/3 )
        {
                me->start_busy(1);

                damage = (int)me->query_skill("dagger", 1) + (int)me->query_skill("force",1);
                //(ȫ�潣������+�����ڹ�)

                damage = damage/2 + random(damage/2);

                target->receive_damage("qi", damage);
                target->start_busy(4);
                me->add("neili", -100);
               time=8-((int)me->query_skill("shigu-bifa",1)/40);
              if(me->query_skill("shigu-bifa", 1) > 160)
                call_out("perform2", time+3, me, target);    

                msg += HIR"$n��֪$Nд����ʲô�������˸����ֲ�����\n"NOR;me->start_perform( 8+random(3), "����ݡ�");

        }
        else
        {
                me->start_busy(3);
                msg += BGRN"$N��·���ÿһ��ֻʹ������,���̱�$n��ס��\n"NOR;
        }
        message_vision(msg, me, target);
        me->start_perform(5,"����ݡ�");
        return 1;
}
int perform2(object me, object target)
{
 object weapon, ob;
        string msg, string1;
        int count,time;
        
    weapon = me->query_temp("weapon");  
              
        if(!living(target)) 
          return notify_fail("�����Ѿ�������ս���ˡ�\n");

        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("���Ҫ�ٳ��ڶ�����ȴ�����Լ������������ˣ�\n");     

        if(!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "dagger")
    return notify_fail("������û��ʹ�����޷���һ��������\n");
             msg = HIY+BRED "$N���һ�����ʷ��Ǳ䣬�������ʲ���ô������������Ǿ����з棬�������أ�����â�ǳ����������ţ��������䲨����̬��\n" NOR;
        
        message_vision(msg, me,target);
        me->clean_up_enemy();
        ob = me->select_opponent();   
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);  COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        me->add("neili", -100);
    time= 1+((int)me->query_skill("dagger",1)/50);
        if(me->query_skill("shigu-bifa", 1) > 180)
               call_out("perform3", time, me, target);    me->start_perform(5,"����ݡ�");  
        return 1;
}

int perform3(object me, object target)
{
 object weapon, ob;
        string msg, string1;
        int count,time,i,damage;
        
    weapon = me->query_temp("weapon");  
              
        if(!living(target)) 
          return notify_fail("�����Ѿ�������ս���ˡ�\n");

        if( (int)me->query("neili", 1) < 400 )
                return notify_fail("���Ҫ�ٳ���������ȴ�����Լ������������ˣ�\n");     

        if(!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "dagger")
    return notify_fail("������û��ʹ�����޷���һ��������\n");
        me->add("neili", -300);
        me->add("jingli", -100);
        message_vision(HBBLU "\n$N�ʷ��ֱ䣬���顶�������������еĲ��飬�ݺ�Ʈ������ת�޷������мӲ�,�������棬�����ۻ����ң�\n" NOR,me, target);

        me->add_temp("apply/damage", 50);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);
        me->start_busy(1+random(3));
        me->add_temp("apply/damage", -50);
        me->set_temp("mr_sanhua", 1); 
        i = (int)me->query_skill("dagger")/30;
        if( 15 - i <= 4) i = 4;
        call_out("remove_effect", i, me);
         me->start_perform(5,"����ݡ�");
        
        return 1;
}
