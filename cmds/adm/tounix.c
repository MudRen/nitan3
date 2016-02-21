// tounix.c
// by zjpwxh@sjpl 2004.5.5
// rewrited by lonely


#include <ansi.h>
inherit F_CLEAN_UP;

#define MS sprintf("%c%c", 13, 10 )
#define CC sprintf("%c", 10 )

string *deep_file_list(string dir);
int convert_file(string file);
int help(object me);

int main(object me, string arg)
{
        string file;
        mixed *dir;
        int i, total = 0;

        seteuid(geteuid(this_player(1)));

        if (! SECURITY_D->valid_grant(me, "(arch)"))
                return 0;
                
        if (! arg || sscanf(arg, "%s", file) != 1) 
                return help( me );
                
        if (! SECURITY_D->valid_write(file, me))
                return notify_fail("û���㹻�Ķ�дȨ��.\n");

        if (file_size(file) == -1 )
                file = resolve_path(me->query("cwd"), file);

        if (file_size(file) > 0)
        { 
                convert_file(file);
                write("ok.\n");
                return 1;
        }
        
        if (file_size(file) == -2 && file[strlen(file) - 1] != '/') 
                file += "/";

        if (file_size(file) != -2) 
                return notify_fail(file + " ������һ��Ŀ¼��\n");
                
        write(HIW "��������ת���У����Ժ�...\n" NOR);

        dir = deep_file_list(file);
        for(i = 0; i < sizeof(dir); i++)
        {
                reset_eval_cost();
                if (file_size(dir[i]) > 0)
                {
                        convert_file(dir[i]);
                        total++;
                        // write(dir[i] +" ��ת����ɡ�\n");
                }
        }
        write("\nĿ¼��" + file + "�������ļ�ת����ɡ�\n");

        if (total > 0)
                write(HIC "�ܹ��� " + HIW + total + HIC " ���������ɹ�ת��Ϊ UNIX ��ʽ��\n" NOR);
        else
                write(HIC "û��ת���κε�����\n" NOR);
        return 1;
}

string *deep_file_list(string dir)
{
        int i;
        string *flist, *result = ({ }), file;
        
        flist = get_dir(dir);

        for (i = 0; i < sizeof(flist); i++)
        {
                file = dir + flist[i];
                
                if (file_size(file + "/") == -2)
                        result += deep_file_list(file + "/");
                else 
                {
                        if (file[strlen(file) - 1] == 'o' && 
                            file[strlen(file) - 2] == '.')
                                continue;
                                
                        result += ({ file });
                }

        }
        return result;
}

int convert_file(string file)
{
        string text;

        text = read_file(file);

        if (! text)
        {
                write(sprintf("read file %s error!\n", file));
                return 0;
        }

        text = replace_string(text, MS, CC);
        write_file(file, text, 1);
        return 1;
}

