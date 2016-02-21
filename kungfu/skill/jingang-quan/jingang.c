// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// jingsng.c ���ȭ ������ͨ

#include <ansi.h>

inherit F_SSERVER;

void remove_effect(object me, int aamount, int damount);

int perform(object me, object target)
{
        object weapon;  
        string msg;
        int d_count, count, qi, maxqi, skill;

        if (userp(me) && ! me->query("can_perform/jingang-quan/jingang"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ��������ͨ����\n");

        if ((string)me->query("family/family_name") != "������")
                return notify_fail("�����ڷ��ţ��Ѿ����Ѽ�������ʩչ��������ͨ���ˡ�\n");

                
        if ((int)me->query_temp("jingang"))
                return notify_fail("���Ѿ����˹����ˡ�\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }
        if (! target || ! me->is_fighting(target))
                return notify_fail("��������ͨ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("��������������޷�ʩչ��������ͨ����\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("����ڹ���Ϊ����������ʹ�ô�����ͨ��\n");

        if ((int)me->query_skill("cuff") < 150)
                return notify_fail("���ȭ���������ң��޷�ʹ�ô�����ͨ��\n");

        if (me->query_skill_mapped("cuff") != "jingang-quan") 
                return notify_fail("��û�м������ȭ���޷�ʹ�ô�����ͨ��\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "ʹ������ȭ�ľ�����������ͨ����������Ȼ���ӣ�\n" NOR;
        
        qi = me->query("qi");
        maxqi = me->query("max_qi");
        skill = (int) (me->query_skill("jingang-quan", 1) / 3);
        count = me->query_str();
        d_count = (int)me->query_dex() / 2;

        if (qi > (maxqi * 0.4))
        {       
                message_combatd(msg, me, target);
                
                me->add_temp("str", count * 2);
                me->set_temp("jingang", 1);
                me->start_call_out((: call_other, __FILE__, "remove_effect", me, count * 2, d_count :), skill);

                me->add("neili", -150);
               me->start_busy(3+random(2));
        } else
        {
                msg = HIR "$N" HIR "ƴ����������ʹ���˴���ȭ����"
                      "������, ȫ�����һ����, ����$n" HIR "ͬ���ھ���\n" NOR;
                message_combatd(msg, me, target);
                me->add_temp("str", count * 9);
                me->set_temp("jingang", 1);

                me->start_call_out((: call_other, __FILE__, "remove_effect", me, count * 9, 0 :), 2);

                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                me->set("neili",0);
                me->add("max_neili", -10);

                msg = HIR "$N" HIR "�þ������һ������, ���һ����Ѫ, һͷ�Ե��ڵأ�\n" NOR;
                message_combatd(msg, me, target);
                me->unconcious();
        }
        return 1;
}

void remove_effect(object me, int aamount, int damount)
{
        if ((int)me->query_temp("jingang"))
        {
                me->add_temp("str", -aamount);
                me->delete_temp("jingang");
                tell_object(me, "��Ĵ�����ͨ������ϣ��������ջص��\n");
        }
}

