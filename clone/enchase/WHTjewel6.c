#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name(WHT "ħ֮��ʯ" NOR, ({ "WHT jewel6","jewel6" }));
        set_weight(40);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", WHT "һ����˸�������â�İ�ɫ��ʯ��"
                    "���˸е�һ������ļ¡�\n" NOR);
                set("unit", "��");
                set("value", 180000);
                set("no_identify", 1);
                set("wear_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "����ͷ�ϡ�\n" NOR);
                set("remove_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "��ͷ��ժ��������\n" NOR);
                
                set("enchase/SN", 7);    
                set("enchase/type", "all");   // ����Ƕ�ĵ�������"all"��"sword"��"blade"��"cloth"��
                set("enchase/cur_firm", 90);  // ��ĥ���
                set("enchase/wspe_data",      // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������


                        "int" : 8,           // �����ǻ�
                        "dex" : 8,           // ���Ӹ���

                        ////////////////////     ������������

                        "cold_attack"   : 80, // �䶳����
                        "suck_neili"    : 25, // ��ȡ����
                        "suck_jingli"   : 25, // ��ȡ����

                   ]));

                set("enchase/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������

                        "int" : 8,           // �����ǻ�
                        "dex" : 8,            // ���Ӹ���
                        ////////////////////     ������������

                        "reduce_cold"   : 80, // �����䶳��80%
                        "defense": 80,       // �����ȼ���+80
                        "max_jingli"    : 25, // �������ޣ�+25%

                        "jing_recover_speed"   : 40, // �����ָ��ٶ�: +40%
                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}

