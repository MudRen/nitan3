#include <ansi.h>
inherit ITEM;
int is_enchase_ob() { return 1; }
void create()
{
        set_name(MAG "ʥ֮��ʯ" NOR, ({ "MAG jewel5","jewel5" }));
        set_weight(30);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", MAG "һ����˸�������â����ɫ��ʯ��"
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


                        "con" : 5,           // ������

                        ////////////////////     ������������

                        "perferm_ap"    : 5,  // �������У�+5%
                        "suck_eff_jing" : 20, // �˵о�������
                        "suck_jingli"   : 20, // ��ȡ����
                        "suck_neili"    : 20, // ��ȡ����

                   ]));

                set("enchase/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������

                        "con" : 5,           // ������

                        ////////////////////     ������������

                        "defense": 50,       // �����ȼ���+50
                        "armor"  : 50,       // ����������+50
                        "perform_dp"    : 5,  // ���з�����+5%
                        "reduce_damage" : 30, // �����˺���30%
                        "reduce_busy"   : 30, // ����æ�ң�30%

                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}


