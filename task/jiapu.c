#include <ansi.h>
inherit TASK;
void create()
{
    set_name(CYN"�ƼҼ���"NOR, ({ "jiapu" }) );
    set_weight(1);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "һ���ƼҼ���\n");
          }
    set("owner", "���");
    setup();
}
