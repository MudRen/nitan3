#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name(HIG "ħ֮��ʯ" NOR, ({ "GRN jewel6","jewel6" }));
        set_weight(40);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIG "һ����˸�������â����ɫ��ʯ��"
                    "���˸е�һ������ļ¡�\n" NOR);
                set("unit", "��");
                set("value", 180000);
                set("no_identify", 1);
                set("wear_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "����ͷ�ϡ�\n" NOR);
                set("remove_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "��ͷ��ժ��������\n" NOR);
                
                set("enchase/SN", 4);    
                set("enchase/type", "all");   // ����Ƕ�ĵ�������"all"��"sword"��"blade"��"cloth"��
                set("enchase/cur_firm", 90);  // ��ĥ���
                set("enchase/wspe_data",      // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������


                        "int" : 8,           // �����ǻ�

                        ////////////////////     ������������

                        "suck_jingli"   : 25, // ��ȡ����
                        "suck_eff_jing" : 25, // �˵о�������
                        "damage" : 80,       // �����˺���+80

                   ]));

                set("enchase/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������

                        "int" : 8,           // �����ǻ�

                        ////////////////////     ������������

                        "armor"  : 80,       // ����������+80
                        "eff_jing"      : 8, // �������ޣ�+8%
                        "max_jingli"    : 25, // �������ޣ�+25%

                        "jing_recover_speed"   : 40, // �����ָ��ٶ�: +40%
                        "jingli_recover_speed" : 16, // �����ָ��ٶȣ�+16%
                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}

