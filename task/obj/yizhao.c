#include <ansi.h>
inherit TASK;
void create()
{
    set_name( WHT "����ү��گ" NOR, ({ "yi zhao" }) );
    set_weight(1);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "����ү����ǰд�µ���گ��\n");
          }
    set("owner", "֣��ˬ");
    setup();
}
