#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name(RED "ϡ����ʯ" NOR, ({ "RED jewel3","jewel3" }));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", RED "һ�ź�������ľ�����ʯ�������Բ�ͬѰ���ĸо���\n" NOR);
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


                        "str" : 3,           // ��������
                        "dex" : 3,           // ���Ӹ���

                        ////////////////////     ������������

                        "attack" : 30,        // �����ȼ���+30
                        "damage" : 30,        // �����˺���+30
                        "fire_attack"   : 30, // ���湥��
                        "perferm_ap"    : 3,   // �������У�+3%
                        "add_damage"    : 2, // ׷���˺�2%

                   ]));

                set("enchase/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������

                        "str" : 3,            // ��������
                        "dex" : 3,            // ���Ӹ���
                        ////////////////////     ������������

                        "reduce_fire"   : 20, // ������棺20%
                        "reduce_damage" : 20, // �����˺���20%
                        "max_neili"     : 6, // �������ޣ�+6%
                        "perform_dp"    : 2,  // ���з�����+2%

                        "qi_recover_speed"     : 8, // ��Ѫ�ָ��ٶȣ�+8%
                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}


