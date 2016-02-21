// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// ls.c

#include <ansi.h>

inherit F_CLEAN_UP;

int filter_list(mixed ob, string path, object user);
int sort_list(mixed ob1, mixed ob2);

int main(object me, string arg)
{
	int i, j, w, x, col;
	string dir;
	string path;
	int opt_l,files,dirs,k;
	mixed *file;
	string result;

        if (! SECURITY_D->valid_grant(me, "(wizard)"))
                return 0;
                
	if (arg)
	{
		if (arg == "-l")
		{
			opt_l = 1;
			arg = 0;
		} else
			if (sscanf(arg, "%s -l", arg) || sscanf(arg, "-l %s", arg))
			{
				opt_l = 1;
			} else
				opt_l = 0;
	}
	
	dir = resolve_path(me->query("cwd"), arg);
	
	if (me != this_player(1))
		return notify_fail("���ǵ�ǰʹ���߽��в�����\n");
		
	seteuid(getuid());
	if (file_size(dir) == -2 && dir[strlen(dir) - 1] != '/') dir += "/";
	
	if (file_size(dir) == -2)
	{
		path = dir;
	} else
	{
		string *p;
		p = explode(dir, "/");
		if (sizeof(p) >= 2)
		{
			p = p[0..sizeof(p) - 2];
			path = "/" + implode(p, "/") + "/";
		} else
			path = "/";
		p = 0;
	}
	
	file = get_dir(dir, -1);
	seteuid(geteuid(me));
	
	if (! sizeof(file))
	{
		if (file_size(dir) == -2)
			return notify_fail(sprintf("Ŀ¼(%s)�ǿյġ�\n", dir));
		else
			return notify_fail(sprintf("û�����Ŀ¼(%s)��\n", dir));
	}
	
	file = filter_array(file, (: filter_list :), path, me);
	file = sort_array(file, (: sort_list :));
	
	i = sizeof(file);
        x = 0;
        k = 0;
	w = 0;
	while (i--)
	{
		if (file[i][1] == -2)
		{
		        file[i][0] += "/";
                        x++;
                }
		if (strlen(file[i][0]) > w) w = strlen(file[i][0]) + 1;
		file[i] += ({ MASTER_OB->valid_write(path + file[i][0], me, "ls") });
	}
	result = "Ŀ¼��" + path + "\n";
        files = sizeof(file) - x;
        dirs = x;
	if (! sizeof(file))
	{
		write(sprintf("%s    û���κε�����\n\n", result));
		return 1;
	}
	
	if (opt_l)
	{
		string syntax;
		syntax = sprintf("%%s%%-%ds  %%-8s  %%-8s  %%s\n" NOR, w);
		result += sprintf(syntax, HIR, "�ļ���", "��С", "�Ƿ�װ��", "������ʱ��");
		col = 82 / (w + 6);
		for (i = 0, j = sizeof(file); i < j; i++)
		result += sprintf(syntax,
			          (file[i][3] ? NOR : HIR),
			          file[i][0],
			          (file[i][1] == -2 ? "<dir>" : sprintf("%d", file[i][1])),
			          ((file[i][1] != -2 && find_object(path + file[i][0])) ? HIC "����װ��" NOR : NOR "--------"),
			          CHINESE_D->chinese_time(5, ctime(file[i][2])));
	} else
	{
		col = 82 / (w + 6);
		for (i = 0, j = sizeof(file); i < j; i++) {
                        result += sprintf("%s%-*s%6s%s"NOR,
                                          (file[i][3] ? (file[i][1] == -2 || find_object(path + file[i][0])? HIC:GRN) : HIR),
                                           w + 1,file[i][0] ,
                                          (file[i][1]==-2 ? " [37m<DIR>[0m" : sprintf("%4dk", (file[i][1]+1023)/1024)),
                                          ((i+1)%col)?" [1;33m| [0m":"\n" );
                        k += ((file[i][1]+1023)/1024);
	        }
	}
	me->start_more(result);
//	write(result);
        printf("\n                    �ļ��У�%d �����ܹ���%d K ��Ŀ¼���У�%d ��\n", files, k, dirs);
	
	return 1;
}

int filter_list(mixed ob, string path, object user)
{
	return MASTER_OB->valid_read(path + ob[0], user, "ls");
}

int sort_list(mixed ob1, mixed ob2)
{
	if (ob1[1] == -2 && ob2[1] != -2)
		return -1;
		
	if (ob1[1] != -2 && ob2[1] == -2)
		return 1;
		
	return strcmp(ob1[0], ob2[0]);
}

int help(object me)
{
	write(@HELP
ָ���ʽ: ls [-l] [<·����>]
 
�г�Ŀ¼�����е���Ŀ¼������, ���û��ָ��Ŀ¼, ���г�����Ŀ¼
�����ݣ����г��ĵ����У���ɫ�Ĵ���·�������Ѿ�����������Ӧ��
�ļ�������ɫ�Ĵ�����ͨ���ļ�����ɫ���ʾ��Ը�Ŀ¼���ļ�û��д
��Ȩ�ޡ�-l���������г���ϸ���ϡ�
 
����:
'ls /' ���г�����λ춸�Ŀ¼�µĵ�������Ŀ¼��
'ls /adm/*.c -l' ����г�/adm/Ŀ¼����������.c��β���ļ�����ϸ
�����б�
 
HELP );
	return 1;
}
