#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{   
        int l_temp;
    
        me->set_temp("die_reason", "��Ԫ�ݽ�");
        if (random(4) >= 3)
        {
                if (! living(me))
                        message("vision", me->name() + "����һ����£��������[����]�졣\n", 
                                environment(me), me);
                else
                {
                        tell_object(me, HIB "���Ȼ�е����ھ�Ԫ��й��ͷ������ġ�\n" NOR );
                        message("vision", me->name() + "ͻȻ���ȷ������ֱ���һ�ţ����ֱ������\n",
                                environment(me), me);
                }
                
                l_temp = 50 - (int)me->query_skill("force", 1) / 20;
                if (l_temp < 10) l_temp = 10;
                me->add("jing", -l_temp);
                
                if ((int)me->query_skill("force", 1) < 180)
                { 
                        me->receive_wound("jing", random(1));
                } 
        }
        me->apply_condition("juehu_hurt", duration - 1);
        
        if (duration < 1) return 0;
        return CND_CONTINUE;
}

string query_type(object me)
{
        return "hurt";
}

