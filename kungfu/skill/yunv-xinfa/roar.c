// roar.c һЦ���
// by Lonely

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        object *ob;
        int i, skill, damage;

        if ((int)me->query("neili") < 100)
                return notify_fail("�������������\n");
                
        if (environment(me)->query("no_fight")) 
                return notify_fail("���ﲻ�ܹ�������! \n"); 

        skill = me->query_skill("force", 1);

        me->add("neili", -100);
        me->receive_damage("qi", 10);

        me->start_busy(3);
        message_combatd(
                HIG "$N�س���������һ����ȻһЦ��"HIM"$N"HIG"�������䣬�����˶�Ϊ֮һ��,��ʱȫ��������Ȼ��\n" NOR, me);
        ob = all_inventory(environment(me));
        
        for (i = 0; i < sizeof(ob); i++) 
        {
                if (! ob[i]->is_character() || ob[i] == me) 
                        continue;
                        
                if (! living(ob[i]) || wizardp(ob[i]) ||  
                    (ob[i]->query("age") < 17 && userp(ob[i]))) 
                        continue; 

                if (skill/2 + random(skill/2) < (int)ob[i]->query_skill("force", 1))
                        continue;
                
                me->want_kill(ob[i]); 
                me->fight_ob(ob[i]); 
                ob[i]->kill_ob(me); 

                damage = skill - ((int)ob[i]->query("max_neili") / 15);
                if (damage > 0)
                {
                        ob[i]->set("last_damage_from", me);    
                        ob[i]->receive_damage("jing", damage * 2, me);
                        if ((int)ob[i]->query("neili") < skill * 2)
                                ob[i]->receive_wound("jing", damage, me);
                        tell_object(ob[i], HIY "��ֻ������ǰһƬģ�����������ƺ�����������Ů�ڶ��������Ц,�����ɾ���\n" NOR);
                }
        }
        return 1;
}
