#include <ansi.h>
inherit ITEM;
int is_enchase_ob() { return 1; }
void create()
{
        set_name(MAG "ħ֮��ʯ" NOR, ({ "MAG jewel6","jewel6" }));
        set_weight(40);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", MAG "һ����˸�������â����ɫ��ʯ��"
                    "���˸е�һ������ļ¡�\n" NOR);
                set("unit", "��");
                set("value", 180000);
                set("no_identify", 1);
                set("wear_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "����ͷ�ϡ�\n" NOR);
                set("remove_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "��ͷ��ժ��������\n" NOR);
                
                set("enchase/SN", 5);
                set("enchase/type", "all");   // ����Ƕ�ĵ�������"all"��"sword"��"blade"��"cloth"��
                set("enchase/cur_firm", 90);  // ��ĥ���
                set("enchase/wspe_data",      // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������


                        "con" : 7,           // ������

                        ////////////////////     ������������

                        "perferm_ap"    : 7,  // �������У�+7%
                        "suck_eff_jing" : 25, // �˵о�������
                        "suck_jingli"   : 25, // ��ȡ����
                        "suck_neili"    : 25, // ��ȡ����

                   ]));

                set("enchase/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������

                        "con" : 7,           // ������

                        ////////////////////     ������������

                        "defense": 70,       // �����ȼ���+70
                        "armor"  : 70,       // ����������+70
                        "perform_dp"    : 7,  // ���з�����+7%
                        "reduce_damage" : 40, // �����˺���40%
                        "reduce_busy"   : 40, // ����æ�ң�40%

                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}


