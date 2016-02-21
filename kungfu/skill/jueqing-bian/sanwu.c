
// sanwu.c
// Xuanyuan 14/7/2001

#include <ansi.h>
inherit F_SSERVER;

void remove_effect(object me);

int perform(object me, object target)
{
        int skill, amount;
        string weapon;

        if( !target ) target = offensive_target(me);

       	if( userp(me) && !me->query("can_perform/jueqing-bian/sanwu"))
		return notify_fail("��δ������ָ�㣬�������⡸���������֡���ȴ��֪����ʩչ��\n");

        if( me->query_temp("sanwu_busy") )
                return notify_fail("��΢һ�˾���ȴ�����Լ�˫������һʱ�޷�ʩչ�����������֡���\n");

        if( !target || !target->is_character() ||  !me->is_fighting(target) )
                return notify_fail("�����������֡�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( me->query_temp("yield") )
                return notify_fail("�㲻���ƣ����ʹ�������������֡���\n");

        if( me->query_skill_mapped("force") != "wudu-xinfa" )
                return notify_fail("�����õ��ڹ��롸���������֡���·��㣣�\n");

        if( me->query_skill("wudu-xinfa", 1) < 60 )
                return notify_fail("����嶾�ķ����δ�����޷�ʩչ�����������֡���\n");

        if( me->query_skill("jueqing-bian", 1) < 100 )
                return notify_fail("����޷�������죬�޷�ʩչ�����������֡���\n");

        if( (int)me->query("max_neili", 1) < 1000 )
                return notify_fail("���������Ϊ����������ʩչ�����������֡���\n");

        if( me->query("neili") < 800 )
                return notify_fail("�����ڵ�����̫��������ʹ�á����������֡���\n");

        if( (int)me->query("jingli", 1) < 300 )
                return notify_fail("�����ڵ�����̫��������ʹ�á����������֡�\n");

        message_vision( HIR"\n$Nһ����Ц��Ѹ���������������У����ǳ������ӵľ��������������֡���\n"NOR, me);

        me->add("neili", -400);
        me->add("jingli", -100);
        me->set_temp("sanwu", 1);

                skill = me->query_skill("whip");

                switch ( me->query_temp("sanwu") )
                {
                        case 1:         
                                amount = skill/20;
                                break;
                        case 2:
                                amount = skill/15;
                                break;
                        case 3:
                                amount = skill/10;
                                break;
                }

                me->add_temp("apply/attack", amount);
                me->add_temp("apply/damage", amount);

                COMBAT_D->do_attack(me,target,me->query_temp("weapon"));
		me->add_temp("sanwu", 1);
                COMBAT_D->do_attack(me,target,me->query_temp("weapon"));
		me->add_temp("sanwu", 1);
                COMBAT_D->do_attack(me,target,me->query_temp("weapon"));
		me->add_temp("sanwu", 1);
                me->add_temp("apply/attack", -amount);
                me->add_temp("apply/damage", -amount);

                me->set_temp("sanwu_busy", (int)me->query_temp("sanwu"));

                if ( !me->query_temp("sanwu") || me->query_temp("sanwu") == 4 )
                        remove_effect(me);

		me->start_busy(2);
		return 1;
}

void remove_effect(object me)
{
        int sanwu_busy = me->query_temp("sanwu_busy");

        int amount = (int)(450 - me->query_skill("whip")) / 2;
        if ( amount < 15 ) amount = 15;

        if ( sanwu_busy == 4 )
                message_vision(RED"\n$N���޻����������������ӵ����쾡�£����Ƕ���������\n"NOR,me);

        // if 3 hit all missed, delete sanwu temp here.
        if ( me->query_temp("sanwu") )
                me->delete_temp("sanwu");

        // more hits, cost more neili, min 100, max 300.
        me->add("neili", -100 * sanwu_busy);

        // more hits, longer busy time, longer to receive heal.
        me->start_busy(sanwu_busy + random(2));
        call_out("receive_heal", (int)amount * sanwu_busy / 3, me);
}

void receive_heal(object me)
{
        if ( !me ) return;

        me->delete_temp("sanwu_busy");
        tell_object(me, HIG"\n�㾭��һ���˹���Ϣ�����Ͼ�����������ʱ�����������������ֹ��С�\n"NOR); 
}
