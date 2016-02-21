// junquest_song
// Updated by Lonely

#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{      
        object room, jiang;  
        string temp;
        int liangcao;
        mapping jiangjun;

        room = environment(me);
 
        if (duration < 1) return 0;

        if (me != WAR_D->query_king())
        {
                me->apply_condition("junquest_song", 0);
                return 0;
        }

        if ((time() - me->query_temp("jun_quest/last_jiang")) > 500)
        {
                jiangjun = me->query_temp("jun_quest/jiang");

                temp = read_file("/d/city2/song/liangcao", 1, 1);
                liangcao = atoi(temp);
                if (! jiangjun || sizeof(jiangjun) < me->query("degree_jungong") * 2)         
                if (liangcao > 300 && objectp(room)
                && file_name(room) == "/d/city2/sying1")
                {
                        me->set_temp("jun_quest/last_jiang", time());
                        tell_object(me,
                                    HIR "����һ�����ξ����ˣ��Ͽ�ӽ�ѵ���ɣ�����\n" NOR); 
                        liangcao = liangcao - 50;
                        temp = sprintf("%d", liangcao);
                        write_file("/d/city2/song/liangcao", temp, 1);
                        jiang = new("/d/city2/song/songb");
                        jiang->move(room);
                        jiang->change_ob();
                }
        }

        if (duration == 1)  
        {
                WAR_D->remove_enemy();     
                tell_object(me, HIR "�ɹŴ���ù����£����ڳ����ˣ�����\n" NOR);
                tell_object(me, HIR "��ϲ��ʤ����ɴ˴γ������񣬻��������ɾ�ʵ���ҳ�֮������������\n" NOR);    
                WAR_D->give_bouns();
        }
        me->apply_condition("junquest_song", duration - 1); 

        return CND_CONTINUE;      
}


