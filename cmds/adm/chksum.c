 // chksum.c
 // By Plzw 
 // 2004-5-25 
  
#include <ansi.h>  
#include <command.h>  
  
inherit F_CLEAN_UP;  
  
int main(object me, string str)  
{ 
        object ob;  
        string file;  
        mapping ol; 
        string item; 
        string *items; 
        string nitem; 
        string msg; 

        if (! SECURITY_D->valid_grant(me, "(admin)")) 
                return 0;
	
        if (! str)   
                ob = me;   
        else   
        {   
                ob = present(str, environment(me));   
                if (! ob) ob = find_player(str);   
                if (! ob) ob = find_living(str);   
                if (! ob) return notify_fail("��Ҫ�鿴˭���ٻ��б�\n");   
        }  
        
        // ��ȡ���ٻ���Ʒ�б� 
        
        if (! mapp(ol = ob->query("can_summon")) || sizeof(ol) < 1) 
                return notify_fail("�����ڻ�û�п����ٻ�����Ʒ��\n"); 
 
        msg = ob->query("name") + "(" + ob->query("id") + ")�����ٻ�����Ʒ�У�\n\n"; 
        items = keys(ol); 
        foreach (item in items) 
        { 
                file = (string) ol[item]; 
                if (file_size(file + ".c") < 0 && file_size(file) < 0) 
                        nitem = HIR"<�����ڵ�����ID��������ʦ��ϵ>"NOR; 
                else 
                { 
                        call_other(file, "???"); 
                        if (objectp(ob = find_object(file))) 
                                nitem = ob->name(); 
                } 
                msg += sprintf(WHT "%-14s  %-14s\n", item, nitem); 
        } 
        write(msg); 
        return 1; 
}
