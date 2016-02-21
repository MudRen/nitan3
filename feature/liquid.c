// liquid.c

#include <dbase.h>
#include <name.h>

mixed func = 0;

int is_liquid(){ return 1; }

void apply_effect(function f)
{
        if (! func)
                func = f;
        else
        if (functionp(func))
                func = ({ func, f });
        else
        if (sizeof(func) < 12)
                func += ({ f });
}

void clear_effect()
{
        func = 0;
}

mixed query_effect()
{
        return func;
}

void do_effect()
{
        int i;

        if (functionp(func))
                evaluate(func);
        if (arrayp(func))
                for (i = 0; i < sizeof(func); i++)
                        evaluate(func[i]);
}

string extra_long()
{
        int amount, max;
        string str = "";

        if (amount = query("liquid/remaining"))
        {
                max = query("max_liquid");
                if (amount == max)
                        str = "����װ����" + query("liquid/name") + "��\n";
                else if (amount >= max * 2 / 3)
                        str = "����װ���ߡ��˷�����" + query("liquid/name") + "��\n";
                else if (amount >= max * 2 / 5)
                        str = "����װ���塢��������" + query("liquid/name") + "��\n";
                else if (amount >= 1)
                        str = "����װ�������" + query("liquid/name") + "��\n";
        }

        str += "��Ʒ����    ��    ����\n";
        str += sprintf("��    ��    ��    %s\n", query("liquid/name"));
        str += sprintf("��    ��    ��    %d\n", this_object()->query_weight());
        str += sprintf("��    ��    ��    %d\n", query("max_liquid"));
        str += sprintf("ʣ    ��    ��    %d\n", query("liquid/remaining"));
        str += sprintf("ʹ�÷�ʽ    ��    ����ָ�� drink %s ���á�\n", query("id"));
        if (this_object()->query_autoload())
                str += "���߶�ʧ    ��    ��\n";
        else
                str += "���߶�ʧ    ��    ��\n";
        return str;
}
