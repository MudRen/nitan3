#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name(YEL "��ʯ" NOR, ({ "YEL jewel2","jewel2" }));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", YEL "һ�Żƹ������ľ�����ʯ�������쳣��\n" NOR);
                set("unit", "��");
                set("value", 100000);
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


                        "con" : 2,           // ������

                        ////////////////////     ������������

                        "busy_time"     : 1,  // æ�ҵ���1��
                        "unarmed_damage": 20, // �ַ��˺���+20
                        "no_exert"      : 1,  // ��Ϣ����1��

                   ]));

                set("enchase/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������

                        "con" : 2,           // ������

                        ////////////////////     ������������

                        "avoid_poison"  : 20, // ���Իرܣ�20%
                        "dodge"  : 20,       // �Ṧ�ȼ���+20
                        "reduce_busy"   : 10, // ����æ�ң�10%

                        "jingli_recover_speed" : 4, // �����ָ��ٶȣ�+4%
                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}


