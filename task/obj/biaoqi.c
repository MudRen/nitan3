#include <ansi.h>
inherit TASK;
void create()
{
    set_name(HIR"����"NOR, ({ "biaoqi" }) );
    set_weight(1);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "һ���ּ��ھֵ�����\n");
          }
    set("owner", "������");
    setup();
}
