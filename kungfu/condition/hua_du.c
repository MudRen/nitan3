// by Lonely

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{   
        if (duration == 1)
        {
                tell_object(me, HIR "��һ����û�м������������ڶ����Ѿ���ʼ�������ܿ��ƣ�\n" NOR );
                message("vision", me->name() +"������һ����ɫ��ɢ����ɫ��ʼ���ࡣ\n", environment(me), me);
                me->apply_condition("hua_poison", 80 + me->query_skill("huagong-dafa", 1));
        }
        me->apply_condition("hua_du", duration - 1);

        if (duration < 1) return 0;
        return CND_CONTINUE;
}

