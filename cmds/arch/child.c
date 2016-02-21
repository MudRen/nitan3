// child.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object where, *list;
        int i, number;
        string option,str;

        if (! SECURITY_D->valid_grant(me, "(arch)"))
                return 0;

        if (! arg) arg = me->query("cwf");
        if (! arg) return notify_fail("��Ҫ�鿴�ĸ��ļ���\n");
  
        if (sscanf(arg, "%s %s", option, str) != 2 || option != "-r")
        str = arg; 

        str = resolve_path(me->query("cwd"), str);
        if (sscanf(str, "%*s.c") != 1) str += ".c";
                me->set("cwf", str);
      
        if (file_size(str) < 0)
                       return  notify_fail("û������ļ���"  +  str  +  ")\n");

        list = children(str);
        number=sizeof(list);
        if (number)
        {
                for (i = 0; i < sizeof(list); i++)
                {
                        write((int)(i + 1) + ". " + file_name(list[i]) + " " +
                              list[i]->query("name")+"("+
                              list[i]->query("id")+") is at ");
                        where = environment(list[i]);
                        if (where)
                        {
                                if (where->query("short"))
                                {
                                        write(where->query("short"));
                                } else
                                {
                                        write(where->short());
                                }
                                write("(" + file_name(where) + ")\n");
                                if (option == "-r" && ! living(where))
                                {
                                        destruct(list[i]);
                                        write ("�Ѿ������\n");
                                }
                        } else
                        {
                                write("???\n");
                                if (option == "-r")
                                        destruct(list[i]);
                        }
                }
        } else
                write("û���ҵ��κ����������\n");
        return  1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ: child [-r] filename

�г�һ���ĵ����и�����
�����-r���������������в��ڻ������ϵĸ��ĵ�������

HELP );
        return 1;
}

