#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name(YEL "��ʯ" NOR, ({ "YEL jewel","jewel" }));
        set_weight(30);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", YEL "һ����˸�������â�Ļ�ɫ��ʯ��\n" NOR);
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


                        "con" : 4,           // ������

                        ////////////////////     ������������

                        "busy_time"     : 2,  // æ�ҵ���2��
                        "unarmed_damage": 40, // �ַ��˺���+40
                        "no_exert"      : 2,  // ��Ϣ����2��

                   ]));

                set("enchase/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������

                        "con" : 4,           // ������

                        ////////////////////     ������������

                        "avoid_poison"  : 40, // ���Իرܣ�40%
                        "dodge"  : 40,       // �Ṧ�ȼ���+40
                        "reduce_busy"   : 30, // ����æ�ң�30%

                        "jingli_recover_speed" : 10, // �����ָ��ٶȣ�+10%
                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}


