#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name(CYN "ħ֮��ʯ" NOR, ({ "CYN jewel6","jewel6" }));
        set_weight(40);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", CYN "һ����˸�������â����ɫ��ʯ��"
                    "���˸е�һ������ļ¡�\n" NOR);
                set("unit", "��");
                set("value", 180000);
                set("no_identify", 1);
                set("wear_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "����ͷ�ϡ�\n" NOR);
                set("remove_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "��ͷ��ժ��������\n" NOR);
                    
                set("enchase/SN", 3);
                set("enchase/type", "all");   // ����Ƕ�ĵ�������"all"��"sword"��"blade"��"cloth"��
                set("enchase/cur_firm", 90);  // ��ĥ���
                set("enchase/wspe_data",      // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������


                        "kar" : 8,           // ���Ӹ�Դ

                        ////////////////////     ������������

                       "attack" : 80,       // �����ȼ���+80
                        "xuruo_status"  : 3,  // ս������(����)3��
                        "suck_jingli"   : 24, // ��ȡ����24

                   ]));

                set("enchase/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������

                        "kar" : 8,           // ���Ӹ�Դ

                        ////////////////////     ������������

                        "avoid_poison"  : 75, // ���Իرܣ�75%
                        "dodge"  : 80,       // �Ṧ�ȼ���+80
                        "reduce_busy"   : 40, // ����æ�ң�40%

                        "neili_recover_speed"  : 15, // �����ָ��ٶȣ�+15%
                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}

