#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name(CYN "ϡ����ʯ" NOR, ({ "CYN jewel3","jewel3" }));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", CYN "һ����������ľ�����ʯ�������Բ�ͬѰ���ĸо���\n" NOR);
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


                        "kar" : 3,           // ���Ӹ�Դ

                        ////////////////////     ������������

                       "attack" : 30,       // �����ȼ���+20
                        "xuruo_status"  : 1,  // ս������(����)1��
                        "suck_jingli"   : 8, // ��ȡ����8

                   ]));

                set("enchase/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������

                        "kar" : 3,           // ���Ӹ�Դ

                        ////////////////////     ������������

                        "avoid_poison"  : 30, // ���Իرܣ�30%
                        "dodge"  : 30,       // �Ṧ�ȼ���+30
                        "reduce_busy"   : 15, // ����æ�ң�15%

                        "neili_recover_speed"  : 7, // �����ָ��ٶȣ�+7%
                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}

