#include <ansi.h>
inherit TASK;
void create()
{
    set_name(WHT"����"NOR, ({ "tie jian", "sword" }) );
    set_weight(100);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "��");
            set("material", "iron");
            set("long", "����һ���ǳ�������������\n");
          }
    set("owner", "��������");
    setup();
}
