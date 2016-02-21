// lifeheal.c

#include <ansi.h>

int exert(object me, object target)
{
        string force;

        if (! me->query("breakup")) 
                return notify_fail("�㻹û����������������������ľ��ϡ�\n");

        if (! target || target == me)
                return notify_fail("��Ҫ������Ϊ˭���ˣ�\n");

        if (me->is_fighting() || target->is_fighting())
                return notify_fail("ս�����޷��˹����ˣ�\n");

        if (target->query("not_living"))
                return notify_fail("�㲻�ܸ�" + target->name() + "���ˡ�\n");

        force = me->query_skill_mapped("force");
        if (! force)
                return notify_fail("����뼤��һ���ڹ������������ˡ�\n");

        if ((int)me->query_skill(force,1) < 50)
                return notify_fail("���" + to_chinese(force) + "�ȼ�������\n");

        if ((int)me->query("max_neili") < 300)
                return notify_fail("���������Ϊ������\n");

        if ((int)me->query("neili") < 150)
                return notify_fail("�����ڵ�����������\n");

        if ((int)target->query("eff_jing") >= (int)target->query("max_jing"))
                return notify_fail( target->name() +
                        "���ھ������棬����Ҫ���˹����ƣ�\n");

        if ((int)target->query("eff_qi") < (int)target->query("max_qi") / 5)
                return notify_fail( target->name() +
                        "�Ѿ����˹��أ����ܲ�����������𵴣�\n");

        message_vision(
                HIY "$N������������" + to_chinese(force) +
                "������������$n���ģ������ؽ���������$n����....\n"
                HIW "���˲��ã�$N��ͷ��ð������ĺ��飬$n�³�һ"
                "����Ѫ����������˫Ŀ���������䡣\n" NOR,
                me, target );

        target->receive_curing("jing", 5 + (int)me->query_skill("force") / 6);
//        target->add("qi", 10 + (int)me->query_skill("force") / 3);
        if ((int)target->query("jing") > (int)target->query("eff_jing"))
                target->set("jing", (int)target->query("eff_jing"));

        me->add("neili", -150);
        return 1;
}
