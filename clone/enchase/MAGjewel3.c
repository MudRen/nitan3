#include <ansi.h>
inherit ITEM;
int is_enchase_ob() { return 1; }
void create()
{
        set_name(MAG "ϡ����ʯ" NOR, ({ "MAG jewel3","jewel3" }));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", MAG "һ���Ϲ������ľ�����ʯ�������Բ�ͬѰ���ĸо���\n" NOR);
                set("unit", "��");
                set("value", 120000);
                set("no_identify", 1);
                set("wear_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "����ͷ�ϡ�\n" NOR);
                set("remove_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "��ͷ��ժ��������\n" NOR);
                    
                set("enchase/type", "all");   // ����Ƕ�ĵ�������"all"��"sword"��"blade"��"cloth"��
                set("enchase/cur_firm", 90);  // ��ĥ���
                set("enchase/wspe_data",      // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������


                        "con" : 3,           // ������

                        ////////////////////     ������������

                        "perferm_ap"    : 3,  // �������У�+5%
                        "suck_eff_jing" : 10, // �˵о�������
                        "suck_jingli"   : 10, // ��ȡ����
                        "suck_neili"    : 10, // ��ȡ����

                   ]));

                set("enchase/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������

                        "con" : 3,           // ������

                        ////////////////////     ������������

                        "defense": 30,       // �����ȼ���+30
                        "armor"  : 30,       // ����������+30
                        "perform_dp"    : 3,  // ���з�����+3%
                        "reduce_damage" : 15, // �����˺���15%
                        "reduce_busy"   : 15, // ����æ�ң�15%

                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}


