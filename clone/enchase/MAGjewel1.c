#include <ansi.h>
inherit ITEM;
int is_enchase_ob() { return 1; }
void create()
{
        set_name(MAG "��ʯ��Ƭ" NOR, ({ "MAG jewel1","jewel1" }));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", MAG "һƬ��ɫ�ı�ʯ��Ƭ��\n" NOR);
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


                        "con" : 1,           // ������

                        ////////////////////     ������������

                        "perferm_ap"    : 1,  // �������У�+5%
                        "suck_eff_jing" : 3, // �˵о�������
                        "suck_jingli"   : 3, // ��ȡ����
                        "suck_neili"    : 3, // ��ȡ����3

                   ]));

                set("enchase/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������

                        "con" : 1,           // ������

                        ////////////////////     ������������

                        "defense": 10,       // �����ȼ���+10
                        "armor"  : 10,       // ����������+10
                        "perform_dp"    : 1,  // ���з�����+1%
                        "reduce_damage" : 5, // �����˺���5%
                        "reduce_busy"   : 5, // ����æ�ң�5%

                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}


