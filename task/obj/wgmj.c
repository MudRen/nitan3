#include <ansi.h>
inherit TASK;
void create()
{
    set_name(HIG"�书����"NOR, ({ "wugong miji" }) );
    set_weight(10);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "һ���ܺ���飬�������д���书�����ĸ����֡�\n");
          }
    set("owner", "���е�");
    setup();
}
