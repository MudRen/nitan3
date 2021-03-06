// Updated by Lonely

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        int damage, ap, dp;
        string msg;
    
        if (! target) target = offensive_target(me);

/*
        if (userp(me) && ! me->query("can_perform/wudang-zhang/zhen")) 
                return notify_fail("你还没有受过高人指点，无法施展「震」字诀。\n"); 
*/
        
        if (! target || ! target->is_character() || 
            ! me->is_fighting(target))
                return notify_fail("震字决只能对战斗中的对手使用。\n");
                
        if ((int)me->query_skill("wudang-zhang", 1) < 100)
                return notify_fail("你的武当棉掌不够娴熟，不会使用「震」字诀。\n");
        
        if (me->query("neili") < 500)
                return notify_fail("你的内力不够！\n");
                
        msg = HIB "$N气运丹田，使出棉掌震字决，双掌泛起凌厉掌风，拍向$n。\n" NOR;
        
        ap = ap_power(me, "strike");
        dp = dp_power(target, "force");

        if (ap / 2 + random(ap) > dp) 
        {
                damage = da_power(me, "strike");
                me->add("neili", - 400);
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 50,
                        HIR "$n 茫然不知所措，结果被$N一掌击中前胸，$n眼前一黑，被击飞出两丈许！！！\n" NOR);
                me->start_busy(2);
        } else
        {
                me->add("neili", 200);
                me->start_busy(3);
                msg += HIG "可是$p看破了$P的企图，早就闪在了一边。\n" NOR;
        }
        
        message_combatd(msg, me, target);
        return 1;
}


