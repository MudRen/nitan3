// quest.c

#include <ansi.h>
 
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob;

        if (! arg || arg == "")
                return notify_fail("��Ҫ��˭��ȡ������������\n");
        
        if (! objectp(ob = present(arg, environment(me))))
                return notify_fail("����û������ˣ�����ô������\n");

        if (! living(ob))
                return notify_fail("�㻹�ǵ�" + ob->name() +
                                   "������˵�ɣ�\n");

        if (me->is_fighting())
                return notify_fail("ר�Ĵ���ļܣ�\n");

        if (me->is_busy())
                return notify_fail("�㻹���п����ٺ�" + ob->name() +
                                   "̸��Щ����ɣ�\n");

        if (ob->is_fighting())
                return notify_fail("�㻹�ǵ�" + ob->name() +
                                   "�������˵�ɣ�\n");

        if (ob->is_busy())
                return notify_fail(ob->name() +
                                   "��æ���أ�û�������㡣\n");

        notify_fail(ob->name() + "������Ǻǵ�ɵЦ��\n");
        return ob->ask_defend(me);
}

int help(object me)
{
        write(@HELP
ָ���ʽ : defend  ���ָ�����������������ɵ����Ż����ҳ���
��ȡ����
HELP );
        return 1;
}
