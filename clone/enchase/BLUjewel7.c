#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name(BLU "��֮��ʯ" NOR, ({ "BLU jewel7","jewel7" }));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", BLU "һ����˸�������â����ɫ��ʯ��"
                    "���˸е�һ������ļ¡�\n" NOR);
                set("unit", "��");
                set("value", 200000);
                set("no_identify", 1);
                set("wear_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "����ͷ�ϡ�\n" NOR);
                set("remove_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "��ͷ��ժ��������\n" NOR);
                
                set("enchase/SN", 3);    
                set("can_be_enchased", 1);    // ֻ����ߵȼ��ı�ʯ���д˱�־
		set("magic/type", "magic"); 
		set("magic/power", 15 + random(16)); 
                set("magic/cur_firm", 90);  // ��ĥ���
                set("magic/wspe_data",      // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������


                            "kar" : 10,           // ���Ӹ�Դ

                        ////////////////////     ������������

                            "light_attack"  : 100, // ���繥��
                            "add_damage"    : 20, // ׷���˺�20%
                            "suck_eff_qi"   : 30, // �˵���Ѫ����

                   ]));

                set("magic/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������

                            "kar" : 10,           // ���Ӹ�Դ

                        ////////////////////     ������������

                            "reduce_light"  : 100, // �������磺100%
                            "avoid_poison"  : 100, // ���Իرܣ�100%
                            "reduce_damage" : 50, // �����˺���50%

                            "qi_recover_speed"     : 50, // ��Ѫ�ָ��ٶȣ�+50%
                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}

