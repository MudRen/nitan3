#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string file,result;
        object ob;
        int a,b,x;
        if (! SECURITY_D->valid_grant(me, "(wizard)"))
                return 0;

        seteuid(geteuid(me));
        if (! arg) return notify_fail("ָ���ʽ : readfile <����>|<�����>,n1,n2  n1��ʾ��ʼ�У�n2��ʾ��ֹ�С�n1,n2û������moreָ��һ�����ٺ١�\n");
        if (sscanf(arg, "%s,%d,%d", arg, a, x) != 3)
                return notify_fail("������������n1,n2��\n");
	if ( a <= 0 || x < 0 || x - a < 0)
                return notify_fail("������˼�룬�����\n");
        file = resolve_path(me->query("cwd"), arg);
        if (file_size(file) < 0)
        {
                ob = present(arg, me);
                if (! ob) ob = present(arg, environment(me));
                if (! ob) return notify_fail("û�����������\n");
                file = base_name(ob) + ".c";
        }
        if (! SECURITY_D->valid_read(file, me, "read"))
                return notify_fail("��û��Ȩ�޲鿴����ļ���\n");
        
                b = x - a + 1;

        message("", HIG "�����Ķ����ļ�Ϊ"HIY + file + NOR "\n"
                                HIG "����ѡȡ���Ǵӵ�"  HIW + a + NOR  HIG "�е���"  HIW + x + NOR HIG"��\n"
                                HIG "�����������£�\n"NOR,me);
        result = HIC + read_file(file,a,b) + "\n";
        me->start_more(result);
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : readfile <������>,��ʼ��������������
HELP );
        return 1;
}

