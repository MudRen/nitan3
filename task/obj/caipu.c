#include <ansi.h>
inherit TASK;
void create()
{
    set_name(HIC"����¥����" NOR, ({ "cai pu" }) );
    set_weight(1);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "��");
            set("material", "stone");
            set("long", "һ������¥����\n");
          }
    set("owner", "���ϰ�");
    setup();
}
