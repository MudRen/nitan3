#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name("ħ֮��ʯ", ({ "BLK jewel6","jewel6" }));
        set_weight(40);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ����˸�������â�ĺ�ɫ��ʯ��"
                    "���˸е�һ������ļ¡�\n");
                set("unit", "��");
                set("value", 180000);
                set("no_identify", 1);
                set("wear_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "����ͷ�ϡ�\n" NOR);
                set("remove_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "��ͷ��ժ��������\n" NOR);
                
                set("enchase/SN", 1);
                set("enchase/type", "all");   // ����Ƕ�ĵ�������"all"��"sword"��"blade"��"cloth"��
                set("enchase/cur_firm", 90);  // ��ĥ���
                set("enchase/wspe_data",      // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������


                          "str" : 8,           // ��������

                        ////////////////////     ������������

                        "poison_attack" : 70, // ���湥��
                        "draw_dragon"   : 1,  // �ٻ�����
                        "xuruo_status"  : 3,  // ս������(����)1��

                   ]));

                set("enchase/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������
 
                          "str" : 8,           // ��������

                        ////////////////////     ������������

                        "reduce_poison" : 70, // ����Ч����70%
                        "avoid_poison"  : 70, // ���Իرܣ�70%
                        "reduce_damage" : 40, // �����˺���40%
                        "reduce_busy"   : 40, // ����æ�ң�40%
                        "reduce_poison" : 70, // ����Ч����70%
                        "parry"  : 80,       // �мܵȼ���+80

                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}


