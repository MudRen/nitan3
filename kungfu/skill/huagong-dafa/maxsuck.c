// jinglisuck.c
// Updated by Lonely

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int exert(object me, object target)
{
        int sp, dp, suck;

        if (! target) target = offensive_target(me);

        if (! objectp(target) || target == me)
                return notify_fail("��Ҫ��ȡ˭�ľ�Ԫ��\n");
                
        if (target->query("id") == "mu ren")
                return notify_fail("��Ҫ��ȡ˭�ľ�Ԫ��\n");
                
        if (target->query("race") != "����")
                return notify_fail("����ˣ�ֻ���˲����о�Ԫ��\n");
                
        if (me->is_busy()) return notify_fail("����æ���ء�\n");

        if (me->query_temp("sucked"))
                return notify_fail("��ո���ȡ��������\n");

        if (objectp(me->query_temp("weapon")))
                return notify_fail("�������ֲ���ʩ�û��������˾�Ԫ��\n");
        
        if ((int)me->query_skill("huagong-dafa", 1) < 90)
                return notify_fail("��Ļ����󷨹���������������ȡ�Է��ľ�Ԫ��\n");

        if ((int)me->query("jingli") < 5)
                return notify_fail("��ľ�������������ʹ�û����󷨡�\n");

        if ((int)me->query("max_jingli") > (int)me->query_current_jingli_limit()) 
                return notify_fail("��ľ�����Ϊ�ƺ��Ѿ��ﵽ��ƿ��������ȡҲ��ͽ�͡�\n");
                
        if ((int)me->query_skill("huagong-dafa", 1) < (int)me->query("max_jingli") / 10)
                return notify_fail("��Ļ�����̫���ˣ�����ȡҲ��ͽ�͡�\n");

        if ((int)target->query("max_jingli") <= 100 || target->query("no_suck"))
                return notify_fail(target->name() + "�Ѿ���Ԫ��ɢ�����Ѿ��޷�����������ȡ�κξ�Ԫ�ˣ�\n");
                
        if ((int)target->query("max_jingli") < (int)me->query("max_jingli") / 10)
                return notify_fail(target->name() + "�ľ�����ΪԶ�����㣬���޷�����������ȡ��Ԫ��\n");

        message_combatd(
                HIY "$Nȫ��ǽڱ��죬˫�۱������ߣ���Ե�͵���$n������������ȥ��\n\n" NOR,
                me, target );
                
        if (living(target))
        {
                if (! target->is_killing(me)) 
                        if (playerp(target))
                                target->want_kill(me);
                        target->kill_ob(me);
        }

        sp = me->query_skill("force", 1) * 3 / 2 + me->query("level") * 20 +  
             me->query_skill("martial-cognize", 1); 

        dp = target->query_skill("dodge") + target->query("level") * 20 +
             target->query_skill("martial-cognize", 1); 

        me->set_temp("sucked", 1);              

        if (dp / 2 + random(dp) < sp || ! living(target))
        {
                tell_object(target, HIR "��ֻ���춥���ѣ���Ԫ���ˮ���Ի���Ѩ���ڶ�����\n" NOR);
                tell_object(me, HIG "�����" + target->name() + "�ľ�Ԫ������ԴԴ���������˽�����\n" NOR);
                
                suck = 1 + (me->query_skill("huagong-dafa", 1) - 90) / 5;

                target->add("max_jingli", - suck);
                me->add("max_jingli",       suck);
                
                if (target->query("max_jingli") < 1) 
                        target->set("max_jingli", 0);

                me->start_busy(7);
                target->start_busy(7);
                me->add("jingli", - 5);
                // remove_call_out("del_sucked");
                call_out("del_sucked", 10, me);
        }
        else
        {       
                message_combatd(HIY "����$p������$P����ͼ�������͵�һ�𣬽������˿�ȥ��\n" NOR, me, target);
                me->start_busy(2 + random(5));
                // remove_call_out("del_sucked");
                call_out("del_sucked", 15, me);
        }

        return 1;
}

void del_sucked(object me)
{
        if (me->query_temp("sucked"))
                me->delete_temp("sucked");
}



