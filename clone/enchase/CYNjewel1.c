#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name(CYN "��ʯ��Ƭ" NOR, ({ "CYN jewel1","jewel1" }));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", CYN "һƬ��ɫ�ı�ʯ��Ƭ��\n" NOR);
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


                        "kar" : 1,           // ���Ӹ�Դ

                        ////////////////////     ������������

                       "attack" : 10,       // �����ȼ���+10
                        "xuruo_status"  : 1,  // ս������(����)1��
                        "suck_jingli"   : 3, // ��ȡ����3

                   ]));

                set("enchase/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������

                        "kar" : 1,           // ���Ӹ�Դ

                        ////////////////////     ������������

                        "avoid_poison"  : 10, // ���Իرܣ�10%
                        "dodge"  : 10,       // �Ṧ�ȼ���+10
                        "reduce_busy"   : 5, // ����æ�ң�5%

                        "neili_recover_speed"  : 2, // �����ָ��ٶȣ�+2%
                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}

