// lingbo.c  �����貨
// by Lonely


#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int ap, dp;

        if (! target) target = offensive_target(me);

        if (! target || ! target->is_character() || ! me->is_fighting(target))
                return notify_fail("��һ��������ô��\n");

        if (me->query("gender") == "����")
                return notify_fail(HIY "һ��������������������Ҳ���ߣ�\n" NOR);

        if ((int)me->query_skill("beiming-shengong", 1) < 100)
                return notify_fail(HIY "��ı�ڤ����Ϊ������\n" NOR);

        if ((int)me->query_skill("lingboweibu", 1) < 100)
                return notify_fail(HIY "����貨΢������������\n" NOR);

        if ((int)me->query("neili") < 400)
                return notify_fail(HIY "�������������㡣\n" HIY);

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");

        if (me->query("gender") == "����")
        {
                msg = HIC "$N�����������������������ʮ���ԣ�����$n��γ��У��Թ��ԵĽ�"
                      "�貨΢����ͷ��βѸ���ޱȵ�����һ�Ρ�\nֻ��$N��̬Ʈ�ݣ�Ӱ���ҷɣ�"
                      "$nȴ��һ��ƤëҲմ���ϡ�$N�������ң���ַ��ӵ����쾡����\n" NOR;
        }
        else  
        {
                msg = HIG "$N�����������������������ʮ���ԣ�����$n��γ��У��Թ��ԵĽ�"
                      "�貨΢����ͷ��βѸ���ޱȵ�����һ�Ρ�\n$N��������������΢���貨��"
                      "$nȴ��һ��ƤëҲմ���ϡ�$N�������ң���ַ��ӵ����쾡����\n" NOR;
        }
        
        ap = me->query_skill("lingboweibu", 1) * 3 / 2 + me->query("level") * 20 + 
             me->query_skill("martial-cognize", 1);
        dp = target->query_skill("dodge") + target->query("level") * 20 + 
             target->query_skill("martial-cognize", 1);
                   
        if (ap / 2 + random(ap) > dp)
        {
                msg += HIW "$N���������·���$n������$N���貽ת�˸�ͷ���ۻ�\n" NOR;
                target->start_busy( (int)me->query_skill("lingboweibu",1) / 30);
                me->add("neili", -100);
                // me->start_busy(1);
        } else 
        {
                msg += HIG "����$n������$N���貽,��̬���ݵĶ��˹�ȥ\n" NOR;
                me->add("neili", -100);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}

