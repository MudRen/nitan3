#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name(HIG "ϡ����ʯ" NOR, ({ "GRN jewel3","jewel3" }));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIG "һ���̹������ľ�����ʯ�������Բ�ͬѰ���ĸо���\n" NOR);
                set("unit", "��");
                set("value", 120000);
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


                        "int" : 3,           // �����ǻ�

                        ////////////////////     ������������

                        "suck_jingli"   : 10, // ��ȡ����
                        "suck_eff_jing" : 10, // �˵о�������
                        "damage" : 30,       // �����˺���+30

                   ]));

                set("enchase/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������

                        "int" : 3,           // �����ǻ�

                        ////////////////////     ������������

                        "armor"  : 30,       // ����������+30
                        "eff_jing"      : 3, // �������ޣ�+3%
                        "max_jingli"    : 10, // �������ޣ�+10%

                        "jing_recover_speed"   : 15, // �����ָ��ٶ�: +15%
                        "jingli_recover_speed" : 8, // �����ָ��ٶȣ�+8%
                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}

