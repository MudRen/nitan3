// Code by JHSH
     
#include <ansi.h>
inherit F_DBASE;
inherit F_SSERVER; 
       
int perform(object me, object target) 
{ 
        object weapon; 
        int myexp, targexp, damage, skill, merand, targrand, targneili,time,i; 
        string str,*limb,type; 
        mapping myfam; 
        int tmp_jiali,dmg;
        int num,ap,dp;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��ŭ�����Ρ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if ( (!( myfam= me->query("family")) || myfam["family_name"] != "��Ĺ��") )
                  return notify_fail("ֻ�й�Ĺ���Ӳ����á�ŭ�����Ρ���\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("���ֲ���ʩչ��ŭ�����Ρ���\n");

        if( me->query_skill_mapped("force") != "surge-force" )
                return notify_fail("�������ڹ��Ĳ���ŭ�����Σ�ʹ������ŭ�����Ρ���\n");

        if( (int)me->query_skill("surge-force",1) < 150 )
                return notify_fail("���ڹ���Ϊ̫��������á�ŭ�����Ρ���\n");

        if( me->query_skill("sad-strike",1) < 150 )
                return notify_fail("����Ȼ��������Ϊ̫��������á�ŭ�����Ρ���\n");
	
        if( (string)me->query_skill_mapped("unarmed") != "sad-strike")
		return notify_fail("�㲢û�м�����Ȼ��������Ϊ�Ʒ���\n");

        if( (string)me->query_skill_prepared("unarmed") != "sad-strike")
		return notify_fail("�㲢û��׼����Ȼ�����ơ�\n");

        if ( !living(target))    
               return notify_fail("���ڲ�û��Ҫ�á�ŭ�����Ρ��ɣ�\n");

        if( me->query("neili") <= 1000 )
                return notify_fail("�����������ʹ�á�ŭ�����Ρ���\n");

        ap = me->query_skill("force") + me->query_skill("unarmed") + me->query("jiali");
	dp = target->query_skill("force") + target->query_skill("parry");
	
        skill=me->query_skill("sad-strike",1);

        message_vision(HIW"\n$N���Ʒ��������ų�ӿ֮�����Ʒ�ĵ��������п�ӿ���������������������ں��������ľ����� \n\n"NOR,me,target);
	
	if (ap/2 + random(ap) > dp)
	{
		message_vision(HIR"$n�����ܵÿ��������Ѿ���$N���Ʒ�ӡ���ؿڣ�һ����Ѫ���������\n\n",me,target);
		target->receive_damage("qi",ap/2,me);
		target->receive_wound("qi",random(ap/2),me);
                            if (! target->is_busy()) 
			target->start_busy(1);
	} else
	{
		message_vision(HIY"$n��״������̾͵�һ���������Ȼ�����ѿ��Լ�����������ܿ���$N��һ�ơ�\n\n"NOR,me,target);
	}

        message_vision(HIW"\n$N���Ʒ�ﵽ����֮ʱ�����š��겻���ᡱ����������ʩ������������ʧ�����������С�\n\n"NOR,me,target);
	
	if (ap/2 + random(ap/2) > dp)
	{
		message_vision(HIR"$n����δ����������֮�ʣ��������һ�����ҵ������������������$N�Ʒ��ش���\n\n",me,target);
		target->receive_damage("qi",ap,me);
		target->receive_wound("qi",random(ap),me);
                            if (! target->is_busy()) 
			target->start_busy(1);
	} else
	{
		message_vision(HIY"$n�˲��÷���������������ɣ����ո�$N���Ʒ�ɨ����΢΢���죬��������ܿ���$N�����ơ�\n\n"NOR,me,target);
	}
	
        message_vision(HIW"����$N�������һ�С���ʬ���⡱��������߳�һ�š�\n\n"NOR,me);

	if (ap/3 + random(ap/3) > dp)
	{
		message_vision(HIR"$n�ۿ�������������һ�ţ���Ȼ�����˵ֿ�������������$N�������ϣ����ݽ��飬��ĿѪɫ������\n\n",me,target);
		target->receive_damage("qi",ap*2,me);
		target->receive_wound("qi",random(ap*2),me);
                            if (! target->is_busy()) 
			target->start_busy(1);
	} else
	{
		message_vision(HIY"$n˫���أ�������𣬴�$N��ͷ���ӹ������¾�����Х������������֮���գ�\n\n"NOR,me,target);
	}

        me->add("neili",-ap/2);
	me->start_busy(2+random(2));

        return 1;
}        
