#include <ansi.h>
inherit ITEM;
int is_enchase_ob() { return 1; }
void create()
{
        set_name(RED "��ʯ��Ƭ" NOR, ({ "RED jewel1","jewel1" }));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", RED "һƬ��ɫ�ı�ʯ��Ƭ��\n" NOR);
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


                        "str" : 1,           // ��������

                        ////////////////////     ������������

                        "attack" : 10,       // �����ȼ���+10
                        "damage" : 10,       // �����˺���+10
                        "fire_attack"   : 10, // ���湥��

                   ]));

                set("enchase/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������

                        "str" : 1,           // ��������

                        ////////////////////     ������������

                        "reduce_fire"   : 5, // ������棺5%
                        "reduce_damage" : 5, // �����˺���5%
                        "max_neili"     : 2, // �������ޣ�+2%

                        "qi_recover_speed"     : 2, // ��Ѫ�ָ��ٶȣ�+2%
                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}


