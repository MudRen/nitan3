// This is player's own perform (Write by Lonely@nt2)
// Create by 段左助(Rare) at Sat Apr  8 14:58:33 2006
// 搞你人(gnr)

#include <ansi.h>
#include <combat.h>

#define PFM "「" HIW "搞你人" NOR "」"

inherit F_SSERVER;
#include <balance.h>

string *weapon_sk = ({
        "sword", "blade", "staff", "whip", "club", "hammer", "axe"
});

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int count, damage;
        int attack_time;
        int attack, i;

        if (! me->query("can_perform/" + "six-finger" + "/" + "gnr"))
                return notify_fail("你还没有受到高手指点，还不会运用" PFM "。\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(PFM "只能对战斗中的对手使用。\n");

        if (member_array("finger", weapon_sk) != -1)
        {
                attack = WEAPON_ATTACK;
                if (! objectp(weapon = me->query_temp("weapon"))
                   || (string)weapon->query("skill_type") != "finger")
                        return notify_fail("你所使用的武器不对，难以施展" PFM "。\n");
        } else
        {
                attack = UNARMED_ATTACK;
                if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                        return notify_fail(PFM "只能空手使用。\n");             
        }
        
        if ((int)me->query_skill("six-finger", 1) < 400)
                return notify_fail("你" + to_chinese("six-finger") + "不够娴熟，难以施展" PFM "。\n");

        if (member_array("finger", weapon_sk) == -1)
        {
                if (me->query_skill_prepared("finger") != "six-finger")
                        return notify_fail("你没有准备" + to_chinese("six-finger") + "，难以施展" PFM "。\n");
        }
        
        if (me->query("neili") < 500)
                return notify_fail("你现在的真气不够，难以施展" PFM "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIW "搞就一个字，$N只讲一次。" + "\n" + NOR;

        ap = ap_power(me, "finger");
        dp = dp_power(target, "parry");
         
        if (ap / 2 + random(ap * 2) > dp)
        {
                damage = da_power(me, "finger") * 2;
                msg += COMBAT_D->do_damage(me, target, attack, damage, 100, HIM "$n立马挨搞了。" + "\n" NOR);
                me->add("neili", -200);
             
                if (! target->is_busy())
                        target->start_busy(2);
        } else
        {
                msg += NOR + CYN "$P这一下居然没搞中。" + "\n" NOR;
                me->add("neili", -100);
        }
                
        message_sort(msg, me, target);
    
        msg = HIW "$N" HIW "余势未尽，招式陡然变得凌厉无比，一转念间已然攻出数招。\n" NOR;
        if (ap / 2 + random(ap * 2) > dp)
        {
                count = ap / 20;
                msg += HIR "$n" HIR "见$P" HIR "来势迅猛之极，一时不知该如"
                       "何作出抵挡，竟呆立当场。\n" NOR;
        } else
        {
                msg += HIY "$n" HIY "见$p" HIY "来势迅猛之极，甚难防备，连"
                       "忙振作精神，小心抵挡。\n" NOR;
                count = 0;
        }

        message_combatd(msg, me, target);
        
        attack_time = 3;
        attack_time += me->query("jieti/times") * 2;
        if (attack_time > 8)
                attack_time = 8;

        me->add("neili", -attack_time * 20);

        me->add_temp("apply/attack", count);
        me->add_temp("apply/damage", count);
                
        for (i = 0; i < attack_time; i++)
        {
                if (! me->is_fighting(target))
                        break;

                COMBAT_D->do_attack(me, target, (member_array("finger", weapon_sk) == -1 ? 0 : weapon), 0);
        }
        me->add_temp("apply/attack", -count);
        me->add_temp("apply/damage", -count);
        me->start_busy(3 + random(attack_time/ 3));                        
        return 1;
}

