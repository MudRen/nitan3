#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIW "���˿" NOR, ({ "tiancan si", "tiancan", "si" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + WHT "����һ�����˿����Ө��͸�����ǳ���\n" NOR);
                set("base_unit", "��");
                set("unit", "��");
                set("base_value", 100000);
                set("base_weight", 1);
        }
        setup();
}
int query_autoload()
{	
	return 1;
}
