#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name(BLU "��ʯ" NOR, ({ "BLU jewel","jewel" }));
        set_weight(30);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", BLU "һ����˸�������â����ɫ��ʯ��\n" NOR);
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


                            "kar" : 4,           // ���Ӹ�Դ

                        ////////////////////     ������������

                            "light_attack"  : 40, // ���繥��
                            "add_damage"    : 12, // ׷���˺�12%
                            "suck_eff_qi"   : 14, // �˵���Ѫ����

                   ]));

                set("enchase/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������

                            "kar" : 4,           // ���Ӹ�Դ

                        ////////////////////     ������������

                            "reduce_light"  : 40, // �������磺40%
                            "avoid_poison"  : 40, // ���Իرܣ�40%
                            "reduce_damage" : 20, // �����˺���20%

                            "qi_recover_speed"     : 20, // ��Ѫ�ָ��ٶȣ�+20%
                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}

