// need_energy.c

#include <condition.h>
#include <ansi.h>

int dispel() { return 0; }

int update_condition(object me, int duration)
{
        object ob;
        
        if (me->query("food") > 0 && me->query("water") > 0)
                return 0;

        if (! environment(me) ||
            environment(me)->is_chat_room())
                return CND_CONTINUE;

        if (duration == 4)
        {
                if (objectp(ob = find_player(me->query("owner"))))
                        tell_object(ob, HIR "���ħ����(" + me->query("name") + HIR + ")��Ҫ�����ˣ�\n" NOR); 
                        
                message_vision(HIY "$N" HIY "�������ּ��ֿʣ��Ѿ�ƣ��������\n" NOR, me);
        }
        else
        if (duration == 7)
        {
                if (objectp(ob = find_player(me->query("owner"))))
                        tell_object(ob, HIR "���ħ����(" + me->query("name") + HIR + ")��Ҫ�����ˣ�\n" NOR); 
                                        
                message_vision(HIY "$N" HIY "�������ּ��ֿʣ����������ı�Ե��\n" NOR, me);
        }
        else
        if (duration >= 21)
        {
                if (objectp(ob = find_player(me->query("owner"))))
                        tell_object(ob, HIY "���ħ����(" + me->query("name") + HIY + ")�Ѿ������ˣ�\n" NOR); 
                
                me->receive_damage("qi", 0);
                me->unconcious();
                return 0;
        } 
                                              
        me->apply_condition("need_energy", duration + 1);
        return CND_CONTINUE;
}

