#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name(RED "��֮��ʯ" NOR, ({ "RED jewel7","jewel7" }));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", RED "һ����˸�������â�ĺ�ɫ��ʯ��"
                    "���˸е�һ������ļ¡�\n" NOR);
                set("unit", "��");
                set("value", 200000);
                set("no_identify", 1);
                set("wear_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "����ͷ�ϡ�\n" NOR);
                set("remove_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "��ͷ��ժ��������\n" NOR);
                
                set("enchase/SN", 7);    
                set("can_be_enchased", 1);    // ֻ����ߵȼ��ı�ʯ���д˱�־
		set("magic/type", "magic"); 
		set("magic/power", 15 + random(16)); 
                set("magic/cur_firm", 90);  // ��ĥ���
                set("magic/wspe_data",      // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������


                        "str" : 10,           // ��������
                        "dex" : 10,           // ���Ӹ���

                        ////////////////////     ������������

                        "attack" : 100,        // �����ȼ���+100
                        "damage" : 100,        // �����˺���+100
                        "fire_attack"   : 100, // ���湥��
                        "perferm_ap"    : 12,   // �������У�+12%
                        "add_damage"    : 10, // ׷���˺�10%

                   ]));

                set("magic/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������

                        "str" : 10,            // ��������
                        "dex" : 10,            // ���Ӹ���
                        ////////////////////     ������������

                        "reduce_fire"   : 90, // ������棺90%
                        "reduce_damage" : 90, // �����˺���90%
                        "max_neili"     : 20, // �������ޣ�+20%
                        "perform_dp"    : 10,  // ���з�����+10%

                        "qi_recover_speed"     : 50, // ��Ѫ�ָ��ٶȣ�+50%
                        "neili_recover_speed"   : 5, // �����ָ��ٶȣ�+5%
                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}


