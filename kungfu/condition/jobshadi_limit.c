#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
        object room;
        object obb;
        object* inv;
        int i;

        if (duration < 1) return 0;  
        
        me->apply_condition("jobshadi_limit", duration - 1);  

        room = environment(me);     
        if (me->query_temp("guo_shoucheng/where")) 
        if (me->query_temp("guo_shoucheng/where") != room 
        &&  ! me->query_temp("guo_shoucheng/job_over")) 
        {
                message_vision(HIY "һ���α��ܹ�����$N˵���������سǣ���ȴ�����й䣬��ȥ��������ˣ�\n" NOR, me);
                me->set_temp("guo_shoucheng/failed", 1);
                me->apply_condition("jobshadi_limit", 0);  
        }

        if (me->query_temp("guo_shoucheng/start_job")
        &&  me->query_temp("guo_shoucheng/where") == room)
         message_vision(HIY"$N��վ�ڳ�ǽ������ע���ų���"HIR"�ɹű�"HIY"��һ��һ����\n"NOR,me);

        if (me->is_ghost())
        {
                me->delete_temp("guo_shoucheng");
                me->apply_condition("jobshadi_limit", 0);
                return 0;
        }

        if (duration == 1 && me->query_temp("guo_shoucheng/where") == room)
        {
                message_vision(HIW "��ʱ���ɹž�Ӫ��������ս�����������ǵ��ɹŴ����Ȼ��ʼ�����ˣ�\n" NOR, me);   

                message_vision(CYN "\nһ���س��α��ܹ���˵�����ɹ�������ʱ�������ˣ�$N���Ի�ȥ�����ˣ�\n" NOR, me);
                if (me->query_temp("guo_shoucheng/start_job")) 
                        me->set_temp("guo_shoucheng/job_over", 1);
                me->delete_temp("guo_shoucheng/start_job");
                inv = all_inventory(room);
        
                for (i = 0; i < sizeof(inv); i++) 
                {
                        obb = inv[i];

                        if (obb->is_character() && ! userp(obb) && obb->query("is_guojob")
                        &&  obb->query("want_kill") == me)
                                destruct(obb);
                        else continue;  
                }
                me->apply_condition("jobshadi_limit", 0);     
        }
        return CND_CONTINUE;      
}

