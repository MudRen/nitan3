#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name(RED "��ʯ" NOR, ({ "RED jewel2","jewel2" }));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", RED "һ�ź�������ľ�����ʯ�������쳣��\n" NOR);
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


                        "str" : 2,           // ��������
                        "dex" : 2,           // ���Ӹ���

                        ////////////////////     ������������

                        "attack" : 18,        // �����ȼ���+18
                        "damage" : 18,        // �����˺���+18
                        "fire_attack"   : 18, // ���湥��
                        "perferm_ap"    : 1,   // �������У�+1%

                   ]));

                set("enchase/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������

                        "str" : 2,            // ��������
                        "dex" : 2,            // ���Ӹ���
                        ////////////////////     ������������

                        "reduce_fire"   : 10, // ������棺10%
                        "reduce_damage" : 10, // �����˺���10%
                        "max_neili"     : 4, // �������ޣ�+4%
                        "perform_dp"    : 1,  // ���з�����+1%

                        "qi_recover_speed"     : 4, // ��Ѫ�ָ��ٶȣ�+4%
                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}


