// checkexit.c
// Created by jjgod
// Updated by Lonely (06/17/2002)
// ���ڼ��һ��Ŀ¼�µ����з����ļ��ĳ��������Ƿ���ȷ
// ��������Ŀ¼����Ŀ¼

#include <ansi.h>

inherit F_CLEAN_UP;

int help();

int main(object me, string arg)
{
        string info;
        int i;
        string *flist;
        string file;
        object rob;
        mapping exits;
        string *all_exit, *key;
        string exit;
        mapping errors;

        if (! SECURITY_D->valid_grant(me, "(arch)"))
	        return 0;

        if (! arg)
                return help();

        arg = resolve_path(me->query("cwd"), arg);
        seteuid(getuid(me));
        
        if (file_size(arg) != -2)
                return notify_fail("û�����Ŀ¼��\n");

        info = HIR "���ڼ�� " + arg + " Ŀ¼�µķ����ļ���\n\n" NOR;
        
        message_system("�������������У����Ժ�...");  
        if (! arrayp(flist = get_dir(arg + "/")) || ! sizeof(flist))
        {
                info += HIR "û���κοɼ����ļ���\n" NOR;
                me->start_more(info);
                message_system("ϵͳ������������������ϣ��������Ϸ��\n" ESC + "[K"); 
                return 1;
        }
        
        errors = ([ ]);
        for (i = 0; i < sizeof(flist); i++)
        {
                if (flist[i][strlen(flist[i])-2..strlen(flist[i])] != ".c")
                        continue;

                file = arg + "/" + flist[i];
                
                if (file_size(file) <= 0)
                        continue;
                // if (! objectp(rob = get_object(file)))
                if (! objectp(rob = find_object(file)))
                        rob = load_object(file);
                if (! objectp(rob))
                        continue;
                if (! rob->is_room())
                        continue;
                /*
                if (! inherits(ROOM, rob))
                        continue;
                */
                if (! mapp(exits = rob->query("exits")) ||
                    ! sizeof(exits))
                        continue;

                if (! i % 100)
                        reset_eval_cost();
                
                all_exit = keys(exits);
                foreach (exit in all_exit)
                {
                        if (file_size(exits[exit]) <= 0 &&
                            file_size(exits[exit] + ".c") <= 0)
                                errors[file] = exit;
                }
        }
        
        if (! sizeof(errors))
        {
                info += HIR "�����ϣ�û���κδ���" NOR;
                me->start_more(info);
                message_system("ϵͳ������������������ϣ��������Ϸ��\n" ESC + "[K"); 
                return 1;
        }
        
        key = keys(errors);
        for (i = 0; i < sizeof(key); i++)
        {
                info += sprintf(CYN "�ļ� " WHT "%-30s" CYN " �ĳ��� " WHT "%-8s" CYN " ����\n" NOR,
                                key[i], errors[key[i]]);
        }
        
        info += HIR "\n�����ϡ�" NOR;
        me->start_more(info);
        message_system("ϵͳ������������������ϣ��������Ϸ��\n" ESC + "[K"); 
        return 1;
}

int help()
{
        write(@HELP
ָ���ʽ��checkexit <Ŀ¼��>

���ָ��Ŀ¼�µķ����ļ��ĳ��������Ƿ���ȷ��
HELP
	);
        return 1;
}
