#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name(HIG "ʥ֮��ʯ" NOR, ({ "GRN jewel5","jewel5" }));
        set_weight(30);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIG "һ����˸�������â����ɫ��ʯ��"
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


                        "int" : 6,           // �����ǻ�

                        ////////////////////     ������������

                        "suck_jingli"   : 20, // ��ȡ����
                        "suck_eff_jing" : 20, // �˵о�������
                        "damage" : 60,       // �����˺���+60

                   ]));

                set("enchase/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������

                        "int" : 6,           // �����ǻ�

                        ////////////////////     ������������

                        "armor"  : 60,       // ����������+60
                        "eff_jing"      : 6, // �������ޣ�+6%
                        "max_jingli"    : 20, // �������ޣ�+20%

                        "jing_recover_speed"   : 30, // �����ָ��ٶ�: +30%
                        "jingli_recover_speed" : 13, // �����ָ��ٶȣ�+13%
                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}

