#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIR "�챦ʯ��" NOR, ({ "hong baoshikuang", "hong" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("base_unit", "��");
                set("unit", "��");
                set("base_value", 10000);
                set("base_weight", 600);
        }
        setup();
}
int query_autoload()
{
	return 1;
}