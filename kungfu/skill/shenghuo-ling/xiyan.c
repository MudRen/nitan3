#include <ansi.h>
inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object weapon, weapon2, target;
        int skill, ap, dp;

        if (!objectp(weapon = me->query_temp("weapon")))
                return notify_fail("��ʹ�õı������ԣ�����ʹ��ʥ����֮�����\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        skill = me->query_skill("shenghuo-ling", 1);

        if( !(me->is_fighting() ))
                return notify_fail("������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (!objectp(weapon2 = target->query_temp("weapon")))
                return notify_fail("�Է�û��ʹ�ñ�����������������Ҳû�á�\n");

	if( me->query_skill_mapped("force") != "shenghuo-xuanming")
	    return notify_fail("��ʹ�õ��ڹ�����ʥ����ڤ���޷�ʹ��ʥ�����\n");

        if( skill < 160)
                return notify_fail("���ʥ����ȼ�����, ����ʹ�������\n");

        if( me->query("max_neili") < 1500 )
                return notify_fail("���������Ϊ���㣬�޷����������\n");

        if( me->query("neili") < 500 )
                return notify_fail("��������������޷�ʹ�������\n");

        msg = HIM "ͻȻ$N�����һЦ��ʹ��ʥ���֮���������" +weapon->name()+ NOR + HIM"�ó�����СȦ����$n��" +weapon2->name()+ NOR + HIM"������ס��\n" NOR;
        message_combatd(msg, me, target);

        ap = me->query_skill("sword")/3 + skill;
        dp = target->query_skill("parry");

        if( dp < 1 )
            dp = 1;

        if( random(ap) > random(dp) || !living(target))
        {
                if(userp(me))
                me->add("neili", -300);
                msg = HIM "$nֻ����ǰ���������Ծ��������ʱֻ��ͷ��Ŀѣ������һ�飬����" +weapon2->name()+ NOR + HIM"�ѱ�$N���뻳�У�\n" NOR;
                weapon2->move(me);
		target->reset_action();
                me->start_busy(random(2));
                target->start_busy(2);
        }
        else
        {
                if(userp(me))
	                me->add("neili", -100);
                msg = CYN "����$n������$N����ͼ�������б��л�����ܲ�͸�磬ʹ��$N�޴����֡�\n"NOR;
                me->start_busy(4);
        }
        message_combatd(msg, me, target);
        return 1;
}


