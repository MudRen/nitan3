#include <ansi.h>
inherit TASK;
void create()
{
    set_name(MAG"�洫�ط�"NOR, ({ "zuchuan mifang" }) );
    set_weight(10);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "һ�ŷǳ��¾ɵĻ�ֽƬ��\n");
          }
    set("owner", "Ҧ��");
    setup();
}
