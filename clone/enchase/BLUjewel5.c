#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name(BLU "ʥ֮��ʯ" NOR, ({ "BLU jewel5","jewel5" }));
        set_weight(30);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", BLU "һ����˸�������â����ɫ��ʯ��"
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


                            "kar" : 6,           // ���Ӹ�Դ

                        ////////////////////     ������������

                            "light_attack"  : 60, // ���繥��
                            "add_damage"    : 14, // ׷���˺�14%
                            "suck_eff_qi"   : 18, // �˵���Ѫ����

                   ]));

                set("enchase/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������

                            "kar" : 6,           // ���Ӹ�Դ

                        ////////////////////     ������������

                            "reduce_light"  : 60, // �������磺60%
                            "avoid_poison"  : 60, // ���Իرܣ�60%
                            "reduce_damage" : 30, // �����˺���30%

                            "qi_recover_speed"     : 30, // ��Ѫ�ָ��ٶȣ�+30%
                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}

