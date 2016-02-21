// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// huayu.c ���컨��

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        string msg;
        object weapon;
        int damage, num, lvl, p, ap, dp;

        if (! target) target = offensive_target(me);

        if (! target || ! target->is_character() || ! me->is_fighting(target))
                return notify_fail("���컨��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (userp(me) && ! me->query("can_perform/tanzhi-shentong/huayu"))
                return notify_fail("����Ȼ��˵�������컨�ꡱ��һ�У�����ȴδ���ڡ�\n");

        lvl = (int)me->query_skill("tanzhi-shentong", 1);
         
        if (lvl < 120) return notify_fail("��ĵ�ָ��ͨ������죬�޷�ʹ�����컨�ꡣ\n");

        if (! objectp(weapon = me->query_temp("handing"))
           || (string)weapon->query("skill_type") != "throwing")
                return notify_fail("������û�����Ű���������ʩչ���컨�ꡣ\n");
                 
        if ((num = weapon->query_amount()) < lvl / 20) 
                return notify_fail("�������ͱ��ң���������İ����Ѿ�����ʹ�����컨���Ҫ���ˣ�\n");

        if ((int)me->query("neili") < 450)
                return notify_fail("��������������޷�ʹ�����컨�ꡣ\n");

        msg = CYN "$N˫���ڱ�����һץ��ץ��" + CHINESE_D->chinese_number(lvl / 20) + 
              weapon->query("base_unit") + weapon->query("name") + 
              "����\n����ָ������ص��˳�ȥ��$nֻ����ǰ�ƺ�����һ�������꣡\n";
        
        ap = ap_power(me,"finger");
        dp = dp_power(target,"dodge");
        
        if (ap / 2 + random(ap) > dp) 
        {
                damage = da_power(me, "finger");
                me->add("neili", 350);

                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 80, 
                                           HIR "$n���������������ۡ��ؼ������������������У�\n��ʱ��Ѫ�ɽ���\n" NOR);
                me->start_busy(2); 
        } else 
        {
                me->add("neili", -100);
                msg += WHT "$n�ŵø�æ��ͷ��������Ǳ������Ա�һ�������ſ����ض��˹�ȥ��\n" NOR;
                me->start_busy(3); 
        }
        message_combatd(msg, me, target);

        weapon->add_amount(-(lvl/20));
        me->reset_action();

        return 1;
}

