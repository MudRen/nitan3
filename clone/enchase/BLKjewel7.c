#include <ansi.h>
inherit ITEM;
// by dream

int is_enchase_ob() { return 1; } 

void create()
{
        set_name("��֮��ʯ", ({ "BLK jewel7","jewel7" }));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ����˸�������â�ĺ�ɫ��ʯ��"
                    "���˸е�һ������ļ¡�\n");
                set("unit", "��");
                set("value", 200000);
		set("no_identify", 1); 

                set("wear_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "����ͷ�ϡ�\n" NOR);
                set("remove_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "��ͷ��ժ��������\n" NOR);
		
		set("enchase/SN", 2);
                set("can_be_enchased", 1);    // ֻ����ߵȼ��ı�ʯ���д˱�־
		set("magic/type", "magic"); 
		set("magic/power", 15 + random(16));                     
                set("magic/cur_firm", 90);  // ��ĥ���
                
                set("magic/wspe_data",      // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������


                          "str" : 10,           // ��������

                        ////////////////////     ������������

                        "poison_attack" : 90, // ���湥��
                        "draw_dragon"   : 1,  // �ٻ�����
                        "xuruo_status"  : 3,  // ս������(����)1��

                   ]));

                set("magic/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������
 
                          "str" : 10,           // ��������

                        ////////////////////     ������������

                        "reduce_poison" : 90, // ����Ч����90%
                        "avoid_poison"  : 90, // ���Իرܣ�90%
                        "reduce_damage" : 50, // �����˺���50%
                        "reduce_busy"   : 50, // ����æ�ң�50%
                        "reduce_poison" : 90, // ����Ч����90%
                        "parry"  : 100,       // �мܵȼ���+100

                   ]));
                   
        }
        setup();
}

int query_autoload()
{
        return 1;
}


