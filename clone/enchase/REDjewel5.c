#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name(RED "ʥ֮��ʯ" NOR, ({ "RED jewel5","jewel5" }));
        set_weight(30);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", RED "һ����˸�������â�ĺ�ɫ��ʯ��"
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


                        "str" : 6,           // ��������
                        "dex" : 6,           // ���Ӹ���

                        ////////////////////     ������������

                        "attack" : 60,        // �����ȼ���+60
                        "damage" : 60,        // �����˺���+60
                        "fire_attack"   : 60, // ���湥��
                        "perferm_ap"    : 7,   // �������У�+7%
                        "add_damage"    : 5, // ׷���˺�5%

                   ]));

                set("enchase/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������

                        "str" : 6,            // ��������
                        "dex" : 6,            // ���Ӹ���
                        ////////////////////     ������������

                        "reduce_fire"   : 50, // ������棺50%
                        "reduce_damage" : 50, // �����˺���50%
                        "max_neili"     : 13, // �������ޣ�+13%
                        "perform_dp"    : 6,  // ���з�����+6%

                        "qi_recover_speed"     : 20, // ��Ѫ�ָ��ٶȣ�+20%
                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}


