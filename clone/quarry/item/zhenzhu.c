#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIW "��Ȼ����" NOR, ({ "tianran zhenzhu", "tianran", "zhenzhu" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIC "һ����Ȼ�����飬����ޱȡ�\n" NOR);
                set("base_unit", "��");
                set("unit", "��");
                set("base_value", 200000);
                set("base_weight", 100);
        }
        setup();
}
int query_autoload()
{
	return 1;
}