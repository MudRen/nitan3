#include <ansi.h>
inherit TASK;
void create()
{
    set_name(BLU"������"NOR, ({ "yu zhuo", "zhuo" }) );
    set_weight(1);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "֧");
            set("material", "steel");
            set("long", "����һ֧�������ഫ�Ǵ�������͸�������������\n");
          }
    set("owner", "��ܽ");
    setup();
}
