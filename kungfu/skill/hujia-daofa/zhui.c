#include <ansi.h>
#include <combat.h>

#define ZHUI "��" HIR "ж��׶����" NOR "��"

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;
        int ap, dp;

        if (userp(me) && ! me->query("can_perform/hujia-daofa/zhui"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ" ZHUI "��\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHUI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" ZHUI "��\n");

        if ((int)me->query_skill("force") < 200)
                return notify_fail("����ڹ���򲻹�������ʩչ" ZHUI "��\n");

        if ((int)me->query_skill("hujia-daofa", 1) < 140)
                return notify_fail("��ĺ��ҵ����������ң�����ʩչ" ZHUI "��\n");

        if (me->query_skill_mapped("blade") != "hujia-daofa")
                return notify_fail("��û�м������ҵ���������ʩչ" ZHUI "��\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("�����������������ʩչ" ZHUI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIR "$N" HIR "���е�" + weapon->name() +  HIR "һ��ʩ����ж"
              "��׶���ơ�����ʱһ�������ޱȵ����ε����ƿ�Ϯ��$n" HIR "��\n"NOR;

        ap = ap_power(me, "blade");
        dp = dp_power(target, "parry");
             
        if (ap / 2 + random(ap) > dp)
        {
                damage = da_power(me, "blade");
                me->add("neili", -150);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 65,
                                           HIR "ֻ��$n" HIR "һ���ҽУ�����������"
                                           "������������ģ�������Ѫ���������\n" NOR);
                me->start_busy(2);
        } else 
        {
                msg += CYN "����$p" CYN "Ĭ��������Ӳ�ǵֵ���$P"
                       CYN "��������ε�����\n"NOR;
                me->add("neili", -50);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}

