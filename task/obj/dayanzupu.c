#include <ansi.h>
inherit TASK;
void create()
{
    set_name(YEL"��������"NOR, ({ "dayan zupu", "zu pu" }) );
    set_weight(10);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "һ�����Ͼɵ��飬����д�š��������ס���\n");
          }
    set("owner", "Ľ�ݸ�");
    setup();
}
