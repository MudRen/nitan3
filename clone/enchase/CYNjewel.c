#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name(CYN "��ʯ" NOR, ({ "CYN jewel","jewel" }));
        set_weight(30);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", CYN "һ����˸�������â����ɫ��ʯ��\n" NOR);
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


                        "kar" : 5,           // ���Ӹ�Դ

                        ////////////////////     ������������

                       "attack" : 50,       // �����ȼ���+50
                        "xuruo_status"  : 2,  // ս������(����)2��
                        "suck_jingli"   : 12, // ��ȡ����12

                   ]));

                set("enchase/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������

                        "kar" : 5,           // ���Ӹ�Դ

                        ////////////////////     ������������

                        "avoid_poison"  : 50, // ���Իرܣ�50%
                        "dodge"  : 50,       // �Ṧ�ȼ���+50
                        "reduce_busy"   : 25, // ����æ�ң�25%

                        "neili_recover_speed"  : 10, // �����ָ��ٶȣ�+10%
                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}

