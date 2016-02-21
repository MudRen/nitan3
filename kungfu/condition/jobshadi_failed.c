// dart_limit.c

#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        if (duration < 1) return 0;
        me->apply_condition("jobshadi_failed", duration - 1);

        if (duration == 1 && me->query_temp("guo_shoucheng/failed"))
        {
                message_vision(CYN "\nһ���α��ܹ�����$N˵�����ɹ������ֿ�ʼ�����ˣ�Ԫ˧��������ǰȥ������\n" NOR, me);
                me->delete_temp("guo_shoucheng/failed");
                me->apply_condition("jobshadi_failed", 0);
                return 0;
        }

        return CND_CONTINUE;      
}

