// gate.c
// Created by Lonely Nitan@Mud

#pragma save_binary
 
inherit F_CLEAN_UP;
#include <ansi.h>

int main(object me, string arg)
{
        int goto_inventory = 0;
        object obj;
        object env;
        string msg;

        if (! arg) return 0;
        
        if (! me->query("jyszhuang/gate")) return 0;

        if (sscanf(arg, "-i %s", arg)) goto_inventory = 1;

        if (! arg) return 0;

        obj = find_player(arg);
        if (! obj) obj = MESSAGE_D->find_user(arg);
        if (! obj) obj = find_living(arg);
        if (! obj || ! me->visible(obj))
        {
                arg = resolve_path(me->query("cwd"), arg);
                if (! sscanf(arg, "%*s.c") ) arg += ".c";
                if (! (obj = find_object(arg)))
                {
                        if (file_size(arg) >= 0)
                                return me->move(arg);
                        return notify_fail("û�������ҡ������ط���\n");
                }
        }

        if (! goto_inventory)
        {
                if (environment(obj))
                        obj = environment(obj);
                else
                {
                        if (obj->is_character())
                                // unless you goto a inventory, or you
                                // can not enter a character
                                obj = 0;
                }
        }

        if (! obj) return notify_fail("������û�л�������ȥ��\n");
                
        if ((env = environment(me)) == obj)
                return notify_fail("��������ﰡ��\n");

        if (stringp(msg = me->query("env/msg_gate")))
                message_vision(CYN"" + msg + "\n" + ""NOR, me);
        else
                message_vision(HIG "$N����һ��������һ������֮�š�\n" NOR, me);

        
        environment(me)->set("exits/jygate", file_name(obj));
        me->set_magic_move();
        me->start_call_out((: call_other, __FILE__, "close_door", environment(me), "jygate" :), 10);

        if (me->is_fighting()) me->start_busy(3);

        return 1;
}

void close_door(object me, string dir)
{
        me->delete("exits/jygate");
        tell_room(me, HIG"����֮����ʧ�ˡ�\n"NOR);
}

int help(object me)
{
write(@HELP
ָ���ʽ : gate <Ŀ��>
 
���ָ��Ὣ�㴫�͵�ָ����Ŀ��. Ŀ�������һ��living �򷿼�
�ĵ���. ���Ŀ����living , ��ᱻ�Ƶ����Ǹ���ͬ���Ļ�����
 
HELP
    );
    return 1;
}

