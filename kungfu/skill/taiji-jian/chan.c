// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// chan.c ���־�

#include <ansi.h>

#define PFM_NAME        "���־�"

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;

        if (userp(me) && ! me->query("can_perform/taiji-jian/chan"))
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

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

        if (me->query("neili") < (int)me->query("max_neili") / 50)
                return notify_fail("�������������ʩչ��" + PFM_NAME + "����\n");

        if ((int)me->query_skill("taiji-shengong", 1) < 100)
                return notify_fail("���̫���񹦻�򲻹�������ʩչ��" + PFM_NAME + "����\n");

        if (me->query_skill("taiji-jian", 1) < 100)
                return notify_fail("���̫������������죬����ʹ�á�" + PFM_NAME + "����\n");

        msg = HIG "$Nʹ��̫�������������־���������������������ͼ����$n�Ĺ��ơ�\n"
              HIG "��Ȼ����" + weapon->name() + HIG "����һ����ԲȦ�����ڽ��ȣ�"
              HIG "���಻��������������һ�Ŵ���������$n�ս���\n" NOR;

        ap = ap_power(me, "sword");
        dp = dp_power(target, "parry");
             
        if (ap * 2 / 3 + random(ap ) > dp)
        {
                me->add("neili",-me->query("max_neili") / 50);
                msg += HIC "\n���̫������ɢ������ϸ˿Խ��Խ�࣬���ǻ�����һ����˿�ޣ���$p��������������\n" NOR;
                target->start_busy(2 + ap / 80);
                me->start_busy(1);
        } else
        {
                me->add("neili",-me->query("max_neili") / 80);
                msg += HIY "\n����$p������$P����ͼ������һԾ�����ӳ�Ȧ�⡣\n" NOR;
                me->start_busy(1 + random(3));
        }
        message_combatd(msg, me, target);

        return 1;
}

int help(object me)
{
        write(WHT"\n̫���������־�����"NOR"\n");
        write(@HELP
        ̫������Բת���ϣ����಻�����ٵ���֮������Ԧ����ʹ���������־�ÿ��
        һ�У����Ʒų�һ��ϸ˿����ס���֣�ǧ���򻯣������޾���ʹ���޷�������
        ���ҿ����Զ���������������ֱ�����ܶ��֡�
        
        Ҫ��  ������� 1000 ���ϣ�      
                ���� 500 ���ϣ� 
                ̫�����ȼ� 100 ���ϣ�
                ����̫����Ϊ�мܣ�
                ��δ���ƴ򲻻��֡�     
HELP
        );
        return 1;
}
