// ruyi.c ��������

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon;
        string msg;
        int i, ap, dp, level, damage;
 
        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail("���������⡹ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
        if (!objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "blade")
                return notify_fail("����û�У�ʹʲô���������⡹��\n");

        if ((int)me->query("neili") < 300)
                return notify_fail("�������������\n");

        if ((int)me->query_skill("xiaowuxiang", 1) < 100
                && (int)me->query_skill("lingjiu-xinfa", 1) < 100
                && (int)me->query_skill("xiaoyao-xinfa", 1) < 100
                && (int)me->query_skill("bahuang-gong", 1) < 100
                && (int)me->query_skill("beiming-shengong", 1) < 100)
                return notify_fail("��������ڹ��ķ�����ȷ�����߹�������������ʹ���������⣡\n");

        if ( me->query_skill_mapped("force") != "xiaowuxiang"
                && me->query_skill_mapped("force") != "bahuang-gong"
                && me->query_skill_mapped("force") != "lingjiu-xinfa"
                && me->query_skill_mapped("force") != "xiaoyao-xinfa"
                && me->query_skill_mapped("force") != "beiming-shengong")
                return notify_fail("��û��������ң��ϵ���ڹ���\n");     

        if (me->query_skill("blade") < 100)
                return notify_fail("������⵶���������ң��޷�ʹ�á��������⡹��\n");

        if (me->query_skill_mapped("blade") != "ruyi-dao")
                return notify_fail("��û�м������⵶�����޷�ʹ�á��������⡹��\n");

        msg = HIC "$N" HIC "����Ц�����ֻӳ�" + weapon->query("name") + HIC "��ֻ��������ת�������ݺ��޿ײ��磬ֱ��$n�������ֽ�ȥ��\n" NOR;
        message_combatd(msg, me, target);

        level = me->query_skill("blade");
        ap = level + me->query_skill("force");
        dp = target->query_skill("parry") + target->query_skill("force");
        if (ap/2 + random(ap) > dp || !living(target))
        {
                me->add("neili", -level);
                damage = me->query_skill("ruyi-dao",1) + me->query("jiali") + me->query_str()*10;
                if (me->query_skill_mapped("force") == "xiaowuxiang") damage += me->query_skill("xiaowuxiang",1);
                if (me->query_skill_mapped("force") == "beiming-shengong" && target->query("neili") > me->query_skill("force") * 2)
                        target->add("neili",-100);
                damage += random(damage);
                msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 50,
                        HIR "$p" HIR "�ۼ��ŵ����й����ȴ�����޴룬�����$P"
                        HIR "һ�������ؿڣ��ƺ�һ������Ѫ�ɽ�������\n" NOR);
                me->start_busy(2);
                target->start_busy(1+random(2));
        }
        else
        {
                msg = HIY "$p" HIY "�ۼ��ŵ����й��������æ��͵�һ�����������ܿ���$P"
                      HIY "�����������⣡\n" NOR;
                me->start_busy(3 + random(3));
        }
        message_combatd(msg, me, target);
        return 1;
}

