#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name(HIG "��֮��ʯ" NOR, ({ "GRN jewel7","jewel7" }));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIG "һ����˸�������â����ɫ��ʯ��"
                    "���˸е�һ������ļ¡�\n" NOR);
                set("unit", "��");
                set("value", 200000);
                set("no_identify", 1);
                set("wear_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "����ͷ�ϡ�\n" NOR);
                set("remove_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "��ͷ��ժ��������\n" NOR);
                
                set("enchase/SN", 5);    
                set("can_be_enchased", 1);    // ֻ����ߵȼ��ı�ʯ���д˱�־
		set("magic/type", "magic"); 
		set("magic/power", 15 + random(16)); 
                set("magic/cur_firm", 90);  // ��ĥ���
                set("magic/wspe_data",      // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������


                        "int" : 10,           // �����ǻ�

                        ////////////////////     ������������

                        "suck_jingli"   : 30, // ��ȡ����
                        "suck_eff_jing" : 30, // �˵о�������
                        "damage" : 100,       // �����˺���+100

                   ]));

                set("magic/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������

                        "int" : 10,           // �����ǻ�

                        ////////////////////     ������������

                        "armor"  : 100,       // ����������+100
                        "eff_jing"      : 10, // �������ޣ�+10%
                        "max_jingli"    : 30, // �������ޣ�+30%

                        "jing_recover_speed"   : 50, // �����ָ��ٶ�: +50%
                        "jingli_recover_speed" : 20, // �����ָ��ٶȣ�+20%
                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}

