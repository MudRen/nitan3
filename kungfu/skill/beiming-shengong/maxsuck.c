// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// maxsuck.c

#include <ansi.h>

inherit F_SSERVER;
int exert(object me, object target)
{
        int ap, dp, suck;

        if (target == me) target = offensive_target(me);

        if (me->is_busy()) return notify_fail("����æ���ء�\n");

        if (environment(me)->query("no_fight"))
                return notify_fail("�����ﲻ�ܹ������ˡ�\n");

        if (! objectp(target) || target->query("id") == "mu ren")
                return notify_fail("��Ҫ��ȡ˭�ĵ�Ԫ��\n");
                
        if (target->query("race") != "����")
                return notify_fail("����ˣ�ֻ���˲����е�Ԫ��\n");
       
        if (me->query_temp("sucked"))
                return notify_fail("��ո���ȡ����Ԫ��\n");
        if (objectp(me->query_temp("weapon")))
                return notify_fail("�������ֲ���ʩ�ñ�ڤ�����˵�Ԫ��\n");

        if ((int)me->query_skill("beiming-shengong", 1) < 90)
                return notify_fail("��ı�ڤ�񹦹���������������ȡ�Է��ĵ�Ԫ��\n");

        if ((int)me->query("neili") < 20)
                return notify_fail("�����������������ʹ�û����󷨡�\n");

        if ((int)me->query_skill("beiming-shengong", 1) < (int)me->query("max_neili") / 20)
                return notify_fail("��ı�ڤ��̫���ˣ�����ȡҲ��ͽ�͡�\n");
                
        if ((int)me->query("max_neili") >= (int)me->query_neili_limit())
                return notify_fail("���������Ϊ�ƺ��Ѿ��ﵽ��ƿ��������ȡҲ��ͽ�͡�\n"); 

        if ((int)target->query("max_neili") < 100 || target->query("no_suck"))
                return notify_fail(target->name() +
                        "��Ԫ��ɢ������δ�ۣ����޷�����������ȡ�κζ�����\n");

        if ((int)target->query("max_neili") < (int)me->query("max_neili") / 18)
                return notify_fail(target->name() +
                        "���ڹ���ΪԶ�����㣬���޷�����������ȡ��Ԫ��\n");

        message_combatd(
                HIG "$N��$n΢΢һЦ��ͻȻ���Ʊ�צ������$n������\n\n" NOR,
                me, target );
                
        me->want_kill(target);               
        if (living(target))
        {
                if (! target->is_killing(me))
                        target->kill_ob(me);
        }
        me->set_temp("sucked", 1);  

        ap = me->query_skill("force") * 3 / 2 + me->query("level") * 20 +  
             me->query_skill("martial-cognize", 1); 

        dp = target->query_skill("dodge") + target->query("level") * 20 +
             target->query_skill("martial-cognize", 1); 
             
        if (ap / 2 + random(ap) > dp || ! living(target))
        {
                tell_object(target, HIR "��ֻ��ȫ������ȫ��������ѩ����ʧ����Ӱ���٣�\n" NOR);
                tell_object(me, HIG "�����" + target->name() + "�ĵ�Ԫ������ԴԴ���������˽�����\n" NOR);
                
                suck = 1 + (me->query_skill("beiming-shengong", 1) - 90) / 5;
                
                target->add("max_neili",  - suck);
                me->add("max_neili",        suck);
                if (target->query("max_neili") < 1) 
                        target->set("max_neili", 0);

                me->start_busy(7);
                if (! target->is_busy())
                target->start_busy(7);
                me->add("neili", - 10);
                // remove_call_out("del_sucked");
                call_out("del_sucked", 10, me);
        }
        else
        {       
                message_combatd(HIY "����$p������$P����ͼ����������˿�ȥ��\n" NOR, me, target);
                me->start_busy(2 + random(5));
                // remove_call_out("del_sucked");
                call_out("del_sucked", 15, me);
        }

        return 1;
}

void del_sucked(object me)
{
        if (! me) return;
        
        if (me->query_temp("sucked"))
                me->delete_temp("sucked");
}



