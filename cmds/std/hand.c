// drop.c

#include <weapon.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob, old;
        object weapon;
        string str;

        if (! arg)
                return notify_fail("��Ҫ�ó�ʲô������\n");

        if (arg == "none" || arg == "nothing")
        {
                if (! objectp(ob = me->query_temp("handing")))
                        return notify_fail("�㱾����ʲô��û���ð���\n");

                if (! stringp(str = ob->query("unhand_msg"))) 
                        str = "$N��$n�ջذ��ҡ�\n";
                message_vision(str, me, ob);
                me->delete_temp("handing");
                return 1;
        }

        if (! objectp(ob = present(arg, me)))
                return notify_fail("������û������������\n");
                
        if (ob->is_pet() || ob->is_magic_beast() || ob->query("ridable"))
                return notify_fail("����������ﲻ�����������ϡ�\n");
                
        if (objectp(old = me->query_temp("handing")))
        {
                if (old == ob)
                        return notify_fail("�㲻������������\n");

                if (! stringp(str = old->query("unhand_msg"))) 
                        str = "$N�ջ����е�$n��\n";
                message_vision(str, me, old);
                me->delete_temp("handing");
        }

        if ((ob->query_amount() ? ob->query("base_weight") : ob->query_weight()) > 20000)
                return notify_fail(ob->name() + "̫���ˣ��㵥���ò�ס��\n");

        weapon = me->query_temp("weapon");
        if (weapon &&
            (((int)weapon->query("flag")) & TWO_HANDED ||
             me->query_temp("secondary_weapon")))
        {
                // none of two hand is free
                return notify_fail("��˫�ֶ�����������û�а취"
                                   "������" + ob->name() + "�ˡ�\n");
        }

        if (ob->query("equipped"))
                return notify_fail("����װ�������أ�\n");

        me->set_temp("handing", ob);
        if (! stringp(str = ob->query("hand_msg"))) 
                str = "$N�ó�" + (old && ob->name() == old->name() ? "����" : "") +
                      // "һ" + (ob->query_amount() ? ob->query("base_unit")
                      "һ" + (ob->query_amount() ? ob->query("unit")
                                                 : ob->query("unit")) +
                      "$n���������С�\n";
        message_vision(str, me, ob); 
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : hand <��Ʒ����> | nothing
 
���ָ����������ó�һ������Я������Ʒ����ʱ׼��ʹ�á�
 
HELP );
    return 1;
}
 

