#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name(YEL "ʥ֮��ʯ" NOR, ({ "YEL jewel5","jewel5" }));
        set_weight(30);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", YEL "һ����˸�������â�Ļ�ɫ��ʯ��"
                    "���˸е�һ������ļ¡�\n" NOR);
                set("unit", "��");
                set("value", 160000);
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


                        "con" : 6,           // ������

                        ////////////////////     ������������

                        "busy_time"     : 3,  // æ�ҵ���3��
                        "unarmed_damage": 60, // �ַ��˺���+60
                        "no_exert"      : 3,  // ��Ϣ����3��

                   ]));

                set("enchase/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������

                        "con" : 6,           // ������

                        ////////////////////     ������������

                        "avoid_poison"  : 60, // ���Իرܣ�60%
                        "dodge"  : 60,       // �Ṧ�ȼ���+60
                        "reduce_busy"   : 35, // ����æ�ң�35%

                        "jingli_recover_speed" : 13, // �����ָ��ٶȣ�+13%
                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}


