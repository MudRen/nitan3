// xingyun.c 星云密布

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        int n, ap, dp;
        string msg, pmsg;
        object weapon;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("你只能在战斗中对对手使用暗器。\n");

        if (! objectp(weapon = me->query_temp("handing")) ||
            (string)weapon->query("skill_type") != "throwing")
                return notify_fail("你现在手中并没有拿着暗器。\n");

        if (weapon->query_amount() < 10)
                return notify_fail("你至少要有十枚暗器才能施展星云密布。\n");

        if ((me->query_skill("xinghui-canlan", 1)) < 120)
                return notify_fail("你的星辉灿烂不够娴熟，还无法使出星云密布绝技。\n");

        if ((int)me->query("neili") < 120)
                return notify_fail("你现在内力不足，无法施展星云密布。\n");

        me->add("neili", -80);
        weapon->add_amount(-10);

        msg= HIW "$N" HIW "飞身跃起，左手一张，顿时一片星光点点"
             HIW "如夜雨流星一般直向$n"
             HIW "射去！\n" NOR;

        me->start_busy(2);
        ap = me->query_skill("xinghui-canlan", 1);
        dp = target->query_skill("dodge", 1);
        if (ap / 2 + random(ap) > dp || !living(target))
        {
                n = 1 + random(2);
                if (random(ap) > dp)  n += 1 + random(2);
                if (random(ap / 2) > dp)  n += 1 + random(2);
                if (random(ap / 4) > dp)  n += 1 + random(2);
                msg += HIR "结果$p" HIR "一声惨嚎，连中了$P" HIR "发出的" HIR +
                       chinese_number(n) + weapon->query("base_unit") +
                       weapon->name() + HIR "。\n" NOR;
                target->receive_wound("qi", ap / 4 + random(ap / 4), me);
                while (n--)
                {
                        COMBAT_D->clear_ahinfo();
                        weapon->hit_ob(me, target,
                                       me->query("jiali") + n * 10);
                }
                if (stringp(pmsg = COMBAT_D->query_ahinfo()))
                        msg += pmsg;
                message_combatd(msg, me, target);
        } else
        {
                msg += HIG "可是$p" HIG "纵身跃起，躲过了$P" HIG "漫天射出的" +
                       weapon->name() + HIG "。\n" NOR;
                message_combatd(msg, me, target);
        }

        me->reset_action();
        return 1;
}

