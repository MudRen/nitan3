#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name(WHT "��ʯ" NOR, ({ "WHT jewel2","jewel2" }));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", WHT "һ�Ű׹������ľ�����ʯ�������쳣��\n" NOR);
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


                        "int" : 2,           // �����ǻ�
                        "dex" : 2,           // ���Ӹ���

                        ////////////////////     ������������

                        "cold_attack"   : 20, // �䶳����
                        "suck_neili"    : 5, // ��ȡ����
                        "suck_jingli"   : 5, // ��ȡ����

                   ]));

                set("enchase/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������

                        "int" : 2,           // �����ǻ�
                        "dex" : 2,            // ���Ӹ���
                        ////////////////////     ������������

                        "reduce_cold"   : 20, // �����䶳��20%
                        "defense": 20,       // �����ȼ���+20
                        "max_jingli"    : 5, // �������ޣ�+5%

                        "jing_recover_speed"   : 10, // �����ָ��ٶ�: +10%
                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}

