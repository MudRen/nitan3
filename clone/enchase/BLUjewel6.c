#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name(BLU "ħ֮��ʯ" NOR, ({ "BLU jewel6","jewel6" }));
        set_weight(40);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", BLU "һ����˸�������â����ɫ��ʯ��"
                    "���˸е�һ������ļ¡�\n" NOR);
                set("unit", "��");
                set("value", 180000);
                set("no_identify", 1);
                set("wear_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "����ͷ�ϡ�\n" NOR);
                set("remove_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "��ͷ��ժ��������\n" NOR);
                
                set("enchase/SN", 2);    
                set("enchase/type", "all");   // ����Ƕ�ĵ�������"all"��"sword"��"blade"��"cloth"��
                set("enchase/cur_firm", 90);  // ��ĥ���
                set("enchase/wspe_data",      // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������


                            "kar" : 8,           // ���Ӹ�Դ

                        ////////////////////     ������������

                            "light_attack"  : 80, // ���繥��
                            "add_damage"    : 17, // ׷���˺�17%
                            "suck_eff_qi"   : 25, // �˵���Ѫ����

                   ]));

                set("enchase/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������

                            "kar" : 8,           // ���Ӹ�Դ

                        ////////////////////     ������������

                            "reduce_light"  : 80, // �������磺80%
                            "avoid_poison"  : 80, // ���Իرܣ�80%
                            "reduce_damage" : 40, // �����˺���40%

                            "qi_recover_speed"     : 40, // ��Ѫ�ָ��ٶȣ�+40%
                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}

