#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name(HIG "��֮��ʯ" NOR, ({ "GRN jewel4","jewel4" }));
        set_weight(30);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIG "һ����˸�������â����ɫ��ʯ��"
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


                        "int" : 4,           // �����ǻ�

                        ////////////////////     ������������

                        "suck_jingli"   : 15, // ��ȡ����
                        "suck_eff_jing" : 15, // �˵о�������
                        "damage" : 40,       // �����˺���+40

                   ]));

                set("enchase/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������

                        "int" : 4,           // �����ǻ�

                        ////////////////////     ������������

                        "armor"  : 40,       // ����������+40
                        "eff_jing"      : 4, // �������ޣ�+4%
                        "max_jingli"    : 15, // �������ޣ�+15%

                        "jing_recover_speed"   : 20, // �����ָ��ٶ�: +20%
                        "jingli_recover_speed" : 10, // �����ָ��ٶȣ�+10%
                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}

