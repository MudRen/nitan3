#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name(BLU "��ʯ" NOR, ({ "BLU jewel2","jewel2" }));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", BLU "һ�����������ľ�����ʯ�������쳣��\n" NOR);
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


                            "kar" : 2,           // ���Ӹ�Դ

                        ////////////////////     ������������

                            "light_attack"  : 20, // ���繥��
                            "add_damage"    : 4, // ׷���˺�4%
                            "suck_eff_qi"   : 6, // �˵���Ѫ����

                   ]));

                set("enchase/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������

                           "kar" : 2,           // ���Ӹ�Դ

                        ////////////////////     ������������

                            "reduce_light"  : 20, // �������磺20%
                            "avoid_poison"  : 20, // ���Իرܣ�20%
                            "reduce_damage" : 10, // �����˺���10%

                            "qi_recover_speed"     : 10, // ��Ѫ�ָ��ٶȣ�+10%
                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}

