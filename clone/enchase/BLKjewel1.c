#include <ansi.h>
inherit ITEM;
// by dream

int is_enchase_ob() { return 1; } 

void create()
{
        set_name("��ʯ��Ƭ", ({ "BLK jewel1","jewel1" }));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һƬ��ɫ�ı�ʯ��Ƭ��\n");
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

                        "poison_attack" : 10, // ���湥��
                        "draw_dragon"   : 1,  // �ٻ�����
                        "xuruo_status"  : 1,  // ս������(����)1��

                   ]));

                set("enchase/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������
 
                          "str" : 1,           // ��������

                        ////////////////////     ������������

                        "reduce_poison" : 10, // ����Ч����10%
                        "avoid_poison"  : 10, // ���Իرܣ�10%
                        "reduce_damage" : 5, // �����˺���5%
                        "reduce_busy"   : 5, // ����æ�ң�5%
                        "reduce_poison" : 10, // ����Ч����0%
                        "parry"  : 10,       // �мܵȼ���+10

                   ]));
                   
        }
        setup();
}

int query_autoload()
{
        return 1;
}

