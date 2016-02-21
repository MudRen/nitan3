// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// zhen.c һ������

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        int ap, dp, damage;
        string msg, pmsg;
        
        if (! target)
                target = offensive_target(me);

        if (userp(me) && ! me->query("can_perform/liuyang-zhang/zhen"))
                return notify_fail("��һ�С�һ�����졹δ����ɽͯ�ѵ�ָ�㣬���޷��˽��˹������š�\n");
                
        if (! target || ! target->is_character() 
        ||  ! me->is_fighting(target))
                return notify_fail("��һ�����졹ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon"))
                return notify_fail("�������ֲ���ʹ�á�һ�����졹֮����\n");

        if (me->query_skill("liuyang-zhang", 1) < 200)
                return notify_fail("�����ɽ�����Ʋ�����죬�޷�ʹ�á�һ�����졹֮����\n");

        if (me->query_skill("strike", 1) < 180)
                return notify_fail("��Ļ����Ʒ�������죬�޷�ʹ�á�һ�����졹֮����\n");

        if (me->query_skill("force", 1) < 220)
                return notify_fail("��Ļ����ڹ���Ϊ���㣬�޷�ʹ�á�һ�����졹֮����\n");

        if (me->query_skill("bahuang-gong", 1) < 240)
                return notify_fail("��İ˻�����Ω�Ҷ�����Ϊ���㣬�޷�ʹ�á�һ�����졹֮����\n");

        if (me->query_str() < 38)
                return notify_fail("��ĺ����������㣬�޷�ʹ�á�һ�����졹֮����\n");

        if (me->query_str() < 38)
                return notify_fail("��ĺ�����ǲ��㣬�޷�ʹ�á�һ�����졹֮����\n");

        if (me->query("neili", 1) < 2000)
                return notify_fail("�������������㣬����ʹ�á�һ�����졹��\n");

        if (me->query("max_neili", 1) < 4000)
                return notify_fail("������������Ϊ���㣬����ʹ�á�һ�����졹��\n");

        if (me->query("jiali") < 50)
                return notify_fail("�������ôС����ô��ʩչ��һ�����졹�أ�\n");


        msg = WHT" \nֻ��$N" WHT "��Ȼ��Ե�����������֮ɫ��˿˿����������䣬ת˲���ѽ�$P�����ư���������\n" +
             "���ô�ʱ��$n" WHT "�Ѿ������֪�������㣬$N" WHT "���С�" HIY "һ������" WHT "����Ȼ������ǰ��������\n" +
             "������$pֻ�����ܵĿ����·��Ѿ����ᣬ��һ��֮���ѽ���������ǰ�����������ʵ����\n"+
             "�԰��ѡ�˲��Ŀ�������ֱ��һ����մ󶴣�ʹ�����ܵ��˾�����һ�����ͣ�\n\n"NOR;

        ap = ap_power(me, "strike") + me->query("con") * 20; 
        dp = dp_power(target, "force") + target->query("con") * 20; 
             
        if (ap / 2 + random(ap) > dp)
        {
                damage = da_power(me, "strike");
                me->add("neili", -500);

                pmsg = HIR "$n" HIR "�ۼ�$N" HIR "һ���������ƾ���飬�������ȣ�Ȼ��������������֮�У����޿ɱܣ�ֻ��\n" +
                       "��΢Ų���Ų�Ҳ������֮���������$N" HIR "һ��ӡ����ǰ���Ǹ�һ��ʹ����裬ȴ���߹Ǳ�\n" +
                       "��һ��֮����ϣ���Ѫ��ӿ��Ȼʧ�أ�һ����Ѫ�����ӿڱ������˳�����\n\n" NOR;
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 65, pmsg);
                
                me->start_busy(3);      
        } else
        {
                msg += HIG "����$n" HIG "�����쳣��һ�۵���$N" HIG "���е�����֮���������е����ģ���伫Ϊ����������\n"+
                       "���ֳ�ָ��������$N" HIG "���������ϣ�������ָ����$P���ĵ�" HIR "�ٸ�"
                       HIG "��" HIR "�͹�" HIG "��Ѩ�����$N" HIG "Ѩ����\n" +
                      "�⣬�������޴���й������ʴ�������$P�����ֽ���ڴ����࣬����������ˣ�\n\n" NOR;

                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}

