// winfo.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string str;

        seteuid(getuid());

        if (! SECURITY_D->valid_grant(me, "(arch)"))
                return 0;

        str = WORK_D->query_all_work();
        me->start_more(str);

        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : qinfo [<��������>]

��ָ��ɲ鿴��ǰϵͳ�е�����
HELP );
        return 1;
}
