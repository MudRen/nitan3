#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name(CYN "ʥ֮��ʯ" NOR, ({ "CYN jewel5","jewel5" }));
        set_weight(30);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", CYN "һ����˸�������â����ɫ��ʯ��"
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


                        "kar" : 6,           // ���Ӹ�Դ

                        ////////////////////     ������������

                       "attack" : 60,       // �����ȼ���+60
                        "xuruo_status"  : 2,  // ս������(����)2��
                        "suck_jingli"   : 16, // ��ȡ����16

                   ]));

                set("enchase/aspe_data",       // �����ϸ������Ի���
                   ([
                        ////////////////////     ������������

                        "kar" : 6,           // ���Ӹ�Դ

                        ////////////////////     ������������

                        "avoid_poison"  : 60, // ���Իرܣ�60%
                        "dodge"  : 60,       // �Ṧ�ȼ���+60
                        "reduce_busy"   : 35, // ����æ�ң�35%

                        "neili_recover_speed"  : 13, // �����ָ��ٶȣ�+13%
                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}

