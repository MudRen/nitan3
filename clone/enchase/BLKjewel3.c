#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name("ϡ����ʯ", ({ "BLK jewel3","jewel3" }));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ�źڹ������ľ�����ʯ�������Բ�ͬѰ���ĸо���\n");
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


                          "str" : 3,           // ��������

                        ////////////////////     ������������

                        "poison_attack" : 30, // ���湥��
                        "draw_dragon"   : 1,  // �ٻ�����
                        "xuruo_status"  : 2,  // ս������(����)1��

                   ]));

                set("enchase/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������
 
                          "str" : 3,           // ��������

                        ////////////////////     ������������

                        "reduce_poison" : 30, // ����Ч����30%
                        "avoid_poison"  : 30, // ���Իرܣ�30%
                        "reduce_damage" : 15, // �����˺���15%
                        "reduce_busy"   : 15, // ����æ�ң�15%
                        "reduce_poison" : 30, // ����Ч����30%
                        "parry"  : 30,       // �мܵȼ���+30

                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}

