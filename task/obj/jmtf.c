#include <ansi.h>
inherit TASK;
void create()
{
    set_name(HIC"�����ȷ�"NOR, ({ "jueming tuifa" }) );
    set_weight(10);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "һ�������ȷ����޹����š�\n");
          }
    set("owner", "����");
    setup();
}
