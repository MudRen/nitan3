// time.c                                          
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int cur_time = time();  

        if (! wizardp(me) && cur_time - me->query_temp("last_who") < 5) 
                return notify_fail("ϵͳ�������̾���������� ....\n");  

        me->set_temp("last_who", cur_time);    
        if (! objectp(WAR_D->query_marshal()))
                return notify_fail("����ǰ��û��ս�£�\n"); 

        write(sprintf("����ս���Ѿ�������" + WAR_D->query_continue_time() + "��\n"));
	return 1;
}

int help(object me)
{
     write(@HELP
ָ���ʽ: time

���ָ�����������ս���Ѿ����е�ʱ�䡣

HELP
    );
    return 1;
}
