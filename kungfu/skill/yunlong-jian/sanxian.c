#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        int i,lvl;
        
        if( !target ) target = offensive_target(me);

        if( !target
        ||  !target->is_character()
        ||  !me->is_fighting(target) 
        || !living(target))
                return notify_fail("���������֡�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( (int)me->query_skill("yunlong-jian", 1) < 120 )
                return notify_fail("���������������̫ǳ���������ˡ�\n");

        if( (int)me->query_skill("sword", 1) < 120 )
                return notify_fail("��Ļ�����������̫ǳ���������ˡ�\n");
                        
        if( (int)me->query("max_neili") < 1200 )
                return notify_fail("�������̫ǳ���������ˡ�\n");
                
        if( (int)me->query("neili") < 500 )
                return notify_fail("��������������������ˡ�\n");
                
        if( me->query_skill_mapped("force") != "yunlong-shengong" &&
            me->query_skill_mapped("force") != "jiuyang-shengong") 
            
                return notify_fail("����ʲôΪ������ʹ����������ô?\n");
        if( !(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "sword"
            || me->query_skill_mapped("sword") != "yunlong-jian")
                return notify_fail("��ʹ��������������ô?\n");
                
        lvl = ( (int)me->query_skill("yunlong-jian", 1) + (int)me->query_skill("force", 1) ) /8;
        
        me->add("neili", -300);
        message_combatd(HIR "\n$N��Цһ��������һ����" + weapon->name() + HIR"���������죬��������һ�㡣\n"
                "ͻȻ�佣��һ��������ֻ�������ꡱ�������죬 $N����һ˲����$n����������������Ѱ����\n"NOR, 
                me, target);
                
        me->add_temp("apply/dex", lvl); 
        me->add_temp("apply/damage", lvl);
        me->add_temp("apply/str", lvl);
        me->add_temp("apply/attack", lvl); 
        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        
        me->add_temp("apply/damage", -lvl);
        me->add_temp("apply/str", -lvl);
        me->add_temp("apply/dex", -lvl); 
        me->add_temp("apply/attack", -lvl); 
        
        me->start_busy(3);
        return 1;
}


