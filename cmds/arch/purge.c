// Copyright (C) 2003-2004, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// purge.c

#pragma save_binary
#include <ansi.h>

#define SYNTAX  "ָ���ʽ��purge [<δ��������>] | <ʹ��������> because <ԭ��>\n"

inherit F_CLEAN_UP;

protected int do_purge_players(object me, int day);

int main(object me, string arg)
{
        string name, reason;
        int day;
        object ob;

        if (! SECURITY_D->valid_grant(me, "(admin)"))
                return 0;

        if (! arg)
                return notify_fail(SYNTAX);
        
        if (sscanf(arg, "%d", day) && day >= 0) 
                return do_purge_players(me, day);

        if (sscanf(arg, "%s because %s", name, reason) != 2)
                return notify_fail(SYNTAX);

        if (wiz_level(me) <= wiz_level(name) && ! is_root(me))
                return notify_fail("��û��Ȩ��ɾ��������\n");

        seteuid(getuid());
        if (file_size(DATA_DIR + "login/" + name[0..0] + "/" + name + __SAVE_EXTENSION__) < 0)
                return notify_fail("û����λʹ���ߡ�\n");

        if (ob = find_player(name))
                CHANNEL_D->do_channel(this_object(), "rumor", "ʹ����" +
                                      ob->query("name") + "��" +
                                      me->query("name") + "ɾ���ˡ�");

        // remove the user from disk
        UPDATE_D->remove_user(name);

        tell_object(me, "ʹ���� " + capitalize(name) + " ɾ�����ˡ�\n");
        log_file("static/purge", sprintf("%s %s purged %s because %s.\n",
                 log_time(), geteuid(this_player(1)), name, reason));

        return 1;
}

protected int do_purge_players(object me, int day)
{
        int i, j, ppl_cnt, count;
        string *dir, *ppls, name;
        mixed info;
        
        seteuid(getuid());
        
        if (day < 30) return notify_fail("�������������顣�������Ƕ�ɱ�ˡ�\n");
        
        message_system(sprintf("ϵͳ��ʼ������Ҵ��浵�У���������� %d �첻���ߵ�ʹ����...", day));
        write(HIG "����ϵͳ�����������ң��Ժ�㱨��\n"
              HIG "���ȣ�" + process_bar(0) + "\n");
        
        if (me)
        {
                me->attach_system();
                me->write_prompt();
        }
        
        count = 0;
        ppl_cnt = 0;
        dir = get_dir(DATA_DIR + "login/");
        for (i = 0; i < sizeof(dir); i++) 
        {
                ppls = get_dir(DATA_DIR + "login/" + dir[i] + "/", -1);
                for (j = 0; j < sizeof(ppls); j++) 
                {
                        reset_eval_cost();
                        if (sscanf(ppls[j][0], "%s.o", name) == 1)
                        {
                                if ((string)SECURITY_D->get_status(name) != "(player)")
                                        continue;
                                        
                                info = stat(DATA_DIR + "login/" + name[0..0] + "/" +
                                          name + __SAVE_EXTENSION__);
                                          
                                if (! arrayp(info) || sizeof(info) < 3)
                                        continue;
                                        // ����û������ļ�
                                
                                if ((time()-(int)info[1]) / 86400 >= day && ! objectp(find_player(name))) 
                                {
                                        log_file("static/purge",
                                                 sprintf("%s %s was purged by %s "
                                                         "for didn't login more than %d days\n",
                                                         log_time(), name, geteuid(this_player(1)), day));
                                        UPDATE_D->remove_user(name);
                                        count ++;
                                }
                        }
                }
                ppl_cnt += j;
                message("system", ESC + "[1A" + ESC + "[256D"
                                  HIG "���ȣ�" + process_bar((i + 1) * 100 / sizeof(dir)) +
                                   "\n" + (me ? HIR "ִ����" NOR "> " : ""),
                                   me ? me : filter_array(all_interactive(), (: wizardp :)));
        }
        message_system("ϵͳ������������������ϣ��������Ϸ��\n" ESC + "[K");  
        if (me)
        {
                me->detach_system();
        }
        
        write(HIG "ԭ���ܹ��� " + ppl_cnt + " λʹ���ߡ�\n" NOR);
        write(HIG "�� " + count + " ������ " + day + " ��δ���ߵ�ʹ���߱�������ˡ�\n" NOR);
        write(HIG "�����ܹ��� " + (ppl_cnt - count) + " λʹ���ߡ�\n" NOR);
        
        return 1;

}

int help(object me)
{
write(@HELP
ָ���ʽ��purge [<δ��������>] | <ʹ��������> because <ԭ��>

���һ��ʹ���߻��������һ�������������ߵ�ʹ���ߡ�
HELP );
    return 1;
}

