#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name(YEL "ϡ����ʯ" NOR, ({ "YEL jewel3","jewel3" }));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", YEL "һ�Żƹ������ľ�����ʯ�������Բ�ͬѰ���ĸо���\n" NOR);
                set("unit", "��");
                set("value", 120000);
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


                        "con" : 3,           // ������

                        ////////////////////     ������������

                        "busy_time"     : 2,  // æ�ҵ���1��
                        "unarmed_damage": 30, // �ַ��˺���+20
                        "no_exert"      : 2,  // ��Ϣ����1��

                   ]));

                set("enchase/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������

                        "con" : 3,           // ������

                        ////////////////////     ������������

                        "avoid_poison"  : 30, // ���Իرܣ�30%
                        "dodge"  : 30,       // �Ṧ�ȼ���+30
                        "reduce_busy"   : 20, // ����æ�ң�20%

                        "jingli_recover_speed" : 7, // �����ָ��ٶȣ�+7%
                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}


