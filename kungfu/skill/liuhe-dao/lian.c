// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// lianhuan.c  ���ϵ�֮������

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int skill;

/*
        if (userp(me) && ! me->query("can_perform/liuhe-dao/lian"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ��������\n");
*/
                
        if (! target ) target = offensive_target(me);

        if (! target
        ||      ! target->is_character()
        ||      ! me->is_fighting(target) )
                return notify_fail("���ϵ�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("lianhuan") )
                return notify_fail("������ʹ�����ϵ��������ˣ�\n");

        weapon = me->query_temp("weapon");
        if (! objectp(weapon) || weapon->query("skill_type") != "blade" )
                return notify_fail("�������޵�������ܹ�ʩչ��������\n");

        if (me->query_skill_mapped("force") != "huntian-qigong" )
                return notify_fail("�����õĲ��ǻ����������޷���ϵ���ʩչ��������\n");

        if (me->query_skill("force") < 100)
                return notify_fail("��Ļ����������δ�����޷���ϵ���ʩչ��������\n");

        if (me->query_skill("blade") < 100)
                return notify_fail("�����ϵ�����Ϊ���㣬������ʹ����������\n");

        if (me->query("neili") <= 300)
                return notify_fail("�����������ʩչ��������\n");
                
        skill = me->query_skill("blade");
        
        message_combatd(HIR "\n$N���һ�������е���������������������������\n\n" NOR, me, target);

        me->set_temp("lianhuan", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), skill/5);
        me->add("neili", -300);

        return 1;
}

void remove_effect(object me, int amount)
{
        if (! objectp(me)) return;
        
        me->delete_temp("lianhuan");
}

