#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name(YEL "ħ֮��ʯ" NOR, ({ "YEL jewel6","jewel6" }));
        set_weight(40);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", YEL "һ����˸�������â�Ļ�ɫ��ʯ��"
                    "���˸е�һ������ļ¡�\n" NOR);
                set("unit", "��");
                set("value", 180000);
                set("no_identify", 1);
                set("wear_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "����ͷ�ϡ�\n" NOR);
                set("remove_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "��ͷ��ժ��������\n" NOR);
                
                set("enchase/SN", 9);    
                set("enchase/type", "all");   // ����Ƕ�ĵ�������"all"��"sword"��"blade"��"cloth"��
                set("enchase/cur_firm", 90);  // ��ĥ���
                set("enchase/wspe_data",      // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������


                        "con" : 8,           // ������

                        ////////////////////     ������������

                        "busy_time"     : 3,  // æ�ҵ���3��
                        "unarmed_damage": 70, // �ַ��˺���+70
                        "no_exert"      : 3,  // ��Ϣ����3��

                   ]));

                set("enchase/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������

                        "con" : 8,           // ������

                        ////////////////////     ������������

                        "avoid_poison"  : 70, // ���Իرܣ�70%
                        "dodge"  : 80,       // �Ṧ�ȼ���+80
                        "reduce_busy"   : 40, // ����æ�ң�40%

                        "jingli_recover_speed" : 16, // �����ָ��ٶȣ�+16%
                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}


