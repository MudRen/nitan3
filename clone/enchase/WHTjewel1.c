#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name(WHT "��ʯ��Ƭ" NOR, ({ "WHT jewel1","jewel1" }));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", WHT "һƬ��ɫ�ı�ʯ��Ƭ��\n" NOR);
                set("unit", "Ƭ");
                set("value", 80000);
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


                        "int" : 1,           // �����ǻ�
                        "dex" : 1,           // ���Ӹ���

                        ////////////////////     ������������

                        "cold_attack"   : 10, // �䶳����
                        "suck_neili"    : 3, // ��ȡ����3
                        "suck_jingli"   : 3, // ��ȡ����

                   ]));

                set("enchase/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������

                        "int" : 1,           // �����ǻ�
                        "dex" : 1,            // ���Ӹ���
                        ////////////////////     ������������

                        "reduce_cold"   : 10, // �����䶳��10%
                        "defense": 10,       // �����ȼ���+10
                        "max_jingli"    : 3, // �������ޣ�+3%

                        "jing_recover_speed"   : 5, // �����ָ��ٶ�: +5%
                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}



