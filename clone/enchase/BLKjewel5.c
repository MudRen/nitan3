#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name("ʥ֮��ʯ", ({ "BLK jewel5","jewel5" }));
        set_weight(30);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ����˸�������â�ĺ�ɫ��ʯ��"
                    "���˸е�һ������ļ¡�\n");
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


                          "str" : 6,           // ��������

                        ////////////////////     ������������

                        "poison_attack" : 50, // ���湥��
                        "draw_dragon"   : 1,  // �ٻ�����
                        "xuruo_status"  : 2,  // ս������(����)1��

                   ]));

                set("enchase/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������
 
                          "str" : 6,           // ��������

                        ////////////////////     ������������

                        "reduce_poison" : 50, // ����Ч����50%
                        "avoid_poison"  : 50, // ���Իرܣ�50%
                        "reduce_damage" : 30, // �����˺���30%
                        "reduce_busy"   : 30, // ����æ�ң�30%
                        "reduce_poison" : 50, // ����Ч����50%
                        "parry"  : 60,       // �мܵȼ���+60

                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}

