// summon. ȡ�ر���

#include <ansi.h>
#include <command.h>

inherit F_CLEAN_UP;

int main(object me, string str)
{
        object ob;
        string file, msg;
        mapping summon;
        string *ks;

        if (! str)
        {
                summon = me->query("can_summon");
                if (! mapp(summon))
                        return notify_fail("��Ҫ�ٻ�ʲô��Ʒ��\n");

                ks = keys(summon);
                msg = "�����ڿ����ٻ�����Ʒ������";
                if (sizeof(ks) >= 2)
                        msg += implode(ks[0..sizeof(ks) - 2], "��") +
                                "��" + ks[sizeof(ks) - 1] + "��\n";
                else
                        msg += ks[0] + "��\n";
                msg = sort_string(msg, 64);
                write(msg);
                return 1;
        }

        if (me->is_busy())
                return notify_fail("��������æ�������п�����˵�ɡ�\n");

        if (! stringp(file = me->query("can_summon/" + str)))
                return notify_fail("�㲻֪������ٻ������Ʒ��\n");

        if (file_size(file + ".c") < 0 && file_size(file) < 0)
                return notify_fail("�㲻֪������ٻ������Ʒ��\n");

        if (me->is_ghost())
                return notify_fail("���㻹�������ٻ��ɡ�\n");

        call_other(file, "???");
        ob = find_object(file);
        if (! ob || ! ob->receive_summon(me))
        {
                message_vision(HIM "$N" HIM "��������������������"
                               "�ʡ�\nȻ��ʲôҲû�з��� :)\n", me);
        }

        if (me->is_fighting())
                me->start_busy(2 + random(3));

        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : summon <��Ʒ��ID>

��ָ��������ĳЩ��Ʒ����������װ���ϣ���Ȼ�����һ����
����ʩչ�������С�
HELP );
        return 1;
}

