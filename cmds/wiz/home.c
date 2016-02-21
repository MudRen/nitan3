// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// home.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string msg, file1, file2, str;
        string who;
        object body, ob, user;

        if (! SECURITY_D->valid_grant(me, "(immortal)")) 
                return 0; 

        seteuid(getuid()); 
                                    
        file1 = "/clone/misc/workroom.c";
        
        if (! arg || arg == geteuid(me)) 
        {
                file2 = "/u/" + geteuid(me) + "/workroom.c";
                arg = 0;
        } else 
        {
                ob = UPDATE_D->global_find_player(arg);  
                if (! objectp(ob)) 
                        return notify_fail( "û�������ҡ�\n");
                        
                file2 = "/u/" + arg + "/workroom.c";
        }

        if (file_size(file2) <= 0)
        {
                if (arg) 
                        return notify_fail(ob->query("name") + "û���Լ��Ĺ����ҡ�\n");
                else 
                if (! get_dir("/u/" + geteuid(me) + "/"))
                {
                        if (mkdir("/u/" + geteuid(me)))
                                write(GRN "\n���Ŀ¼���� /u �¡�\n\n" NOR);
                        else 
                                return notify_fail("����Ŀ¼ʧ�ܣ�\n");
                }
                str = read_file(file1);
                str = replace_string(str, "NAME", this_player()->name());
                write_file(file2, str);
        }
        
        if (arg && ! me->query("env/invisible"))
                message_vision("$Nȥ" + ob->query("name") + "�������ˡ�\n\n", me);
        else 
        if (stringp(msg = me->query("env/msg_home")) && ! me->query("env/invisible"))
                message_vision(msg + "\n", me);
        else 
        if (! me->query("env/invisible"))
                message_vision("$N�ؼ�ȥ�ˡ�\n\n",me);
                
        me->move(file2);
        
        UPDATE_D->global_destruct_player(ob, 1);  
        return 1;
}

int help(object me)
{
 write(@HELP
ָ���ʽ : home �� home <sb>

���ô�һָ���ֱ�ӻص��Լ��Ĺ����һ��й����ҵ���ʦ�����͡�
������� 'msg_home' ����趨, ���ڳ����˶��ῴ���Ǹ�ѶϢ.
HELP
    );
    return 1;
}

