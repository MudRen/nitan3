// lian.c ���־�

#include <ansi.h>

#define PFM_NAME        "���־�"

inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon;
        string msg;
        int i;
        int time;
        int count;
        int skill;

        if (userp(me) && ! me->query("can_perform/taiji-jian/lian"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ��" PFM_NAME "����\n");
                        
        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail("��" + PFM_NAME + "��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("�����ý�����ʩչ��" + PFM_NAME + "����\n");

        if ((int)me->query("neili") < 1000)
                return notify_fail("��������������޷�ʩչ��" + PFM_NAME + "����\n");

        if ((int)me->query_skill("taiji-shengong", 1) < 200)
                return notify_fail("���̫���񹦻�򲻹�������ʩչ��" + PFM_NAME + "����\n");

        if ((int)me->query_skill("taiji-jian", 1) < 200)
                return notify_fail("���̫�����������ң��޷�ʹ�á�" + PFM_NAME + "����\n");

        time = me->query_skill("taiji-jian") / 20;
        if (time > 10) time = 10;
        if (time < 1) time = 1;

        msg = HIC "$N" HIC "һ����Х����̨�����������Ԫ��ʹ��̫�����еġ�" + PFM_NAME + "����\n"
              HIY "����" + weapon->name() + HIY "��ʽ��Ȼ��������ޱȣ�һת��"
              HIY "����Ȼ����" + chinese_number(time) + "�У�\n" NOR;

        message_combatd(msg, me, target);
        skill = me->query_skill("taiji-jian", 1) / 5;
        me->add("apply/attack", skill);
        me->add("neili", -(time * 100));

        for (i = 0; i < (time); i++)
        {
                if (! me->is_fighting(target))
                        break;
                COMBAT_D->do_attack(me, target, weapon, 0);
        }

        me->add("apply/attack", -skill);
        me->start_busy(time / 2 + random(time / 2));
        return 1;
}

