
#include <ansi.h>
inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
        object target;
        mapping waitback_list, info;
        string msg, my_id;
        string no_tell, can_tell;
        
        if( !arg )
                return notify_fail("����Ҫ��˭����\n");

        /*
        if (sscanf(arg, "%s %s", arg, msg) != 2)
                return help(me);
        */
        sscanf(arg, "%s %s", arg, msg);
                
        if( !objectp(target = find_player(arg)) || ! me->visible(target) )
                return notify_fail("����û�û�е�¼�����޷�������̸��\n");

        my_id = me->query("id");
        no_tell = target->query("env/no_tell");
        if (! wizardp(me) && (no_tell == "all" || no_tell == "ALL" ||
            is_sub(my_id, no_tell)))
        {
                can_tell = target->query("env/can_tell");
                if (! is_sub(my_id, can_tell))
                        return notify_fail("����˲���������������\n");
        }
        
        if (! interactive(target) || target->is_net_dead())
                return notify_fail("�������ڲ������ϣ���������Ļ���\n");

        if (! living(target))
                return notify_fail("�������ڿ�����������˵�Ļ���...\n");

        if (me->ban_say(1))
                return 0;
                
        if( target == me )
                return notify_fail("�����Լ����񣿣�\n");

        info = allocate_mapping(2);
        info["time"] = time();
        info["msg"] = msg;
        
        if( mapp(waitback_list = target->query_temp("waitback_list")) ) 
        {
                waitback_list += ([ me : info ]);
                target->set_temp("waitback_list", waitback_list);
        }
        else
                target->set_temp("waitback_list", ([ me : info ]));     
        
        tell_object(me, HIG "�㿪ʼ�ȴ���" HIG + target->query_idname(1) + HIG "����\n" NOR);
        tell_object(target, HIG + me->query_idname(1) + HIG "��ʼ�ȴ��������\n" NOR);
        tell_object(target, "\a", 0);
        return 1;
}

int help(object me)
{
        write(@HELP
�ȴ�ָ��

���ָ����������ȴ������е�ʹ���ߣ�ֱ����ʹ���߿�ʼ�ʱ֪ͨ����

ָ���ʽ:
waitback <ʹ���ߴ���> <����>

���ָ��: beep
HELP);
        return 1;
}
