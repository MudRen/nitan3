#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name(WHT "ϡ����ʯ" NOR, ({ "WHT jewel3","jewel3" }));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", WHT "һ�Ű׹������ľ�����ʯ�������Բ�ͬѰ���ĸо���\n" NOR);
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


                        "int" : 4,           // �����ǻ�
                        "dex" : 4,           // ���Ӹ���

                        ////////////////////     ������������

                        "cold_attack"   : 30, // �䶳����
                        "suck_neili"    : 10, // ��ȡ����
                        "suck_jingli"   : 10, // ��ȡ����

                   ]));

                set("enchase/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������

                        "int" : 4,           // �����ǻ�
                        "dex" : 4,            // ���Ӹ���
                        ////////////////////     ������������

                        "reduce_cold"   : 30, // �����䶳��30%
                        "defense": 30,       // �����ȼ���+30
                        "max_jingli"    : 10, // �������ޣ�+10%

                        "jing_recover_speed"   : 15, // �����ָ��ٶ�: +15%
                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}

