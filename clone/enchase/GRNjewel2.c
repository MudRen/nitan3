#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name(HIG "��ʯ" NOR, ({ "GRN jewel2","jewel2" }));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIG "һ���̹������ľ�����ʯ�������쳣��\n" NOR);
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


                        "int" : 2,           // �����ǻ�

                        ////////////////////     ������������

                        "suck_jingli"   : 6, // ��ȡ����
                        "suck_eff_jing" : 6, // �˵о�������
                        "damage" : 20,       // �����˺���+20

                   ]));

                set("enchase/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������

                        "int" : 2,           // �����ǻ�

                        ////////////////////     ������������

                        "armor"  : 20,       // ����������+20
                        "eff_jing"      : 2, // �������ޣ�+2%
                        "max_jingli"    : 6, // �������ޣ�+6%

                        "jing_recover_speed"   : 10, // �����ָ��ٶ�: +10%
                        "jingli_recover_speed" : 4, // �����ָ��ٶȣ�+4%
                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}

