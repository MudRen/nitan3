#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name(YEL "��֮��ʯ" NOR, ({ "YEL jewel7","jewel7" }));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", YEL "һ����˸�������â�Ļ�ɫ��ʯ��"
                    "���˸е�һ������ļ¡�\n" NOR);
                set("unit", "��");
                set("value", 200000);
                set("no_identify", 1);
                set("wear_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "����ͷ�ϡ�\n" NOR);
                set("remove_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "��ͷ��ժ��������\n" NOR);
                
                set("enchase/SN", 1);    
                set("can_be_enchased", 1);    // ֻ����ߵȼ��ı�ʯ���д˱�־
		set("magic/type", "magic"); 
		set("magic/power", 15 + random(16)); 
                set("magic/cur_firm", 90);  // ��ĥ���
                set("magic/wspe_data",      // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������


                        "con" : 10,           // ������

                        ////////////////////     ������������

                        "busy_time"     : 4,  // æ�ҵ���4��
                        "unarmed_damage": 90, // �ַ��˺���+90
                        "no_exert"      : 4,  // ��Ϣ����4��

                   ]));

                set("magic/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������

                        "con" : 10,           // ������

                        ////////////////////     ������������

                        "avoid_poison"  : 90, // ���Իرܣ�90%
                        "dodge"  : 100,       // �Ṧ�ȼ���+100
                        "reduce_busy"   : 50, // ����æ�ң�50%

                        "jingli_recover_speed" : 20, // �����ָ��ٶȣ�+20%
                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}


