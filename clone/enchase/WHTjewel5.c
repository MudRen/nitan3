#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name(WHT "ʥ֮��ʯ" NOR, ({ "WHT jewel5","jewel5" }));
        set_weight(30);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", WHT "һ����˸�������â�İ�ɫ��ʯ��"
                    "���˸е�һ������ļ¡�\n" NOR);
                set("unit", "��");
                set("value", 160000);
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


                        "int" : 6,           // �����ǻ�
                        "dex" : 6,           // ���Ӹ���

                        ////////////////////     ������������

                        "cold_attack"   : 60, // �䶳����
                        "suck_neili"    : 20, // ��ȡ����
                        "suck_jingli"   : 20, // ��ȡ����

                   ]));

                set("enchase/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������

                        "int" : 6,           // �����ǻ�
                        "dex" : 6,            // ���Ӹ���
                        ////////////////////     ������������

                        "reduce_cold"   : 60, // �����䶳��60%
                        "defense": 60,       // �����ȼ���+60
                        "max_jingli"    : 20, // �������ޣ�+20%

                        "jing_recover_speed"   : 30, // �����ָ��ٶ�: +30%
                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}

