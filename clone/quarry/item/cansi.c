#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(NOR + WHT "��˿" NOR, ({ "can si", "can", "si" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + WHT "����һ����ͨ�Ĳ�˿��\n" NOR);
                set("base_unit", "��");
                set("unit", "��");
                set("base_value", 1000);
                set("base_weight", 1);
        }
        setup();
}
int query_autoload()
{	
	return 1;
}
