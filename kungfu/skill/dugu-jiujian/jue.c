// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// jue.c ���ܾ�ʽ��

#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object weapon;
        int skill, jing_cost;
        int improve;

        skill = me->query_skill("dugu-jiujian", 1);
        jing_cost = 45 - (int)me->query("int");
        if (jing_cost < 5) jing_cost = 5;

        /*
	if (environment(me)->query("no_fight"))
		return notify_fail("����̫���ӣ��㲻�ܾ�������������\n");
        */

        if (me->is_fighting())
                return notify_fail("���ܾ�ʽ��������ս����������\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("�������ȥ��һ�ѽ���\n");

        if (! skill || skill < 20)
                return notify_fail("��Ķ��¾Ž��ȼ�����, �����������ܾ�ʽ����\n");

        if (me->query("neili") < 50)
                return notify_fail("�������������û�������������ܾ�ʽ����\n");

        if (me->query("jing") < -jing_cost)
                return notify_fail("������̫���ˣ��޷����о����������ܾ�ʽ����\n");

        if (me->query_skill("dugu-jiujian", 1) > 800 && 
            me->query_skill("dugu-jiujian", 1) > me->query_skill("sword", 1))
                return notify_fail("��Ľ����������޷�ʹ�á��ܾ�ʽ������߶��¾Ž���\n");

        if (! me->can_improve_skill("dugu-jiujian"))
                return notify_fail("���ʵս���鲻�����޷���ᡸ�ܾ�ʽ����\n");

        msg = HIG "$N" HIG "ʹ�����¾Ž�֮���ܾ�ʽ����������" +
              weapon->name() + HIG "���������̡�\n" NOR;
        message_combatd(msg, me);

        me->add("neili", -50);
        me->receive_damage("jing", jing_cost);

        if (skill < 60)
           improve = 10; else
        if (skill < 90)
           improve = 10 + random((int)me->query_int() - 9); else
        if (skill < 140)
           improve = 10 + random((int)me->query_int() * 2 - 9); else
        if (skill < 200)
           improve = 10 + random((int)me->query_int() * 4 - 9); else
           improve = 10 + random((int)me->query_int() * 8 - 9);

        tell_object(me, MAG "��ġ������������͡����¾Ž��������ˣ�\n" NOR);
        me->improve_skill("sword", improve);
        me->improve_skill("dugu-jiujian", improve * 3 / 2);
        me->start_busy(random(2));
        return 1;
}
