#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name(CYN "��ʯ" NOR, ({ "CYN jewel2","jewel2" }));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", CYN "һ����������ľ�����ʯ�������쳣��\n" NOR);
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


                        "kar" : 2,           // ���Ӹ�Դ

                        ////////////////////     ������������

                       "attack" : 20,       // �����ȼ���+20
                        "xuruo_status"  : 1,  // ս������(����)1��
                        "suck_jingli"   : 5, // ��ȡ����5

                   ]));

                set("enchase/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������

                        "kar" : 2,           // ���Ӹ�Դ

                        ////////////////////     ������������

                        "avoid_poison"  : 20, // ���Իرܣ�20%
                        "dodge"  : 20,       // �Ṧ�ȼ���+20
                        "reduce_busy"   : 10, // ����æ�ң�10%

                        "neili_recover_speed"  : 4, // �����ָ��ٶȣ�+4%
                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}

