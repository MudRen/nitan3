#include <ansi.h>
inherit TASK;
void create()
{
    set_name(HIM "��Ů��" NOR, ({ "sunvjing" }) );
    set_weight(1);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "һ����Ů����\n");
          }
    set("owner", "ŷ����");
    setup();
}
