#include <ansi.h>
inherit TASK;
void create()
{
    set_name(HIY"�����"NOR, ({ "huang majia", "majia" }) );
    set_weight(10);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "��");
            set("material", "cloth");
            set("long", "����һ���������͸����ݵĻ���ס�\n");
          }
    set("owner", "����");
    setup();
}
