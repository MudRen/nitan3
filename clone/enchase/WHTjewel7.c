#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name(WHT "��֮��ʯ" NOR, ({ "WHT jewel7","jewel7" }));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", WHT "һ����˸�������â�İ�ɫ��ʯ��"
                    "���˸е�һ������ļ¡�\n" NOR);
                set("unit", "��");
                set("value", 200000);
                set("no_identify", 1);
                set("can_be_enchased", 1);    // ֻ����ߵȼ��ı�ʯ���д˱�־
		set("magic/type", "magic"); 
		set("magic/power", 15 + random(16)); 
		
                set("wear_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "����ͷ�ϡ�\n" NOR);
                set("remove_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "��ͷ��ժ��������\n" NOR);
                
                set("enchase/SN", 8);    
                set("magic/cur_firm", 90);  // ��ĥ���
                set("magic/wspe_data",      // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������


                        "int" : 10,           // �����ǻ�
                        "dex" : 10,           // ���Ӹ���

                        ////////////////////     ������������

                        "cold_attack"   : 95, // �䶳����
                        "suck_neili"    : 30, // ��ȡ����
                        "suck_jingli"   : 30, // ��ȡ����

                   ]));

                set("magic/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������

                        "int" : 10,           // �����ǻ�
                        "dex" : 10,            // ���Ӹ���
                        ////////////////////     ������������

                        "reduce_cold"   : 95, // �����䶳��95%
                        "defense": 95,       // �����ȼ���+95
                        "max_jingli"    : 30, // �������ޣ�+30%

                        "jing_recover_speed"   : 50, // �����ָ��ٶ�: +50%
                        "jingli_recover_speed" : 5, // �����ָ��ٶȣ�+5%
                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}

