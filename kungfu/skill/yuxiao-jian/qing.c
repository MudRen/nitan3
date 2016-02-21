// qing.c ����鳤

#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp;
        int cost;

        if (! me->query("can_perform/yuxiao-jian/qing"))
                return notify_fail("�㻹����ʹ�á�����鳤����һ������\n");

        if (! target)
        {
	        me->clean_up_enemy();
	        target = me->select_opponent();
        }

	if (! target || ! me->is_fighting(target))
                return notify_fail("������鳤��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if (target->query("neili") < 300)
                return notify_fail("����ȥ�Է��������ڲ������棬���������á�����鳤����\n");

        skill = me->query_skill("yuxiao-jian",1);

        if (skill < 120)
                return notify_fail("������｣���ȼ�����, ����ʹ�á�����鳤����\n");

        if (me->query("neili") < 1000)
                return notify_fail("��������������������á�����鳤����\n");

        msg = HIC "$N" HIC "���е�" + weapon->name() +
              HIC "ٿ�Ĵ̳�������һ������������ס������������\n" NOR;
        message_combatd(msg, me, target);

        ap = me->query_skill("sword") + me->query_skill("force") +
             me->query_skill("chuixiao-jiafa", 1);
        dp = target->query_skill("force") * 2;
        if (ap > dp && ap / 2 + random(ap) > dp)
        {
                me->add("neili", -500);
                msg = HIM "$p" HIM "����$P" HIM "������������һ��������"
                      "�У�����׽��ȥ����ֻ��ǿ������������\n" NOR;
                cost = 500 + (ap - dp) * 3 / 2;
                if (cost > target->query("neili"))
                        cost = target->query("neili");
                target->add("neili", -cost);
                me->start_busy(1 + random(3));
        } else
        {
                me->add("neili", -120);
                msg = HIG "����$p" HIG "���񰲶���û���յ���������\n"NOR;
                me->start_busy(2);
        }
        message_combatd(msg, me, target);
        return 1;
}
