#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name(HIG "��ʯ��Ƭ" NOR, ({ "GRN jewel1","jewel1" }));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIG "һƬ��ɫ�ı�ʯ��Ƭ��\n" NOR);
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


                        "int" : 1,           // �����ǻ�

                        ////////////////////     ������������

                        "suck_jingli"   : 3, // ��ȡ����
                        "suck_eff_jing" : 3, // �˵о�������
                        "damage" : 10,       // �����˺���+10

                   ]));

                set("enchase/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������

                        "int" : 1,           // �����ǻ�

                        ////////////////////     ������������

                        "armor"  : 10,       // ����������+10
                        "eff_jing"      : 1, // �������ޣ�+1%
                        "max_jingli"    : 3, // �������ޣ�+3%

                        "jing_recover_speed"   : 5, // �����ָ��ٶ�: +5%
                        "jingli_recover_speed" : 2, // �����ָ��ٶȣ�+2%
                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}

