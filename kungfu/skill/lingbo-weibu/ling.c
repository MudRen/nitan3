// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define LING "��" HIW "�����貨" NOR "��"

inherit F_SSERVER;
#include <balance.h>

void remove_effect(object me, int amount, int amount1);


int perform(object me, object target)
{
        string msg;
        int level, ap, dp, count;
        
        if (! target) target = offensive_target(me); 
        if (! target || ! target->is_character() || ! me->is_fighting(target)) 
                return notify_fail("��һ��������ô��\n"); 
        if (userp(me) && ! me->query("can_perform/lingbo-weibu/ling"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ" LING "��\n");

        if ((level = me->query_skill("lingbo-weibu", 1)) < 120)
                return notify_fail("����貨΢������������������ʩչ" LING "��\n" NOR);

        if ((int)me->query("neili") < 600)
                return notify_fail("�������������㣬����ʩչ" LING "��\n" NOR);

        if (me->query_temp("lingbo"))
                return notify_fail("���Ѿ����������貨���ˡ�\n");

        if( me->query("gender") == "Ů��")
               msg = HIW "\n$N" HIW "�����������������������ʮ"
                     "���ԣ����貨΢����ͷ��βѸ���ޱȵ�����һ�Ρ� "
                     "$N" HIW "�����������������ζ�ʱ��ӯ�ޱȣ�"
                     "΢���貨���������ң���ַ��ӵ����쾡����\n" NOR;

        else   msg = HIC "\n$N" HIC "�����������������������ʮ"
                     "���ԣ����貨΢����ͷ��βѸ���ޱȵ�����һ�Ρ�                    "
                     "ֻ��$N" HIC "��̬Ʈ�ݣ�Ӱ���ҷɣ����ζ�ʱ��"
                     "ӯ�ޱȣ��������ң���ַ��ӵ����쾡����\n" NOR;

        message_combatd(msg, me, target);
        /*
        count = level / 30;

        if (me->is_fighting())
                me->start_busy(2);

        me->add_temp("dex", count);
        me->set_temp("lingbo", 1);
        me->start_call_out((: call_other,  __FILE__, "remove_effect", me, count :), level / 2);

        me->add("neili", -400);
        return 1;
        */
        ap = ap_power(me, "dodge");
        dp = dp_power(target, "dodge");
                   
        if (ap / 2 + random(ap) > dp)
        {
                msg = HIW "$N���������·���$n������$N���貽ת�˸�ͷ���ۻ�\n" NOR;
                if (! target->is_busy())
                target->start_busy(3 + random(level / 80));
                me->add("neili", -400);
                // me->start_busy(1);
        } else 
        {
                msg = HIG "����$n������$N���貽,��̬���ݵĶ��˹�ȥ\n" NOR;
                me->add("neili", -100);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;

}

/*
void remove_effect(object me, int amount, int amount1)
{
        if ((int)me->query_temp("lingbo"))
        {
                me->add_temp("dex", -amount);
                me->delete_temp("lingbo");
                tell_object(me, "��ġ������貨���˹���ϣ��������ջص��\n");
        }
}
*/
