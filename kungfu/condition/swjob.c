// swjob.c

#include <ansi.h>
#include <condition.h> 

int update_condition(object me, int duration)
{
        if (duration < 1 && me->query_temp("defend_quest")) 
	{
		tell_object(me, HIY "��������������������\n" NOR);
                me->set_temp("defend_quest/finish", 1);
		return 0;
	}
	if (! duration) return 0;
	me->apply_condition("swjob", duration - 1);
	return 1;
}

string query_type(object me)
{
	return "job";
}
