// shop.c

inherit F_CLEAN_UP;

#include <ansi.h>;

int help(object me);

int main(object me, string arg)
{
        string msg;
        string name, id;

        if (! arg)
        {
                SHOP_D->list_shop(me);
                return 1;
        }
        
        switch (arg)
        {
        case "open"  :
                if (! SECURITY_D->valid_grant(me, "(wizard)"))
                        return notify_fail("��û��Ȩ��ʹ�õ��̹���ָ�\n");
                        
                SHOP_D->open_all(me); 
                break;
        case "close" :
                if (! SECURITY_D->valid_grant(me, "(wizard)"))
                        return notify_fail("��û��Ȩ��ʹ�õ��̹���ָ�\n");
                        
                SHOP_D->close_all(me); 
                break;
        case "reset" : 
                if (! SECURITY_D->valid_grant(me, "(wizard)"))
                        return notify_fail("��û��Ȩ��ʹ�õ��̹���ָ�\n");
                        
                SHOP_D->reset_all(me); 
                break;
        default :
                if (sscanf(arg, "open %s", name))
                {
                        if (! SECURITY_D->valid_grant(me, "(wizard)"))
                                return notify_fail("��û��Ȩ��ʹ�õ��̹���ָ�\n");                        
                        SHOP_D->open_shop(me, name);
                        break;
                }
                if (sscanf(arg, "close %s", name))
                {
                        if (! SECURITY_D->valid_grant(me, "(wizard)"))
                                return notify_fail("��û��Ȩ��ʹ�õ��̹���ָ�\n");                        
                        SHOP_D->close_shop(me, name);
                        break;
                }
                if (sscanf(arg, "reset %s", name))
                {
                        if (! SECURITY_D->valid_grant(me, "(wizard)"))
                                return notify_fail("��û��Ȩ��ʹ�õ��̹���ָ�\n");                       
                        SHOP_D->reset_shop(me, name);
                        break;
                }
                if (sscanf(arg, "owner %s %s", name, id))
                {
                        if (! SECURITY_D->valid_grant(me, "(wizard)"))
                                return notify_fail("��û��Ȩ��ʹ�õ��̹���ָ�\n");                        
                        SHOP_D->change_owner(me, name, id);
                        break;
                }
                else
                {
                        if (time() - (int)me->query("last_tongshangbu") < 2)
                                return notify_fail("��Ҫ�������㣬���㿩��\n");

                        msg = SHOP_D->do_list_all(me, arg);

                        if (stringp(msg))
                                write(msg);

                        me->set("last_tongshangbu", time());
                }
        }
        
        return 1;
}

int help (object me)
{
        write(@HELP
ָ���ʽ��shop [��ƷӢ����|��Ʒ������]
ָ���ʽ��shop [ open [��������] ]  | [ close [��������] ] |
               [ reset [��������] ] | [ owner <��������> <����ID> ]

�鿴��ǰ��Ϸ�еĵ��̾�Ӫ״����

��ʦ�������ڹ�����̡�ʹ�� open ��������ָ����һ�����̻�
�����е��̣�ʹ��close �������ر�ָ����һ�����̻������е�
�̣�reset �������³�ʼ��ָ����һ�����̻������е��̡���ʹ
��owner �����������õ����� id��

HELP);
        return 1;
}


