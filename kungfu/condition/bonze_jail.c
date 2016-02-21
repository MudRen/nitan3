// bonze_jail.c

#include <ansi.h>
#include <login.h>

int move_out(object me);
int update_condition(object me, int duration)
{
	if (duration < 1)
        {
                remove_call_out("move_out");
                if (! me->is_ghost())
                call_out("move_out", 1, me);
		message("vision",
			HIY "ֻ��ƹ��һ����������һ��������һ����\n"
			"ԭ����һ���������ļһ�Ӵ����ﱻ���˳�����\n" NOR, environment(me), me);
		tell_object(me, HIY "ֻ��һ�����Ƽ���㣬��������ر��ӳ��������£�\n" NOR);
		me->set("startroom", START_ROOM);
                return 0;
	}

	me->apply_condition("bonze_jail", duration - 1);
	return 1;
}

int move_out(object me)
{
        me->move("/d/shaolin/guangchang1");
        return 1;
}
