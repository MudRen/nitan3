// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define LIU "��" HIY "���½���" NOR "��"

inherit F_SSERVER;
#include <balance.h>
 
int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;

        if (userp(me) && ! me->query("can_perform/liuyue-jian/liu"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ" LIU "��\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(LIU "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" LIU "��\n");

        if (me->query_skill("force") < 180)
                return notify_fail("����ڹ�����Ϊ����������ʩչ" LIU "��\n");

        if (me->query_skill("liuyue-jian", 1) < 120)
                return notify_fail("������½�����Ϊ����������ʩչ" LIU "��\n");

        if (me->query("neili") < 250)
                return notify_fail("�����������������ʩչ" LIU "��\n");

        if (me->query_skill_mapped("sword") != "liuyue-jian")
                return notify_fail("��û�м������½��裬����ʩչ" LIU "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "һ����Х���������䣬����" + weapon->name() + HIY
              "���Ữ��������һ���ޱ�Ѥ���Ľ�â��ңָ$n" HIY "��ȥ��\n" NOR;
              
        ap = ap_power(me, "sword"); 
        dp = dp_power(target, "parry"); 

        if (ap / 2 + random(ap) > dp)
        {
                damage = da_power(me, "sword");
                me->add("neili", -150);
                
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 45,
                                           HIR "$n" HIR "��ʱĿ�ɿڴ���һ����������$N"
                                           HIR "����Ľ��д��У���Ѫ�ɽ���\n" NOR);
                me->start_busy(2);
        } else
        {
                me->add("neili", -60);
                
                msg += CYN "����$p" CYN "�������ң�������������񵲿���$P"
                       CYN "�Ľ��С�\n" NOR;
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}
