#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name(BLU "ϡ����ʯ" NOR, ({ "BLU jewel3","jewel3" }));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", BLU "һ�����������ľ�����ʯ�������Բ�ͬѰ���ĸо���\n" NOR);
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


                            "kar" : 3,           // ���Ӹ�Դ

                        ////////////////////     ������������

                            "light_attack"  : 30, // ���繥��
                            "add_damage"    : 8, // ׷���˺�8%
                            "suck_eff_qi"   : 10, // �˵���Ѫ����

                   ]));

                set("enchase/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������

                           "kar" : 3,           // ���Ӹ�Դ

                        ////////////////////     ������������

                            "reduce_light"  : 30, // �������磺30%
                            "avoid_poison"  : 30, // ���Իرܣ�30%
                            "reduce_damage" : 15, // �����˺���15%

                            "qi_recover_speed"     : 15, // ��Ѫ�ָ��ٶȣ�+15%
                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}

