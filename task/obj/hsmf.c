#include <ansi.h>
inherit TASK;
void create()
{
    set_name(HIY"���㻨���ط�"NOR, ({ "hsmfang" }) );
    set_weight(1);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "���㻨���ط���\n");
          }
    set("owner", "����ɩ");
    setup();
}
