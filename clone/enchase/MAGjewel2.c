#include <ansi.h>
inherit ITEM;
int is_enchase_ob() { return 1; }
void create()
{
        set_name(MAG "��ʯ" NOR, ({ "MAG jewel2","jewel2" }));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", MAG "һ���Ϲ������ľ�����ʯ�������쳣��\n" NOR);
                set("unit", "��");
                set("value", 100000);

                set("wear_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "����ͷ�ϡ�\n" NOR);
                set("remove_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "��ͷ��ժ��������\n" NOR);
                set("no_identify", 1);                    
                set("enchase/type", "all");   // ����Ƕ�ĵ�������"all"��"sword"��"blade"��"cloth"��
                set("enchase/cur_firm", 90);  // ��ĥ���
                set("enchase/wspe_data",      // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������


                        "con" : 2,           // ������

                        ////////////////////     ������������

                        "perferm_ap"    : 2,  // �������У�+5%
                        "suck_eff_jing" : 6, // �˵о�������
                        "suck_jingli"   : 6, // ��ȡ����
                        "suck_neili"    : 6, // ��ȡ����

                   ]));

                set("enchase/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������

                        "con" : 2,           // ������

                        ////////////////////     ������������

                        "defense": 20,       // �����ȼ���+20
                        "armor"  : 20,       // ����������+20
                        "perform_dp"    : 2,  // ���з�����+2%
                        "reduce_damage" : 10, // �����˺���10%
                        "reduce_busy"   : 10, // ����æ�ң�10%

                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}


