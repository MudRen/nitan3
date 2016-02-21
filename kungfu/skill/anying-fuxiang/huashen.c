// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int i;
        
        if (! me->is_fighting())
                return notify_fail("��ֻ����ս����ʹ�����컯����\n");

        if ((int)me->query_skill("linji-zhuang", 1) < 100)
                return notify_fail("����ټ�ʮ��ׯ���������ʹ�������컯����\n");  

        if ((int)me->query_skill("anying-fuxiang", 1) < 100)
                return notify_fail("��İ�Ӱ���㻹�������ʹ�������컯����\n");  

        if ((int)me->query("jing", 1) < 500)
                return notify_fail("�����ھ�������\n");

        if ((int)me->query("neili", 1) < 500)
                return notify_fail("����������������\n");

        if (me->query_temp("emei/parry"))
                return notify_fail("������ʹ�����컯����\n");

        msg = HBYEL "$Nʹ����Ӱ��������컯�������ֵ�ʱ�������ɣ�\n\n" NOR; 

        me->add("neili", -200 + random(100));
        me->recieve_damage("jing", 50);
        
        message_combatd(msg, me);
        
        i = me->query_skill("linji-zhuang", 1) / 5;
        
        me->add_temp("apply/dex", i);
        me->add_temp("apply/con", i);
        me->set_temp("emei/parry", i);
        
        remove_call_out("remove_effect");
        call_out("remove_effect", 1, me, (int)me->query_skill("force") / 3);
        return 1;
}

void remove_effect(object me, int count)
{
        int i;
        
        if (! me) return;
        if (! me->is_fighting()
        ||  me->query_skill_mapped("dodge") != "anying-fuxiang" 
        ||  count < 1)
        {
                i = me->query_temp("emei/parry");
                me->add_temp("apply/dex", - i);
                me->add_temp("apply/con", - i);
                me->delete_temp("emei/parry");
                tell_object(me, HIW "��ֹͣ�����컯������������˿�����\n" NOR);
                return;
       }
       call_out("remove_effect", 1 ,me ,count -1);
}

