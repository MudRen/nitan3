#include <ansi.h>
inherit ITEM;
int is_enchase_ob() { return 1; }
void create()
{
        set_name(MAG "��֮��ʯ" NOR, ({ "MAG jewel7","jewel7" }));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", MAG "һ����˸�������â����ɫ��ʯ��"
                    "���˸е�һ������ļ¡�\n" NOR);
                set("unit", "��");
                set("value", 200000);
                set("no_identify", 1);		
		set("can_be_enchased", 1);
		
                set("wear_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "����ͷ�ϡ�\n" NOR);
                set("remove_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "��ͷ��ժ��������\n" NOR);
                
                set("enchase/SN", 6);
                set("magic/type", "magic"); 
                set("magic/power", 15 + random(16));    
                set("magic/cur_firm", 90);  // ��ĥ���
                set("magic/wspe_data",      // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������


                        "con" : 10,           // ������

                        ////////////////////     ������������

                        "perferm_ap"    : 10,  // �������У�+10%
                        "suck_eff_jing" : 30, // �˵о�������
                        "suck_jingli"   : 30, // ��ȡ����
                        "suck_neili"    : 30, // ��ȡ����

                   ]));

                set("magic/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������

                        "con" : 10,           // ������

                        ////////////////////     ������������

                        "defense": 100,       // �����ȼ���+100
                        "armor"  : 100,       // ����������+100
                        "perform_dp"    : 10,  // ���з�����+10%
                        "reduce_damage" : 50, // �����˺���50%
                        "reduce_busy"   : 50, // ����æ�ң�50%

                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}



