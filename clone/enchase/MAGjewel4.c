#include <ansi.h>
inherit ITEM;
int is_enchase_ob() { return 1; }
void create()
{
        set_name(MAG "��֮��ʯ" NOR, ({ "MAG jewel4","jewel4" }));
        set_weight(30);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", MAG "һ����˸�������â����ɫ��ʯ��"
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


                        "con" : 4,           // ������

                        ////////////////////     ������������

                        "perferm_ap"    : 4,  // �������У�+5%
                        "suck_eff_jing" : 15, // �˵о�������
                        "suck_jingli"   : 15, // ��ȡ����
                        "suck_neili"    : 15, // ��ȡ����

                   ]));

                set("enchase/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������

                        "con" : 4,           // ������

                        ////////////////////     ������������

                        "defense": 40,       // �����ȼ���+40
                        "armor"  : 40,       // ����������+40
                        "perform_dp"    : 4,  // ���з�����+4%
                        "reduce_damage" : 20, // �����˺���20%
                        "reduce_busy"   : 20, // ����æ�ң�20%

                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}


