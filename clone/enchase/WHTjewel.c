#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name(WHT "��ʯ" NOR, ({ "WHT jewel","jewel" }));
        set_weight(30);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", WHT "һ����˸�������â�İ�ɫ��ʯ��\n" NOR);
                set("unit", "��");
                set("value", 100000);
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


                        "int" : 5,           // �����ǻ�
                        "dex" : 5,           // ���Ӹ���

                        ////////////////////     ������������

                        "cold_attack"   : 40, // �䶳����
                        "suck_neili"    : 15, // ��ȡ����
                        "suck_jingli"   : 15, // ��ȡ����

                   ]));

                set("enchase/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������

                        "int" : 5,           // �����ǻ�
                        "dex" : 5,            // ���Ӹ���
                        ////////////////////     ������������

                        "reduce_cold"   : 40, // �����䶳��40%
                        "defense": 40,       // �����ȼ���+40
                        "max_jingli"    : 15, // �������ޣ�+15%

                        "jing_recover_speed"   : 20, // �����ָ��ٶ�: +20%
                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}

