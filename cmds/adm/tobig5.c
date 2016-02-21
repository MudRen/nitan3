/***** Written by ken@NT.  All rights reserved. *****/
// tobig5.c
/****************************************************/
/* �����ַ����֣��й���½��GB�룬��ۺ�̨����BIG5�� */
/* �������벻ͬ���ͻ��������������GB��ı������� */  
/* 0xa1 - 0xf7 ��BIG5��ı������� 0x40 - 0x7e����� */
/* �������������ֿ⣬�ֱ����ֿ� "BtoG.tab"   ���ֿ� */ 
/* "GtoB.tab" ���ڶ�Ӧ���ֿ����ҳ���Ӧ�����֣� ��� */
/* ������"/adm/daemons/languaed.c" ��ɣ�������ֻ�� */
/* ����������ĺ����Ϳ����ˡ�                       */
/****************************************************/

#include <ansi.h>
inherit F_CLEAN_UP;
#define CONVERT "/adm/daemons/languaged.c"

protected int help(object me);
protected int to_big5(string file);
protected string *deep_file_list(string dir);

int main(object me, string arg)
{
        string file;
        mixed *dir;
        int i, total;

        if (!SECURITY_D->valid_grant(me, "(admin)"))
                return 0; 

        if (!arg || sscanf(arg, "%s", file) != 1) 
                return help( me );
                
        seteuid(geteuid(me));
     
        if(!SECURITY_D->valid_write(file, me))
                return notify_fail("û���㹻�Ķ�дȨ��.\n");
        
        if (file_size(file) == -1 )
                file = resolve_path(me->query("cwd"), file);
                
        if(file_size(file) > 0)
        { 
                to_big5(file);
                write(HIW "�ļ���" + file + "����������ת�����.\n" NOR);
                return 1;
        }
   
        else if(file_size(file) == -2) 
        {
                dir = deep_file_list(file);
                for(i=0; i<sizeof(dir); i++)
                {
                        reset_eval_cost();
                        if ( file_size(dir[i]) > 0)
                        {
                                to_big5(dir[i]);
                                total = total + 1;
                                write(dir[i] + " ��ת����ɡ�\n");
                        }
                }
                write("����" + total + "���ļ�ת���ɴ�����(BIG5)\n");
                return 1;
        }
        else return notify_fail("û������ļ���Ŀ¼.\n");
        return 1;               
}

protected string *deep_file_list(string dir)
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
                        result += ({ file });

        }
        return result;
}

protected int to_big5(string file)
{
        string *text;
        int i;   
        
        text = explode(read_file(file), "\n");
        rm(file);
        
        for(i=0; i<sizeof(text); i++)
        {
                text[i] = CONVERT-> toBig5(text[i]);                    
                write_file(file, text[i] + "\n");
        }       
        return 1;
}

protected int help(object me)
{ 
write(@HELP
Written by ken@NT. All rights reserved.
E-mail: printken@yahoo.com.hk

ָ���ʽ: tobig5 <�ļ���Ŀ¼>
��ָ���������ļ���Ŀ¼ת����BIG5�롣
����togb /d/����� /d/���µ������ļ���Ŀ¼�ڵ������Ķ�ת��BIG5
�Ҳ�����ʹ��ת��Ŀ¼����������˽�����Ҫ��ʲô��
(��ָ������/cmds/adm/��)
ע�⣺������Ƚ�Σ�գ���С��ʹ�á�

HELP);
return 1;
}


