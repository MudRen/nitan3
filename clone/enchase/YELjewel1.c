#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name(YEL "��ʯ��Ƭ" NOR, ({ "YEL jewel1","jewel1" }));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", YEL "һƬ��ɫ�ı�ʯ��Ƭ��\n" NOR);
                set("unit", "Ƭ");
                set("value", 80000);
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


                        "con" : 1,           // ������

                        ////////////////////     ������������

                        "busy_time"     : 1,  // æ�ҵ���3��
                        "unarmed_damage": 10, // �ַ��˺���+10
                        "no_exert"      : 1,  // ��Ϣ����3��

                   ]));

                set("enchase/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������

                        "con" : 1,           // ������

                        ////////////////////     ������������

                        "avoid_poison"  : 10, // ���Իرܣ�10%
                        "dodge"  : 10,       // �Ṧ�ȼ���+10
                        "reduce_busy"   : 5, // ����æ�ң�5%

                        "jingli_recover_speed" : 2, // �����ָ��ٶȣ�+2%
                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}


