// hua.c

#include <ansi.h>

inherit F_SSERVER;

int exert(object me, object target)
{
        int sp, dp;
        int my_max, tg_max;
        int suck;

        if (target == me) target = offensive_target(me);

        if (! environment(me)) return 0;
        if (environment(me)->query("no_fight"))
                return notify_fail("�����ﲻ�ܹ������ˡ�\n");

        if (! objectp(target))
                return notify_fail("��Ҫ��˭��������\n");

        if (target->query("race") != "����")
                return notify_fail("����ˣ�ֻ���˲�����������\n");

        if (me->is_busy())
                return notify_fail("��������æ���޷�������������\n");

        my_max = me->query("max_neili");
        tg_max = target->query("max_neili");

        if (objectp(me->query_temp("weapon")))
                return notify_fail("�������ֲ���ʩ�û����󷨣�\n");

        if ((int)me->query_skill("huagong-dafa", 1) < 90)
                return notify_fail("��Ļ����󷨹�������������ʩչ��\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("�����������������ʩչ�����󷨡�\n");

        if ((int)me->query("max_neili") >= (int)me->query_neili_limit())
                return notify_fail("���������Ϊ�ƺ��Ѿ��ﵽ��ƿ��������ȡҲ��ͽ�͡�\n"); 


        if ((int)target->query("neili") < 10 ||
            (int)target->query("max_neili") < 10)
                return notify_fail(target->name() +
                                   "��Ȼ������ɢ�������ٻ��ˡ�\n");

        if ((int)target->query("max_neili") > (int)me->query("max_neili") * 4 / 3 )
                return notify_fail( target->name() +
                        "���ڹ���ΪԶʤ���㣬���޷��ӻ�����������\n");

        message_combatd(HIR "$N" HIR "ȫ��ǽڱ��죬˫�۱������ߣ�����"
                        "ˢ��һ����ճ��$n��\n" NOR,
                        me, target);

        me->want_kill(target);
        if (living(target))
                if (! target->is_killing(me)) target->kill_ob(me);

        sp = me->query_skill("force") + me->query_skill("dodge");
        dp = target->query_skill("force") + target->query_skill("dodge");

        if ((sp / 2 + random(sp) > random(dp)) || ! living(target))
        {
                tell_object(target, HIR "��ֻ���춥���ѣ�ȫ����"
                            "���Զ���������ѩ����ʧ����Ӱ���٣�\n" NOR);
                suck = 1 + (me->query_skill("huagong-dafa", 1) - 90) / 8;
                target->add("max_neili", -suck);
                me->add("max_neili",      suck);
                if (target->query("max_neili") < 1)
                        target->set("max_neili", 0);

                me->start_busy(4 + random(4));
                target->start_busy(4 + random(4));
        } else
        {       
                message_combatd(HIY "����$p" HIY "������$P"
                                HIY "����ͼ�������͵�һ�𣬽�����"
                                "�˿�ȥ��\n" NOR, me, target);
                me->start_busy(4 + random(4));
        }

        return 1;
}


