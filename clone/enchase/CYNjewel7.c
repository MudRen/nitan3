#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name(CYN "��֮��ʯ" NOR, ({ "CYN jewel7","jewel7" }));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", CYN "һ����˸�������â����ɫ��ʯ��"
                    "���˸е�һ������ļ¡�\n" NOR);
                set("unit", "��");
                set("value", 200000);
                set("no_identify", 1);
                set("wear_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "����ͷ�ϡ�\n" NOR);
                set("remove_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "��ͷ��ժ��������\n" NOR);
                
                set("enchase/SN", 4);    
                set("can_be_enchased", 1);    // ֻ����ߵȼ��ı�ʯ���д˱�־
		set("magic/type", "magic"); 
		set("magic/power", 15 + random(16)); 
                set("magic/cur_firm", 90);  // ��ĥ���
                set("magic/wspe_data",      // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������


                        "kar" : 10,           // ���Ӹ�Դ

                        ////////////////////     ������������

                       "attack" : 100,       // �����ȼ���+100
                        "xuruo_status"  : 4,  // ս������(����)4��
                        "suck_jingli"   : 30, // ��ȡ����30

                   ]));

                set("magic/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������

                        "kar" : 10,           // ���Ӹ�Դ

                        ////////////////////     ������������

                        "avoid_poison"  : 90, // ���Իرܣ�90%
                        "dodge"  : 100,       // �Ṧ�ȼ���+100
                        "reduce_busy"   : 50, // ����æ�ң�50%

                        "neili_recover_speed"  : 20, // �����ָ��ٶȣ�+20%
                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}

