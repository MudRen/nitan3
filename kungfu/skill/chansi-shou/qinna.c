#include <ansi.h>
#include <combat.h>
 
inherit F_SSERVER;
#include <balance.h>

int perform(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp, damage;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail("��˿������ֻ����ս���жԶ���ʹ�á�\n");

        skill = me->query_skill("chansi-shou", 1);

        if (skill < 120)
                return notify_fail("��Ĳ�˿�����ֵȼ�����������ʹ�þ�����\n");

        if (me->query("neili") < 100)
                return notify_fail("��������������޷����þ�����\n");
 
        if (me->query_skill_mapped("hand") != "chansi-shou") 
                return notify_fail("��û�м�����˿�����֣��޷�ʹ�þ�����\n");

        msg = HIC "$N" HIC "��Ȼ����$n" HIC "����Ȼʹ����˿�����֣�ֻ��$P"
              "˫�ֺ��ۺ�Ť����ץ��˦��ֱ��$n" HIC "����Ҫ����\n" NOR;
 
        ap = ap_power(me, "hand");
        dp = dp_power(target, "parry");
        if (ap / 2 + random(ap) > dp)
        {
                me->add("neili", -80);
                damage = da_power(me, "hand");
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 30,
                                           HIR "$p" HIR "�����ֿ����վ�����$P"
                                           HIR "���������к��Ǳ�ѹ�Ƶ��޷�"
                                           "������\n" NOR);
                me->start_busy(1);
                if (ap / 3 + random(ap) > dp && ! target->is_busy())
                        target->start_busy(ap / 25 + 2);
        } else
        {
                msg += CYN "����$p" CYN "�Ŀ�����$P" CYN
                       "����ʽ�������һһ��⣬û¶���������\n" NOR;
                me->add("neili",-20);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}

