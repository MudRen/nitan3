// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// shenfeng.c 华岳三神峰

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        int lvl;
        object weapon;
      
        weapon = me->query_temp("weapon");
        lvl = ((int)me->query_skill("fanliangyi-dao", 1) + 
            (int)me->query_skill("poyu-quan", 1)) / 8;
            
        if (! target ) target = offensive_target(me);
     
        if (! target || ! me->is_fighting(target) )
                return notify_fail("「华岳三神峰」只能在战斗中对对手使用。\n");

        if (userp(me) && ! me->query("can_perform/fanliangyi-dao/sanshen"))
                return notify_fail("你还没有受过高人指点，无法施展「华岳三神峰」。\n"); 
                
        if (! weapon || weapon->query("skill_type") != "blade"
        ||  me->query_skill_mapped("blade") != "fanliangyi-dao")
                return notify_fail("你手里没有刀，无法使用「华岳三神峰」！\n");             

        if ((int)me->query_skill("fanliangyi-dao", 1) < 100)
                return notify_fail("你的反两仪刀不够娴熟，不能使用「华岳三神峰」！\n");
      
        if ((int)me->query_skill("blade", 1) < 100)
                return notify_fail("你的基本刀法等级不够，不能使用「华岳三神峰」！\n");  

        if ((int)me->query_skill("poyu-quan", 1) < 100)
                return notify_fail("你的破玉拳法等级不够，不能使用「华岳三神峰」！\n");
      
        if ((int)me->query_skill("zixia-shengong", 1) < 80)
                return notify_fail("你的紫霞神功等级不够，不能使用「华岳三神峰」！\n");

        if ((int)me->query("max_neili") < 200)
                return notify_fail("你的内力太弱，不能使用「华岳三神峰」！\n");
      
        if ((int)me->query("neili") < 100)
                return notify_fail("你的内力太少了，无法使用出「华岳三神峰」！\n");   
                                                                                 
        if (me->query_skill_prepared("cuff") != "poyu-quan"
        ||  me->query_skill_mapped("cuff") != "poyu-quan")
                return notify_fail("你现在无法使用「华岳三神峰」进行攻击。\n");             

        message_combatd(HIC "\n$N" HIC "仰天一声清啸，运足内力使出「华岳三神峰」，向$n" HIC "雷霆般地击出两拳一刀！\n" NOR, 
                        me,target);
        me->add("neili", -350);      
        me->add_temp("apply/str", lvl / 10);
        me->add_temp("apply/dex", lvl / 10);
        
        weapon->unequip(); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);  
        if (! target->is_busy())
                target->start_busy(2);
        weapon->wield();
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);  
        if (! target->is_busy())
                target->start_busy(2);
        weapon->unequip();
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);  
        me->start_busy(2);
        if (! target->is_busy())
                target->start_busy(2);

        me->add_temp("apply/str", -lvl / 10);
        me->add_temp("apply/dex", -lvl / 10);
        weapon->wield();
        return 1;
}

