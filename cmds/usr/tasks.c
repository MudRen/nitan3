 // task.c
//by xgchen@txwd 
#include <ansi.h>
int main(object me, string str)
{
        string output;

        if(me->is_busy())
        return notify_fail("��������æ��\n");

        if (! wizardp(me) && (time() - me->query_temp("last_tasks") < 5))
                return notify_fail("ϵͳ�������̾���������� ....\n");  

        if (me->query("jing") < 2)
                return notify_fail("�����ھ���״̬���ѣ����ǵȻ��ٲ�ɡ�\n");

        me->add("jing",-2);

        if (str && str == "count")
        {
                tell_object(me, "��Ŀǰ�Ѿ������ЧTASKʹ�� " + me->query("task/count") + " ����\n");
                return 1;
        }

    output = HIR"�� "HIW"��̶"HIR" ��"HIG" TASK���� ʹ����\n" NOR; 
    output += ""HIW"��������������������������������������������������������������������������\n"NOR"";   
        output += TASK_D->task_list();   
    output += ""HIW"��������������������������������������������������������������������������\n\n"NOR"";   

        me->start_more(output);
        me->set_temp("last_tasks", time());
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ: task
ָ���ʽ: task count �鿴�Լ��Ѿ����TASKʹ���ĸ�����
����ļ�: help tasks

���ָ����������֪Ŀǰ������ʹ��.

HELP
        );
        return 1;
}

