// lingbo.c  �����貨

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
	int level;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("��һ��������ô��\n");

        if ((level = me->query_skill("lingbo-weibu", 1)) < 120)
                return notify_fail(HIY "����貨΢��������������\n" NOR);

        if ((int)me->query("neili") < 400)
                return notify_fail(HIY "�������������㡣\n" HIY);

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");

        if( me->query("gender") == "Ů��")
               msg = HIC "$N" HIC "�����������������������ʮ"
                     "���ԣ�����$n" HIC "��γ��У��Թ��ԵĽ�"
                     "\n�貨΢����ͷ��βѸ���ޱȵ�����һ�Ρ�$N"
                     HIC "��������������΢���貨��\n$n" HIC
                     "ȴ��һ��ƤëҲմ���ϡ�$N" HIC
                     "�������ң���ַ��ӵ����쾡����\n" NOR;
        else   msg = HIG "$N" HIG "�����������������������ʮ"
                     "���ԣ�����$n" HIG "��γ��У��Թ��ԵĽ�"
                     "\n�貨΢����ͷ��βѸ���ޱȵ�����һ�Ρ�"
                     "ֻ��$N" HIG "��̬Ʈ�ݣ�Ӱ���ҷɣ�\n$n" HIG
                     "ȴ��һ��ƤëҲմ���ϡ�$N" HIG "�������"
                     "ң���ַ��ӵ����쾡����\n" NOR;

        if (random(level) > (int)target->query_skill("dodge", 1) / 2)
        {
                msg += HIW "���$p��$PΧ��ת��ͷ���ۻ���\n" NOR;
                target->start_busy(level / 16);
                me->add("neili", -100);
                me->start_busy(1);
        } else
        {
                msg += HIY "$p" HIY "ֻ����ǿ�����˿�ȥ��\n" NOR;
                me->add("neili", -50);
                me->start_busy(2);
        }
        message_combatd(msg, me, target);

        return 1;
}
