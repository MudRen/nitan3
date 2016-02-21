// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// huadu.c ����

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int i);

int exert(object me, object target)
{
        int skill, i;

        if( target != me || !target ) target = me;

        if ((int)me->query_skill("huagong-dafa", 1) < 50)
               return notify_fail("��Ļ����󷨹����̫ǳ��\n");

        if ((int)me->query_skill("poison", 1) < 50)
               return notify_fail("�����ڵĶ��ز����������衣\n");


        if( (int)me->query("neili") < 800  ) 
                return notify_fail("������������ڻ�����n");

        if ((int)me->query("jing") < 60) 
                return notify_fail("��ľ���״̬�����ڻ�����\n");

        if( (int)me->query_temp("huadu") ) 
                return notify_fail("�����˹������ˡ�\n");

        skill = me->query_skill("force");
        me->add("neili", 400);
        me->recieve_damage("jing", 50);

        message_combatd(BLU"$N��Ŀ���񣬽������̻��Ķ���������Ϊ��������ɢ����֫�ڡ�\n" NOR, me);
        i = me->query_skill("poison", 1) / 2;
        me->add_temp("apply/attack", i);       
        me->set_temp("huadu", 1);

        me->start_call_out((: call_other, this_object(), "remove_effect", me, i:), skill);

        if( me->is_fighting() ) me->start_busy(2);

        return 1;
}

void remove_effect(object me, int i)
{
        if (me->query_temp("huadu"))
        {
                me->add_temp("apply/attack", -i);           
                me->delete_temp("huadu");
                message_combatd(BLU "$N�˹�������ϣ����������ض����̻����ڡ�\n" NOR, me);
        }
}

