// cline.c ���ĩβ����

#include <ansi.h>
#include <command.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int n;
        string msg;

        if (! stringp(arg) || ! sscanf(arg, "%d", n))
                n = 24;

        if (n < 1 || n > 500)
        {
                write("��������\n");
                return 1;
        }

        msg = "";
        while (n--)
                msg += ESC "[1A" ESC "[K";

        write(msg);
	return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : cline [<����>]

��ָ������������������֣���ʲô�ã��Լ���ɡ�
HELP );
        return 1;
}
