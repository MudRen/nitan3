// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// quest1.c

#include <ansi.h>
 
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        mapping q;
        string name, npc;

        if (me->query("ultra_count"))
                write(sprintf("���ͽ��������ʦ�������Ѿ���������� %d ����\n",
                              me->query("ultra_count")));
 
        if (! me->query("ultraquest/npc1"))
        {
                write("������û�����κ�����\n");
                return 1;
        }

        if (me->query("ultraquest/npc5"))  
        {
                npc = me->query("ultraquest/npc5");
                name = me->query("ultraquest/name5");          
        } else
        if (me->query("ultraquest/npc4"))  
        {
                npc = me->query("ultraquest/npc4");
                name = me->query("ultraquest/name4");         
        } else
        if (me->query("ultraquest/npc3"))  
        {
                npc = me->query("ultraquest/npc3"); 
                name = me->query("ultraquest/name3");
        } else
        if (me->query("ultraquest/npc2"))
        { 
                npc = me->query("ultraquest/npc2");
                name = me->query("ultraquest/name2");  
        } else
        {  
                npc = me->query("ultraquest/npc1"); 
                name = me->query("ultraquest/name1");
        }

        if (! mapp(q =  me->query("ultraquest/quest")))
        {
                if (me->query("ultraquest/id"))
                {
                        write("�����ڵ�������ȥɱ��Ļ�����" + me->query("ultraquest/name") + "(" +
                              me->query("ultraquest/id") + ")����������ͷ�����͡�\n");
                        return 1;
                }
                write("�����ڵ�������ȥѰ������֪����" + name + "(" + npc + ")��\n" +
                      "��˵��ǰ��������" + me->query("ultraquest/place") +"���ֹ���\n");
                return 1;
        } else
        {
                switch (q["type"])
                {
                case "kill":
                        write(name + "(" + npc + ")�Ը���ȥ����" HIR + 
                              q["name"] + "(" + q["id"] + ")" + NOR "����ͷ���������\n");
                        return 1;
                
                case "give":
                        write(name + "(" + npc + ")�Ը���ȥ�Ѱ����͵�" HIR + 
                              q["name"] + "(" + q["id"] + ")" + NOR "������������\n");                
                        return 1;
                        
                case "send":
                        write(name + "(" + npc + ")�Ը���ȥ�����͵�" HIR + 
                              q["name"] + "(" + q["id"] + ")" + NOR "������������\n");  
                        return 1;
                        
                case "guard":  
                        write(name + "(" + npc + ")�Ը������������ﱣ������\n");  
                        return 1; 
                          
                case "mathematics":
                        write(name + "(" + npc + ")�Ը�������������㡣\n");
                        return 1;   
                        
                case "literate":
                        write(name + "(" + npc + ")�Ը����������ʫ�ʡ�\n");
                        return 1;
                           
                case "chess":
                        write(name + "(" + npc + ")�Ը�����������弼��\n");
                        return 1;       
                        
                case "calligraphy":
                        write(name + "(" + npc + ")�Ը������д���鷨��\n");
                        return 1;       

                case "drawing":
                        write(name + "(" + npc + ")�Ը�������滭��\n");
                        return 1;                                                                             

                case "medical":
                        write(name + "(" + npc + ")�Ը�������β���\n");
                        return 1;      
                }
        }

        write("������û�����κ�����\n");
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : quest2 ��ʾ���㵱ǰ����ʦ����
HELP );
        return 1;
}


