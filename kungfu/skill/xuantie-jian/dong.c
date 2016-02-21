#include <ansi.h>
#include <combat.h>

#define DONG "��" HIG "�󽭶�ȥ" NOR "��"

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        object weapon;
        int damage;
        int ap, dp;
        string wp, msg;


        if (userp(me) && ! me->query("can_perform/xuantie-jian/dong"))
                return notify_fail("��δ�ø���ָ�㣬��֪�����ʩչ" DONG "��\n");
        
        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(DONG "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" DONG "��\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("����ڹ���򲻹�������ʩչ" DONG "��\n");

        wp = weapon->name();

        if ((int)me->query_skill("xuantie-jian", 1) < 200)
                return notify_fail("�����������������죬����ʩչ" DONG "��\n");

        if ((int)weapon->query_weight() < 25000)
                return notify_fail("�����е�" + wp + "��������������ʩչ" DONG "��\n");

        if ((int)me->query("neili") < 800)
                return notify_fail("�����ڵ��������㣬����ʩչ" DONG "��\n");

        if (me->query_skill_mapped("sword") != "xuantie-jian")
                return notify_fail("��û�м�����������������ʩչ" DONG "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "�������񣬶�ʱһ��������������ȱŷ������ŵ�"
              "��һ������" + wp + HIW "\n�漴��վ����������Χ��ɳ����"
              "����ʩ��������������" HIG "�󽭶�ȥ" HIW "����\n"NOR;

        me->start_busy(2);

        ap = ap_power(me, "sword") + me->query_str() * 2;
        dp = dp_power(target, "force") + target->query_str() * 2;

        if (me->query("character") == "��������" || me->query("character")=="������˫" )
                ap += ap / 5;
                
        if (ap / 2 + random(ap) > dp)
        {
                target->start_busy(1);
                damage = da_power(me, "sword");
                me->add("neili", -600);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 120,
                                           HIR "���$n" HIR "�����мܣ�ȴ��$N" HIR
                                           "��һ����ķ��𣬿�����Ѫ���²�ֹ��\n" NOR);
        } else
        {
                msg += CYN "����$n" CYN "������$N"
                       CYN "����ͼ����æбԾ�ܿ���\n"NOR;
                me->add("neili", -300);
        }
        message_combatd(msg, me, target);

        return 1;
}
