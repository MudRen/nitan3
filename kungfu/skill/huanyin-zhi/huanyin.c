// huanyin.c ������ָ

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        string msg;
        int ap, dp, damage;

        if (! target) target = offensive_target(me);

        if (environment(me)->query("no_fight"))
                return notify_fail("���ﲻ�ܹ�������! \n");

        if (! target || ! target->is_character())
                return notify_fail("ʩ��ֻ�ܶԶ���ʹ�á�\n");

        if (target->query("not_living"))
                return notify_fail("��������ǲ��ǻ��ˡ�\n");

        if ((int)me->query_skill("force") < 300)
                return notify_fail("����ڹ��������ʩչ������ָ��\n");

        if ((int)me->query_skill("huanyin-zhi", 1) < 150)
                return notify_fail("��Ļ���ָ����Ϊ���������ڻ��޷�ʩչ������ָ��\n");

        if (me->query_skill_mapped("finger") != "huanyin-zhi")
                return notify_fail("��û�м�������ָ�����޷�ʩչ������ָ��\n");

        if (me->query("neili") < 400)
                return notify_fail("������������������޷�ʩչ������ָ��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIG "$N" HIG "���������һ�����������Ĵ�"
              "��һָ��Ю��һ�ɺ�������$n" HIG "��\n" NOR;

        ap = ap_power(me, "finger");
        dp = dp_power(target, "force");
        
        if (ap / 2 + random(ap) > dp)
        {
                damage = da_power(me, "finger");
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 40,
                                           HIG "$p" HIG "��æ���ˣ�Ȼ����ָ�ε������"
                                           "�õ���$p" HIG "��ǰ��$p" HIG "��������һ����"
                                           "ս��\n" NOR);
                target->affect_by("huanyin_poison",
                                  ([ "level" : ap / 5 + random(ap / 5),
                                     "id"    : me->query("id"),
                                     "duration" : ap / 40 + random(ap / 18) ]));
                me->add("neili", -320);
                me->start_busy(2);
        } else
        {
                msg += CYN "����$p" CYN "�����������������ڹ�"
                       "��������һָ������������\n" NOR;
                me->start_busy(4);
                me->add("neili", -80);
        }
        message_combatd(msg, me, target);
        me->want_kill(target);
        if (! target->is_killing(me)) target->kill_ob(me);
        return 1;
}

