#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name(RED "��֮��ʯ" NOR, ({ "RED jewel4","jewel4" }));
        set_weight(30);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", RED "һ����˸�������â�ĺ�ɫ��ʯ��"
                    "���˸е�һ������ļ¡�\n" NOR);
                set("unit", "��");
                set("value", 140000);
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


                        "str" : 4,           // ��������
                        "dex" : 4,           // ���Ӹ���

                        ////////////////////     ������������

                        "attack" : 45,        // �����ȼ���+45
                        "damage" : 45,        // �����˺���+45
                        "fire_attack"   : 45, // ���湥��
                        "perferm_ap"    : 5,   // �������У�+5%
                        "add_damage"    : 3, // ׷���˺�2%

                   ]));

                set("enchase/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������

                        "str" : 4,            // ��������
                        "dex" : 4,            // ���Ӹ���
                        ////////////////////     ������������

                        "reduce_fire"   : 30, // ������棺30%
                        "reduce_damage" : 30, // �����˺���30%
                        "max_neili"     : 10, // �������ޣ�+10%
                        "perform_dp"    : 4,  // ���з�����+4%

                        "qi_recover_speed"     : 12, // ��Ѫ�ָ��ٶȣ�+12%
                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}


