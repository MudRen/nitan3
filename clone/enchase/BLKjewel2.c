#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name("��ʯ", ({ "BLK jewel2","jewel2" }));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ��ڹ������ľ�����ʯ�������쳣��\n");
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


                          "str" : 2,           // ��������

                        ////////////////////     ������������

                        "poison_attack" : 20, // ���湥��
                        "draw_dragon"   : 1,  // �ٻ�����
                        "xuruo_status"  : 1,  // ս������(����)1��

                   ]));

                set("enchase/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������
 
                          "str" : 2,           // ��������

                        ////////////////////     ������������

                        "reduce_poison" : 20, // ����Ч����20%
                        "avoid_poison"  : 20, // ���Իرܣ�20%
                        "reduce_damage" : 10, // �����˺���10%
                        "reduce_busy"   : 10, // ����æ�ң�10%
                        "reduce_poison" : 20, // ����Ч����20%
                        "parry"  : 20,       // �мܵȼ���+20

                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}


