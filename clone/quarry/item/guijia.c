#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(NOR + YEL "���" NOR, ({ "gui jia", "gui", "jia" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + YEL "�ڹ�ļ׿ǣ������������ϡ�\n" NOR);
                set("base_unit", "��");
		set("unit", "��");
                set("base_value", 10000);
                set("base_weight", 1000);
        }
        setup();
}

int query_autoload()
{
	return 1;
}
