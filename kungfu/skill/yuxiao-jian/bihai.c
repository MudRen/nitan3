#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int ap, dp, lvl;
        int jing, skill;
        object ob;

        if (! objectp(ob = me->query_temp("handing")) ||
            ! ob->valid_as_xiao())
                return notify_fail("������û���������޷�ʹ��������У�\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(HIW "�̺�����������" NOR
                                   "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        skill = me->query_skill("yuxiao-jian", 1);

        if (skill < 150)
                return notify_fail("������｣���ȼ�����, ����ʹ��"
                                   HIW "�̺�����������" NOR "��\n");

        if (me->query("neili") < 300)
                return notify_fail("��������������޷�����"
                                   HIW "�̺�����������" NOR "��\n");

        ap = me->query_skill("yuxiao-jian", 1) +
             me->query_skill("sword");
        dp = target->query_skill("force");

        lvl = (int) me->query_skill("yuxiao-jian", 1) / 5 + 1;

        msg = HIC "$N" HIC "�ְ������̤���Է�λ�����" NOR
              HIW "��" NOR+HIC "�̺�����������" NOR+HIW "��" NOR
              HIC "............\n" NOR;
        msg += HIW "\nֻ���������٣�����񣬷��˼�������������"
                   "���Ʈ��һ��������͵Ķ���������\n" NOR;

        if (dp < random(ap * 2))
        {
                msg += HIR "$n" HIR "��ͷһ�������ϲ��Խ���¶��΢Ц��\n" NOR;
                jing = (int) target->query("max_jing");
                target->receive_damage("jing", jing * lvl / 300, me);
                target->receive_wound("jing", jing * lvl / 500, me);
                message_combatd(msg, me, target);
        } else
        {
                msg += HIY "$n" HIY "����������һ��������������Ӧ��ԣ�磡\n" NOR;
                message_vision(msg, me, target);
        }

        msg = HIW "�Ƕ���������Ʈ����������ת������һ��Ů��һ��"
                  "��̾Ϣ��һ���������һ����������´��\n"
                  "�����л���\n" NOR;

        if (dp < random(ap))
        {
                msg+= HIR "$nֻ��ȫ����Ѫ���ڣ���ֻ�������㵸���Ҷ�һ����\n"NOR;
                jing = (int) target->query("max_jing");
                target->receive_damage("jing", jing * lvl / 100, me);
                target->receive_wound("jing", jing * lvl / 240, me);
                message_combatd(msg, me, target);
        } else
        {
                msg += HIY "$n" HIY "����������һ��������������Ӧ��ԣ�磡\n"NOR;
                message_vision(msg, me, target);
        }

        msg = HIW  "��������������󺣺��������޲���Զ����ˮ�����ƽ����������죬��������ӿ��������\n"
                   "ɽ������ˮ����Ծ�����������Ϸ�ХŸ�ɣ��ټ���ˮ�����֣�ȺħŪ����������ɽƮ��������\n"
                   "�Ⱥ���У��������֮���¡�\n" NOR;

        if (dp < random(ap / 2))
        {
                msg+= HIR "$n" HIR "ֻ����ͷ���ȣ�������\n" NOR;
                jing = (int) target->query("max_jing");
                target->receive_damage("jing", jing * lvl / 50, me);
                target->receive_wound("jing", jing * lvl / 120, me);
                message_combatd(msg, me, target);
        } else
        {
                msg += HIY "$n" HIY "����������һ��������������Ӧ��ԣ�磡\n" NOR;
                message_vision(msg, me, target);
        }

        msg = HIW "����������ϸ�������������ţ����糱�˺�ˮƽ��"
                  "��������ȴ���ǰ����ļ���\n" NOR;

        if (dp < random(ap / 4))
        {
                msg+= HIR "$n" HIR "��ʱ���ݾ�������Ҳ�޷�����\n" NOR;
                jing = (int) target->query("max_jing");
                target->receive_damage("jing", jing * lvl / 25, me);
                target->receive_wound("jing", jing * lvl / 50, me);
                me->start_busy(1 + random(2));
                me->add("neili", -200);
                message_combatd(msg, me, target);
                return 1;
        } else
        {
                msg+= HIY "$n" HIY "����������һ��������������Ӧ��ԣ�磡\n" NOR;
                me->start_busy(2 + random(3));
                me->add("neili", -200);
                message_vision(msg, me, target);
                return 1;
        }

        message_combatd(msg, me, target);

        return 1;
}

