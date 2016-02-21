// dart_limit.c 
#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        if (duration < 1) return 0;
        me->apply_condition("guojob2_busy", duration - 1);

        if (duration == 1)
        {
                me->apply_condition("guojob2_busy", 0);     
                message_vision(CYN "\nһ���α��ܹ�����$N˵�����ɹ������ֿ�ʼ�����ˣ�Ԫ˧��������ǰȥ������\n" NOR, me);
        }

        return CND_CONTINUE;      
}

