// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// leidong.c �׶�����

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        int improve;
        object weapon = me->query("weapon");
        
        if (! target) target = offensive_target(me);

        if (! target || ! target->is_character() || ! me->is_fighting(target))
                return notify_fail("�׶�����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
                
        if (userp(me) && ! me->query("can_perform/poyu-quan/lei"))
                 return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ��\n"); 
                 
        if (objectp(me->query_temp("weapon")))
                return notify_fail("�������ֲ���ʹ���׶����죡\n");  
                
        if ((int)me->query_skill("poyu-quan", 1) < 80)
                return notify_fail("�������ȭ������죬����ʹ���׶����죡\n");
                                
        if ((int)me->query_skill("zixia-shengong", 1) < 80)
                return notify_fail("�����ϼ�񹦲����ߣ������ó��׶������˵С�\n");

        if (me->query_skill_prepared("cuff") != "poyu-quan"
                || me->query_skill_mapped("cuff") != "poyu-quan")
                return notify_fail("�������޷�ʹ�á��׶����졹���й�����\n");                                                                                 

        if ((int)me->query("neili") < 200)
                return notify_fail("����������̫�����޷�ʹ���׶����졣\n");

        if (me->query_temp("leidong"))
                return notify_fail("������ʹ���׶����죡\n");

        msg = MAG "$N" MAG "ʹ����ʯ����ȭ�ľ�ѧ�׶����죬��ʱ��յ���������\n" NOR;
        message_combatd(msg, me, target); 
      
        improve = (int)me->query("dex");
        improve += (int)me->query("str");
        me->add_temp("apply/dex", improve);
        me->add_temp("apply/str", improve);
        me->set_temp("leidong", 1);  
        
        me->add("neili", -150); 
        target->start_busy(random((int)me->query_skill("leidong") / 20 + 2));      
        me->start_call_out((: call_other, __FILE__, "remove_effect", me, improve :),
                            me->query_skill("poyu-quan", 1) / 5);
        return 1;
}

void remove_effect(object me, int improve)
{
        if ((int)me->query_temp("leidong"))  
        {
                me->add_temp("apply/dex", - improve);
                me->add_temp("apply/str", - improve);
                me->delete_temp("leidong");
        }
}


