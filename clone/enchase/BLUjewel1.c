#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name(BLU "��ʯ��Ƭ" NOR, ({ "BLU jewel1","jewel1" }));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", BLU "һƬ��ɫ�ı�ʯ��Ƭ��\n" NOR);
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


                            "kar" : 1,           // ���Ӹ�Դ

                        ////////////////////     ������������

                            "light_attack"  : 10, // ���繥��
                            "add_damage"    : 2, // ׷���˺�2%
                            "suck_eff_qi"   : 3, // �˵���Ѫ����

                   ]));

                set("enchase/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������

                           "kar" : 1,           // ���Ӹ�Դ

                        ////////////////////     ������������

                            "reduce_light"  : 10, // �������磺10%
                            "avoid_poison"  : 10, // ���Իرܣ�10%
                            "reduce_damage" : 5, // �����˺���5%

                            "qi_recover_speed"     : 5, // ��Ѫ�ָ��ٶȣ�+5%
                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}

