#include <ansi.h>
inherit ITEM;
int is_enchase_ob() { return 1; }
void create()
{
        set_name(RED "��ʯ" NOR, ({ "RED jewel","jewel" }));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", RED "һ����˸�������â�ĺ�ɫ��ʯ��\n" NOR);
                set("unit", "��");
                set("value", 100000);
                set("no_identify", 1);

                set("wear_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "����ͷ�ϡ�\n" NOR);
                set("remove_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "��ͷ��ժ��������\n" NOR);               
        }
        setup();
}

int query_autoload()
{
        return 1;
}

