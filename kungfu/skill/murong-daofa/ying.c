#include <ansi.h>
inherit F_SSERVER;
int perform(object me,object target)
{
        int j = me->query_skill("murong-daofa", 1);
        object weapon = me->query_temp("weapon");
        
        if (userp(me) && ! me->query("can_perform/murong-daofa/ying"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ����Ӱ�ơ���\n");
        
        if( !target ) target = offensive_target(me);
        j = j * 2 / 3;
        if( !target || !me->is_fighting(target) )
                return notify_fail("��Ӱ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");                
        if( (int)me->query_skill("shenyuan-gong", 1) < 100 )
                return notify_fail("����ڹ���δ���ɣ�����ʹ�õ�Ӱ�ƣ�\n");    
        if( (int)me->query_skill("murong-daofa", 1) < 100 )
                return notify_fail("��ĵ�����δ���ɣ�����ʹ�õ�Ӱ�ƣ�\n");        
        if (!weapon || weapon->query("skill_type") != "blade"
        || me->query_skill_mapped("blade") != "murong-daofa")
                return notify_fail("������û�е����޷�ʹ�õ�Ӱ�ƣ�\n");
        if((int)me->query_skill("xingyi-zhang", 1) < 100 )
                return notify_fail("����Ʒ���δ���ɣ�����ʹ�õ�Ӱ�ƣ�\n");  
        if(me->query_skill_mapped("force") != "shenyuan-gong")
                return notify_fail("����ڹ�������Ԫ�����޷�ʹ�õ�Ӱ�ƣ�\n");      
        if(me->query_skill_mapped("strike") != "xingyi-zhang" ||
           me->query_skill_prepared("strike") != "xingyi-zhang")
                return notify_fail("��û�����ƣ��޷�ʹ�õ�Ӱ�ƣ�\n");
        if(me->query_skill_mapped("parry") != "xingyi-zhang")
                if(me->query_skill_mapped("parry") != "murong-daofa")
                       return notify_fail("����мܹ��򲻶ԣ��޷�ʹ�õ�Ӱ�ƣ�\n");
        if((int)me->query("max_neili") < 1200 )
                return notify_fail("������������Ϊ����������ʹ�õ�Ӱ�ƣ�\n");      
        if((int)me->query("neili") < 600 )
                return notify_fail("�������������㣬����ʹ�õ�Ӱ�ƣ�\n");      
        if((int)me->query_skill("blade", 1) < 100 )
                return notify_fail("��Ļ�������������죬�����ڵ����м���ʹ�õ�Ӱ�ơ�\n");
        if((int)me->query_skill("strike", 1) < 100 )
                return notify_fail("��Ļ����Ʒ�������죬�����ڵ����м���ʹ�õ�Ӱ�ơ�\n");     
        message_combatd(HIR"\n$N���һ��ʹ��Ľ�ݾ�������Ӱ�ơ���ֻ��$P���浶�ߣ�ƬƬ�����м����������Ʒ�һ����$n��\n"NOR, me,target);
        me->add("neili", -200); 
        me->add_temp("apply/attack", j); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),1);
        weapon->unequip(); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),1);
        weapon->wield(); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),1);
        if ((int)me->query_str() > 30)
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),1);
        me->add_temp("apply/attack", -j);
        me->start_busy(2+random(2));
        return 1;
}

