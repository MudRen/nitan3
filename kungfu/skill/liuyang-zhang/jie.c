// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// jie.c �������� 

#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        object obj;
        string msg;

        if (! target) target = offensive_target(me);

        if (userp(me) && ! me->query("can_perform/liuyang-zhang/zhong"))
                return notify_fail("�������������������֣����ǲ�������δ߶����������\n");

        if (! target || ! target->is_character())
                return notify_fail("��Ҫ��˭����������\n");

        if (((int)me->query_skill("bahuang-gong", 1) < 40 ) &&
            ((int)me->query_skill("beiming-shengong", 1) < 40 ))
                return notify_fail("��ı����ڹ�������죬���ܽ���������\n");

        if ((int)me->query_skill("liuyang-zhang", 1) < 150)
                return notify_fail("�����ɽ�����Ʋ�����죬���ܽ���������\n");

        if (! objectp(obj = present("jiudai", me)))
                return notify_fail("������û�оƴ����޷������ⶾ��\n");

        if (me->query("neili") < 200)
                return notify_fail("���������㡣\n");

        if (! target->query_condition("ss_poison"))
                return notify_fail("Ŀ��û������������\n");

        message_combatd(HIY CYN "\n$N��ɫͻ�䣬���м�ת��������$n������ʮ���ƣ��⿪��$n������������\n" NOR, me, target);
        me->add("neili", -200);
        me->start_busy(2);
        target->apply_condition("ss_poison", 0);
        return 1;
}

