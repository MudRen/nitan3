#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name(RED "ħ֮��ʯ" NOR, ({ "RED jewel6","jewel6" }));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", RED "һ����˸�������â�ĺ�ɫ��ʯ��"
                    "���˸е�һ������ļ¡�\n" NOR);
                set("unit", "��");
                set("value", 180000);
                set("no_identify", 1);
                set("wear_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "����ͷ�ϡ�\n" NOR);
                set("remove_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "��ͷ��ժ��������\n" NOR);
                
                set("enchase/SN", 6);    
                set("enchase/type", "all");   // ����Ƕ�ĵ�������"all"��"sword"��"blade"��"cloth"��
                set("enchase/cur_firm", 90);  // ��ĥ���
                set("enchase/wspe_data",      // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������


                        "str" : 8,           // ��������
                        "dex" : 8,           // ���Ӹ���

                        ////////////////////     ������������

                        "attack" : 80,        // �����ȼ���+80
                        "damage" : 80,        // �����˺���+80
                        "fire_attack"   : 80, // ���湥��
                        "perferm_ap"    : 10,   // �������У�+10%
                        "add_damage"    : 7, // ׷���˺�5%

                   ]));

                set("enchase/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������

                        "str" : 8,            // ��������
                        "dex" : 8,            // ���Ӹ���
                        ////////////////////     ������������

                        "reduce_fire"   : 70, // ������棺70%
                        "reduce_damage" : 70, // �����˺���70%
                        "max_neili"     : 15, // �������ޣ�+15%
                        "perform_dp"    : 8,  // ���з�����+8%

                        "qi_recover_speed"     : 30, // ��Ѫ�ָ��ٶȣ�+30%
                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}


