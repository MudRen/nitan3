#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name("��֮��ʯ", ({ "BLK jewel4","jewel4" }));
        set_weight(30);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ����˸�������â�ĺ�ɫ��ʯ��"
                    "���˸е�һ������ļ¡�\n");
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


                          "str" : 4,           // ��������

                        ////////////////////     ������������

                        "poison_attack" : 40, // ���湥��
                        "draw_dragon"   : 1,  // �ٻ�����
                        "xuruo_status"  : 2,  // ս������(����)1��

                   ]));

                set("enchase/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������
 
                          "str" : 4,           // ��������

                        ////////////////////     ������������

                        "reduce_poison" : 40, // ����Ч����40%
                        "avoid_poison"  : 40, // ���Իرܣ�40%
                        "reduce_damage" : 20, // �����˺���20%
                        "reduce_busy"   : 20, // ����æ�ң�20%
                        "reduce_poison" : 40, // ����Ч����40%
                        "parry"  : 40,       // �мܵȼ���+40

                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}

