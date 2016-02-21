// feilong.c ��ɽ���������������

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;
        int ap, dp;

        if (userp(me) && ! me->query("can_perform/huashan-sword/feilong"))
                return notify_fail("�㲻��ʹ�����������\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("�����������ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("���ý���ôʹ�á������������\n");

        if ((int)me->query_skill("huashan-sword", 1) < 150 )
                return notify_fail("�㻪ɽ����������죬ʹ�����������������\n");

        if ((int)me->query_skill("force") < 150 )
                return notify_fail("���ڹ���򲻹���ʹ�����������������\n");

        if ((int)me->query("neili") < 400)
                return notify_fail(HIC"�����������������޷��������������ʹ�꣡\n"NOR);

        if (me->query_skill_mapped("sword") != "huashan-sword")
                return notify_fail("��û�м�����ɽ�������޷�ʹ�á������������\n");

        msg = HIC "$N" HIC "���������һ�������������̽����˾��ڱۣ���"
              "��һ����$n" HIC "���˳�ȥ��\n" NOR;

        ap = me->query("combat_exp");
        dp = target->query("combat_exp");
        if (ap > dp / 2 * 3 && ap / 2 + random(ap) > dp)
        {
                me->start_busy(3);
                damage = target->query("max_qi");
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 30,
                                           HIC "$n��æԾ�𣬵����������ֻ��һ���ʹ������"
                                           "������������Ѫ�ɽ���Ƥ�����\n" NOR);
                me->add("neili", -400);
        } else
        {
                me->start_busy(3);
                msg += CYN "Ȼ��$n" CYN "����һЦ��������ָ������"
                       "��$N" CYN "�Ľ����ϣ���б����ء�\n" NOR;
                me->add("neili", -400);
        }

        weapon->move(environment(me));
        message_combatd(msg, me, target);
        return 1;
}
